//CristianRamosMedina
#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <fstream>

using namespace std;

double distancia(const vector<double>& punto1, const vector<double>& punto2) {
    double res = 0;
    for (size_t i = 0; i < punto1.size(); ++i) {
        double a = punto1[i] - punto2[i];
        res += pow(a, 2);
    }
    return sqrt(res);
}

void calcularDistancias(const vector<vector<double>>& puntos, const string& txt) {
    int numPuntos = puntos.size();
    //int total_op = 0;
    ofstream archivo(txt);
    for (int i = 0; i < numPuntos - 1; ++i) {
        for (int j = i + 1; j < numPuntos; ++j) {
            double dist = distancia(puntos[i], puntos[j]);
            archivo << dist << endl;
            //total_op++;
        }
        
    }

    archivo.close();
    cout << "Escrito en " << txt << endl;
    //cout << total_op;
}

// funcion generar adapatada de cpp reference uniform real distribution
vector<vector<double>> generar(int num, int n) {
    vector<vector<double>> res;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0, 1.0);
    for (int i = 0; i < num; ++i) {
        vector<double> subvect;
        for (int j = 0; j < n; ++j) {
            subvect.push_back(dis(gen));
        }
        res.push_back(subvect);
    }
    return res;
}

int main() {
  //unicamente cambiando de 5000 a las demas dimensiones y el nombre del archivo generado txt.
    vector<vector<double>> puntos = generar(100, 5000);
    calcularDistancias(puntos, "resultados 5000.txt");


    return 0;
}
