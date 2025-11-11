#include "red.h"

Red::Red() {}



void Red::agregarEnrutador(string n, map<string, int> v) {
    nombre = n;
    vecinos = v;

    // Se llena tabla con vecinos
    for (auto &par : vecinos) {
        string vecino = par.first;
        int costo = par.second;

        InfoRuta ruta;
        ruta.costo = costo;
        ruta.siguienteSalto = vecino;
        ruta.rutaCompleta = {nombre, vecino};

        tablaEnrutamiento[vecino] = ruta;
    }

    cout << "Tabla de enrutamiento del enrutador " << nombre << " creada correctamente.\n";


}



void Red::elminarEnrutador() {
    vecinos.clear();
    tablaEnrutamiento.clear();
    cout << "Se eliminaron los datos del enrutador " << nombre << ".\n";
}
