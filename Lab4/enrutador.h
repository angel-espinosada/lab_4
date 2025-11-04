#ifndef ENRUTADOR_H
#define ENRUTADOR_H
#include <string>
#include<map>
#include<vector>

using namespace std;


struct InfoRuta {
    int costo;
    string siguienteSalto;
    vector<string> rutaCompleta;
};

class Enrutador


{
private:
    string nombre;
    map<string, int> vecinos;//Vecinos con su costo.
    map<string, InfoRuta> tablaEnrutamiento;

public:
    Enrutador();
    Enrutador(string n,map<string, int>v,map<string, InfoRuta> tabla);

    void mostrarEnrutador();
    void agregarEnrutador();
    void elminarEnrutador();


};

#endif // ENRUTADOR_H
