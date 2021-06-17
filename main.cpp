#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <ctime>

#include "include/nanoflann.hpp"
#include "include/dbscan.h"

using namespace std;

void readDataset(vector<Point> &points, const char* filename, int size, int dimension) {

    ifstream file(filename);

    if(file.is_open()) {
        string line;
        points.resize(size);
        
        int j = 0;
        while(getline(file, line)) {
            stringstream ss(line.c_str());
            points[j].point.resize(dimension);
            points[j].cluster_id = UNCLASSIFIED;
            points[j].index = j;
            
            int i = 0;
            while(ss.good()) {
                string substring;
                getline(ss, substring, ',');
                points[j].point[i] = stof(substring);
                i++;
            }

            j++;
        }

    }
    
    file.close();

}

int main(int argc, char** argv) {
    
    clock_t start_time = clock();

    const char* filename = argv[1];
    int size = atoi(argv[2]);
    int dimension = atoi(argv[3]);
    int min_points = atoi(argv[4]);
    float epsilon = atof(argv[5]);

    vector<Point> points;
    readDataset(points, filename, size, dimension);

    DBSCAN dbscan(min_points, epsilon, points, dimension);
    dbscan.run();

    vector<Point>::iterator db_iter;
    for(db_iter = dbscan.getPoints().begin(); db_iter != dbscan.getPoints().end(); db_iter++) {
        cout << db_iter->cluster_id << "  ";
    }
    cout << endl;

    clock_t end_time = clock();
    cout << endl << "File Read in " 
            << (float)(end_time - start_time) / CLOCKS_PER_SEC
            << " seconds." << endl; 
    cout << endl;

    return 0;
}