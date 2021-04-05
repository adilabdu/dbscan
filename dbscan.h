#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>

#define UNCLASSIFIED -1
#define CORE_POINT 1
#define BORDER_POINT 2
#define NOISE -2
#define SUCCESS 0
#define FAILURE -3

using namespace std;

typedef struct Point_ {

    double *point;
    int cluster_id;
    int cluster_label;

} Point;

class DBSCAN {
    public:
    DBSCAN(unsigned int min_points, float epsilon, vector<Point> points) {
        min_points = min_points;
        epsilon = epsilon;
        points = points;
        size = points.size();
    }

    ~DBSCAN(){}

    int run();

    private:
    int min_points;
    int size;

};

#endif
