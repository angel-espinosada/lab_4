#include <iostream>
#include <map>
#include <string>
#include "Enrutador.h"


using namespace std;

int main()
{
    map<string, Enrutador> red;
  int opcion= -1;

    while (opcion!=0) {
        cout<<"*************************************"<<endl;
        cout<<"*******Menu Red de enrutadores*******"<<endl;
        cout<<"1. Crear Router"<<endl;
        cout<<"2.Mostrar red"<<endl;
        cout<<"3.Ruta mas corta, costo"<<endl;
        cout<<"0. Salir"<<endl;
        cin>>opcion;
        switch(opcion){

        case 1:
        {


            break;
        }
        case 2:{


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



    return 0;
}
