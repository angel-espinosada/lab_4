#include <iostream>
#include "Enrutador.h"


using namespace std;

int main()
{
  int opcion= -1;

    while (opcion!=0) {
        cout<<"*************************************"<<endl;
        cout<<"*******Menu Red de enrutadores*******"<<endl;
        cout<<"1. Crear Router"<<endl;
        cout<<"2.Eliminar router"<<endl;
        cout<<"3.Ruta mas corta, costo"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;
        switch(opcion){

        case 1:
        {
            cout<<"Cree su router"<<endl;
            break;
        }
        case 2:{

            break;
        }

        case 3:{

            break;

        }


        default:{


                cout<<"opcion no valida"<<endl;
            break;
        }
        }
    }

    Enrutador A;
   A.agregarEnrutador();
    A.mostrarEnrutador();

    return 0;
}
