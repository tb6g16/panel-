#include <iostream>
#include <fstream>
#include <vector>

#include "aerofoil.hpp"

using namespace std;

// TODO: change file read to include first line
// TODO: convert points to spline
// TODO: panel method (copy xfoil)

int main(int argc, char **argv){
    Aerofoil aerofoil("naca2412.dat");

    for (vector<double> coordinate : aerofoil.coords){
        cout << coordinate[0] << "    " << coordinate[1] << "\n";
    }

    return 0;
}
