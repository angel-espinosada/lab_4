#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <string>
class Enrutador
{
private:
    string nombre;
    map<string, int> vecinos;//Vecinos con su costo.
    map<string, infoRuta> tablaEnrutamiento;

public:
    Enrutador();

    void mostrarEnrutador();
    void agregarEnrutador();
    void elminarEnrutador();

};

#endif // ENRUTADOR_H
