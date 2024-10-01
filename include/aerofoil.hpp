#ifndef AEROFOIL_H
#define AEROFOIL_H

#include <vector>

using namespace std;

class Aerofoil{
    public:
        vector<vector<double>> coords;
        Aerofoil(vector<vector<double>>);
        Aerofoil(string);
        void show();
};

std::vector<std::vector<double>> getAerofoilData(std::string filename);

#endif