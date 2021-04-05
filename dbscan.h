#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>
#include <cmath>

#define UNCLASSIFIED -1
#define NOISE -2

using namespace std;

typedef struct Point_ {

    float *point;
    int cluster_id;
    int cluster_label;

} Point;

class DBSCAN {
private:
    unsigned int min_points;
    float epsilon;
    unsigned int size;
    unsigned int dimension;
    vector<Point> points;

public: 
    DBSCAN(unsigned int min_points, float epsilon, vector<Point> points, int dimension) {
        min_points = min_points;
        epsilon = epsilon;
        points = points;
        size = points.size();
        dimension = dimension;
    }

    int run();
    bool expandCluster(Point point, int cluster_id);
    vector<int> regionQuery(Point point);
    inline float distanceMeasure(Point poi, Point target);

};

#endif
