#include <iostream>
#include <fstream>
#include <vector>

#include "aerofoil.hpp"

using namespace std;

Aerofoil::Aerofoil(vector<vector<double>> aerofoil_coords){
    coords = aerofoil_coords;
}

Aerofoil::Aerofoil(string filename){
    coords = getAerofoilData(filename);
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
