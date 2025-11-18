#include "red.h"
#include "Enrutador.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

Red::Red() {}

// Agregar un nuevo enrutador a la red

/*
void Red::agregarEnrutador(const string& nombre, const map<string, int>& vecinos) {
    // Verificar si el enrutador ya existe
    if (enrutadores.find(nombre) != enrutadores.end()) {
        cout << "Error: El enrutador '" << nombre << "' ya existe en la red." << endl;
        return;
    }

    // Crear y agregar el nuevo enrutador
    enrutadores[nombre] = Enrutador(nombre, vecinos);
    cout << "Enrutador '" << nombre << "' agregado correctamente a la red." << endl;


}
*/
void Red::agregarEnrutador(const string& nombre){
    enrutadores[nombre] = Enrutador(nombre);
}
// Eliminar un enrutador de la red
void Red::eliminarEnrutador(const string& nombre) {
    auto it = enrutadores.find(nombre);
    if (it == enrutadores.end()) {
        cout << "Error: El enrutador '" << nombre << "' no existe en la red." << endl;
        return;
    }

    enrutadores.erase(it);
    cout << "Enrutador '" << nombre << "' eliminado correctamente de la red." << endl;

    // TODO: Actualizar tablas de enrutamiento después de eliminar
}

// Verificar si un enrutador existe
bool Red::existeEnrutador(const string& nombre) const {
    return enrutadores.find(nombre) != enrutadores.end();
}

// Mostrar información básica de la red
void Red::mostrarRed() const {
    cout << " RED DE ENRUTADORES" << endl;
    if (enrutadores.empty()) {
        cout << "La red está vacía." << endl;
        return;
    }

    cout << "Enrutadores en la red: ";
    for (const auto& par : enrutadores) {
        cout << par.first << " ";
    }
    cout << endl;

    cout << "Total de enrutadores: " << enrutadores.size() << endl;
}


map<string, int> Red::calcularRutasDesde(const string& origen) {

    return map<string, int>();
}

vector<string> Red::obtenerRutaMasCorta(const string& origen, const string& destino) {

    return vector<string>();
}


int Red::obtenerCostoMinimo(const string& origen, const string& destino) {
    //Implementar después de Dijkstra
    return -1;
}
// Conecta dos enrutadores (origen y destino) con un costo
void Red::conectarEnrutadores(const string& origen, const string& destino, int costo) {
    enrutadores[origen].agregarVecino(destino, costo);
}
void Red::actualizarTablasEnrutamiento() {

}

void Red::guardarEnArchivo(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << " No se pudo abrir el archivo para guardar.\n";
        return;
    }

    for (const auto& par : enrutadores) {
        const string& origen = par.first;
        const auto& vecinos = par.second.obtenerVecinos();

        for (const auto& v : vecinos) {
            archivo << origen << " " << v.first << " " << v.second << "\n";
        }
    }

    archivo.close();
    cout << "Red guardada exitosamente en " << nombreArchivo << endl;
}
void Red::cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cerr << "No se pudo abrir el archivo para leer.\n";
        return;
    }

    string origen, destino;
    int costo;

    while (archivo >> origen >> destino >> costo) {
        agregarEnrutador(origen);
        agregarEnrutador(destino);
        conectarEnrutadores(origen, destino, costo);
        enrutadores[origen].agregarVecino(destino, costo);
        enrutadores[destino].agregarVecino(origen, costo);
    }

    archivo.close();
    cout << "Red cargada desde " << nombreArchivo << " exitosamente.\n";
}
