#ifndef DBSCAN_H
#define DBSCAN_H

#include <vector>

#define UNCLASSIFIED -1

using namespace std;

typedef struct Point_ {

    double *point;
    int cluster_id;
    int cluster_label;

} Point;

#endif
