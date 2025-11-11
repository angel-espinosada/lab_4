#include "red.h"
#include "Enrutador.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;

Red::Red() {}

// Agregar un nuevo enrutador a la red
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

// Mostrar tabla de enrutamiento de un enrutador específico
void Red::mostrarTablaEnrutamiento(const string& nombre) const {
    auto it = enrutadores.find(nombre);
    if (it == enrutadores.end()) {
        cout << "Error: El enrutador '" << nombre << "' no existe en la red." << endl;
        return;
    }

    it->second.mostrarEnrutador();
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

void Red::actualizarTablasEnrutamiento() {

}
