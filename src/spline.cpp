#include <iostream>
#include <vector>
#include <cmath>

#include "spline.hpp"

using namespace std;

// TODO: implement this properly for a set of data points (least squares solution I think)
BezierCurve::BezierCurve(vector<vector<double>> coords){
    cpts = coords;
    ncpts = coords.size();
}

double factorial(int n){
    // declare variables
    int i;
    double fact = 1;

    // loop up to the input computing factorial
    for (i = 2; i <= n; ++i){
        fact *= i;
    }

    return fact;
}

double binomialCoeff(int n, int k){
    return static_cast<double>(factorial(n))/factorial(k)*factorial(n - k);
}

vector<vector<double>> BezierCurve::getCoords(int npts){
    // decalare variables
    int i, j;
    double t, b;
    vector<vector<double>> coords(npts, vector<double>(2, 0));

    for (i = 0; i < npts; ++i){
        t = static_cast<double>(i)/(npts - 1);
        for (j = 0; j < ncpts; ++j){
            b = binomialCoeff(ncpts - 1, j)*pow(t, j)*pow(1 - t, ncpts - 1 - j);
            coords[i][0] += b*cpts[j][0];
            coords[i][1] += b*cpts[j][1];
        }
    }

    return coords;
}
