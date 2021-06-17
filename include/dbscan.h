#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>
#include <cmath>

#define UNCLASSIFIED -1
#define NOISE -2

using namespace std;

typedef struct Point_ {

    vector<float> point;
    int cluster_id;
    int cluster_label;
    int index;

} Point;

class DBSCAN {
private:
    unsigned int min_pts;
    float eps;
    unsigned int size;
    unsigned int dim;
    vector<Point> pts;

public: 
    DBSCAN(unsigned int min_points, float epsilon, vector<Point> points, int dimension) {
        min_pts = min_points;
        eps = epsilon;
        pts = points;
        size = points.size();
        dim = dimension;
    }

    int run();
    bool expandCluster(Point point, int cluster_id);
    vector<int> regionQuery(Point point);
    float distanceMeasure(Point poi, Point target);

    vector<Point> getPoints();
    int getDimension();

};

#endif
