#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <ctime>
#include "dbscan.h"

using namespace std;

void readDataset(vector<Point> &points, const char* filename, int size, int dimension) {

    ifstream file(filename);

    if(file.is_open()) {
        string line;
        Point *point = (Point *)calloc(size, sizeof(Point));
        
        int j = 0;
        while(getline(file, line)) {
            stringstream ss(line.c_str());
            point[j].point = new double[dimension];
            point[j].cluster_id = UNCLASSIFIED;
            
            int i = 0;
            while(ss.good()) {
                string substring;
                getline(ss, substring, ',');
                point[j].point[i] = stod(substring);
                i++;
            }

            points.push_back(point[j]);
            j++;
        }

        delete point;
    }
    
    file.close();

}

int main(int argc, char** argv) {
    
    clock_t start_time = clock();

    const char* filename = argv[1];
    int size = atoi(argv[2]);
    int dimension = atoi(argv[3]);

    cout << "C++ implementation of DBSCAN";
    cout << endl;

    vector<Point> points;
    readDataset(points, filename, size, dimension);

    clock_t end_time = clock();

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < dimension; j++) {
            cout << points[i].point[j] << ", ";
        }
        cout << endl;
    }

    cout << endl << "File Read in " 
            << (float)(end_time - start_time) / CLOCKS_PER_SEC
            << " seconds." << endl; 

    return 0;
}