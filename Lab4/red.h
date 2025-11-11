#ifndef RED_H
#define RED_H

#include "Enrutador.h"
#include <map>
#include <string>
#include <vector>

using namespace std;

class Red
{
private:
    map<string, Enrutador> enrutadores;  // Todos los enrutadores de la red

public:
    Red();

    // Métodos
    void agregarEnrutador(const string& nombre, const map<string, int>& vecinos);
    void eliminarEnrutador(const string& nombre);
    bool existeEnrutador(const string& nombre) const;

    // Dijkstra
    map<string, int> calcularRutasDesde(const string& origen);
    vector<string> obtenerRutaMasCorta(const string& origen, const string& destino);
    int obtenerCostoMinimo(const string& origen, const string& destino);

    // Actualización de tablas
    void actualizarTablasEnrutamiento();

    // Mostrar información
    void mostrarRed() const;
    void mostrarTablaEnrutamiento(const string& nombre) const;
};

#endif // RED_H
