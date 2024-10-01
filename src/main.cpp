#include <iostream>

#include "spline.hpp"
#include "aerofoil.hpp"

using namespace std;

// TODO: object for bezier compositive curve
// TODO: convert points to spline
// TODO: use rational bezier curves

int main(int argc, char **argv){
    Aerofoil aerofoil("naca2412.dat");
    BezierCurve curve({{0.0, 0.0}, {0.5, 1.0}, {1.0, 0.0}});

    vector<vector<double>> coords = curve.getCoords(50);
    for (vector<double> coord : coords){
        cout << coord[0] << "    " << coord[1] << "\n";
    }

    aerofoil.show();

    return 0;
}
