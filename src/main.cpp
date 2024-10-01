#include <iostream>

#include "spline.hpp"
#include "aerofoil.hpp"

using namespace std;

// TODOL plotting method for the aerofoils
// TODO: object for bezier compositive curve
// TODO: convert points to spline
// TODO: try gnuplot for faster plotting?
// TODO: use rational bezier curves

int main(int argc, char **argv){
    Aerofoil aerofoil("naca2412.dat");
    BezierCurve curve({{0.0, 0.0}, {0.5, 1.0}, {1.0, 0.0}});

    // for (vector<double> coordinate : aerofoil.coords){
    //     cout << coordinate[0] << "    " << coordinate[1] << "\n";
    // }

    vector<vector<double>> coords = curve.getCoords(50);
    for (vector<double> coord : coords){
        cout << coord[0] << "    " << coord[1] << "\n";
    }

    vector<double> x(aerofoil.coords.size()), y(aerofoil.coords.size());
    int i = 0;
    for (vector<double> coord : aerofoil.coords){
        x[i] = coord[0];
        y[i] = coord[1];
        i++;
    }

    return 0;
}
