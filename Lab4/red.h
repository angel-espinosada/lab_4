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
    //Cargo los enrutadores de la red
    map<string, Enrutador>enrutadores;

public:
    Red();
    void agregarEnrutador();
    void eliminarEnrutador();


    map<string, int>calcularRuta;
    vector<string> obtenerRutaMasCorta();
    int obtenerCostMinimo();

};

#endif // RED_H
