#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;

#include "funcionesGLOBALES.h"
#include "clsFecha.h"
#include "clsTiposDeporte.h"
#include "clsArchivoTiposDeporte.h"
#include "menuTiposDeporte.h"
#include "clsDeportes.h"
#include "clsArchivoDeportes.h"
#include "menuDeportes.h"
#include "clsEquipos.h"
#include "clsArchivoEquipos.h"
#include "menuEquipos.h"
#include "clsJugadores.h"
#include "clsArchivoJugadores.h"
#include "menuJugadores.h"
#include "reportes.h"
#include "clsConfiguracion.h"
#include "menuConfiguracion.h"



int main(){
    ///Menú
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU PRINCIPAL "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) MENU JUGADORES "<<endl;
        cout<<"2) MENU DEPORTES "<<endl;
        cout<<"3) MENU EQUIPOS "<<endl;
        cout<<"4) MENU TIPOS DE DEPORTE "<<endl;
        cout<<"5) REPORTES "<<endl;
        cout<<"6) CONFIGURACION "<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) FIN DEL PROGRAMA "<<endl;
        cout<<endl;
        cout<<"SELECCIONE UNA DE LAS OPCIONES: "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: MenuJugadores();
                    break;
            case 2: MenuDeportes();
                    break;
            case 3: MenuEquipos();
                    break;
            case 4: MenuTiposDeporte();
                    break;
            case 5: MenuReportes();
                    break;
            case 6: MenuConfiguracion();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"VALOR INCORRECTO"<<endl;
                    break;
            }
            system("pause");
        }
    ///Fin del menú

    system("pause");
    return 0;
}
