#include "enrutador.h"
#include<iostream>
#include<queue>

Enrutador::Enrutador() {}
Enrutador::Enrutador(string n, map<string, int> v, map<string, InfoRuta> tabla)
    : nombre(n), vecinos(v), tablaEnrutamiento(tabla) {}
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


void Enrutador::agregarEnrutador() {

    nombre = "A";
    vecinos = { {"B", 4}, {"C", 10} };


    InfoRuta rutaB;
    rutaB.costo = 4;
    rutaB.siguienteSalto = "B";
    rutaB.rutaCompleta = {"A", "B"};

    InfoRuta rutaC;
    rutaC.costo = 7;
    rutaC.siguienteSalto = "B";
    rutaC.rutaCompleta = {"A", "B", "C"};

    InfoRuta rutaD;
    rutaD.costo = 5;
    rutaD.siguienteSalto = "B";
    rutaD.rutaCompleta = {"A", "B", "D"};


    tablaEnrutamiento["B"] = rutaB;
    tablaEnrutamiento["C"] = rutaC;
    tablaEnrutamiento["D"] = rutaD;

    cout << "Tabla de enrutamiento del enrutador " << nombre << " creada correctamente.\n";
}



void Enrutador::elminarEnrutador() {
    vecinos.clear();
    tablaEnrutamiento.clear();
    cout << "Se eliminaron los datos del enrutador " << nombre << ".\n";
}
