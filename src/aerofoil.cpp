#include <iostream>
#include <fstream>
#include <vector>

#include "matplotlibcpp.h"

#include "aerofoil.hpp"

using namespace std;
namespace plt = matplotlibcpp;

Aerofoil::Aerofoil(vector<vector<double>> aerofoil_coords){
    coords = aerofoil_coords;
}

Aerofoil::Aerofoil(string filename){
    coords = getAerofoilData(filename);
}

// TODO: try gnuplot for faster plotting? Or matplot++?
void Aerofoil::show(){
    // declare variables
    int i;
    vector<double> x(coords.size()), y(coords.size());

    // loop over coordinates assigning to vectors
    for (i = 0; i < coords.size(); ++i){
        x[i] = coords[i][0];
        y[i] = coords[i][1];
    }

    // plot results
    plt::plot(x, y);
    plt::show();
}

vector<vector<double>> getAerofoilData(string filename){
    // initialiase variables
    int i;
    string line;
    vector<vector<double>> aerofoil_coords;

    // open file and read first line
    ifstream file(filename);

    // loop over lines assigning to output vector
    while (getline(file, line)){
        aerofoil_coords.push_back({stod(line.substr(0, line.find(" "))), stod(line.substr(line.find(" "), line.length()-1))});
        i++;
    }

    return aerofoil_coords;
}
