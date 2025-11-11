#include "enrutador.h"
#include<iostream>
#include<queue>
#include <map>
#include <vector>
#include <string>

Enrutador::Enrutador() {}
Enrutador::Enrutador(string n, map<string, int> v) : nombre(n), vecinos(v) {
    // Llenar tabla con vecinos directos
    for (auto &par : vecinos) {
        string vecino = par.first;
        int costo = par.second;

        InfoRuta ruta;
        ruta.costo = costo;
        ruta.siguienteSalto = vecino;
        ruta.rutaCompleta = {nombre, vecino};

        tablaEnrutamiento[vecino] = ruta;
    }
}
void Enrutador::mostrarEnrutador() {
    cout << "\nEnrutador: " << nombre << endl;
    cout << "Vecinos directos:\n";
    for (auto &v : vecinos)
        cout << "> " << v.first << " (costo " << v.second << ")\n";

    cout << "\nTabla de Enrutamiento:\n";
    for (auto &t : tablaEnrutamiento) {
        cout << "Destino: " << t.first
             << "  Costo: " << t.second.costo
             << " Siguiente salto: " << t.second.siguienteSalto
             << "  Ruta: ";

        for (auto &r : t.second.rutaCompleta)
            cout << r << " ";
        cout << endl;
    }
}


