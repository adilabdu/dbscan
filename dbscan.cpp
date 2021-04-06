#include "dbscan.h"

int DBSCAN::run() {

    int cluster_id = 1;
    
    vector<Point>::iterator db_iter;
    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(db_iter->cluster_id == UNCLASSIFIED) {

            if(expandCluster(*db_iter, cluster_id) == true) {
                cluster_id += 1;
            }
    
        }
    }
    
    return 0;
}

bool DBSCAN::expandCluster(Point point, int cluster_id) {
    
    vector<int> cluster_seeds = regionQuery(point);

    if(cluster_seeds.size() < min_pts) {
        point.cluster_id = NOISE;
        return false;
    } 
    else {
        int index = 0, index_core = 0;
        
        vector<int>::iterator seeds_iter;
        for(seeds_iter = cluster_seeds.begin(); seeds_iter != cluster_seeds.end(); seeds_iter++) {

            pts.at(*seeds_iter).cluster_id = cluster_id;

            if(pts.at(*seeds_iter).point == point.point) {
                index_core = index;
            }
            index++;
        }

        cluster_seeds.erase(cluster_seeds.begin() + index_core);

        vector<int>::size_type i, n;
        for(i = 0, n = cluster_seeds.size(); i < n; i++) {
            vector<int> cluster_neighbors = regionQuery(pts.at(cluster_seeds[i]));

            if(cluster_neighbors.size() >= min_pts) {
                
                vector<int>::iterator neighbors_iter;
                for(neighbors_iter = cluster_neighbors.begin(); neighbors_iter != cluster_neighbors.end(); neighbors_iter++) {
                    
                    if(pts.at(*neighbors_iter).cluster_id == UNCLASSIFIED ||
                        pts.at(*neighbors_iter).cluster_id == NOISE) {

                            if(pts.at(*neighbors_iter).cluster_id == UNCLASSIFIED) {
                                cluster_seeds.push_back(*neighbors_iter);
                                n = cluster_seeds.size();
                            }
                            pts.at(*neighbors_iter).cluster_id = cluster_id;
                    }
                }
            }
        }

        return true;
    }
}

vector<int> DBSCAN::regionQuery(Point point) {

    int index = 0;
    vector<int> cluster_index;

    vector<Point>::iterator db_iter;
    for(db_iter = pts.begin(); db_iter != pts.end(); db_iter++) {

        if(distanceMeasure(point, *db_iter) <= eps) {
            cluster_index.push_back(index);
        } 
    
        index++;
    }

    return cluster_index;
}

float DBSCAN::distanceMeasure(Point poi, Point target) {
    
    float square_sums = 0;

    for(int i = 0; i < dim; i++) {
        square_sums += pow(poi.point[i] - target.point[i], 2);
    }

    return sqrt(square_sums);
}

vector<Point> DBSCAN::getPoints() { 
    
    return pts;
}

int DBSCAN::getDimension() {
    return dim;
}