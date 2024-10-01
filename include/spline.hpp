#ifndef SPLINE_H
#define SPLINE_H

#include <vector>

using namespace std;

class BezierCurve{
    public:
        vector<vector<double>> cpts;
        int ncpts;
        BezierCurve(vector<vector<double>>);
        vector<vector<double>> getCoords(int);
};

#endif