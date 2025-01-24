#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

int MenuConfiguracion(){
    Configuracion obj;
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU CONFIGURACION "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE JUGADORES "<<endl;
        cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE DEPORTES "<<endl;
        cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE EQUIPOS "<<endl;
        cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE TIPOS DE DEPORTE "<<endl;
        cout<<"5) RESTAURAR EL ARCHIVO DE JUGADORES "<<endl;
        cout<<"6) RESTAURAR EL ARCHIVO DE DEPORTES "<<endl;
        cout<<"7) RESTAURAR EL ARCHIVO DE EQUIPOS "<<endl;
        cout<<"8) RESTAURAR EL ARCHIVO DE TIPOS DE DEPORTE "<<endl;
        cout<<"9) ESTABLECER DATOS DE INICIO "<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: if(obj.copiaJugadores()==true)cout<<endl;
                    else cout<<"No se ha podido generar la copia de seguridad."<<endl;
                    break;
            case 2: if(obj.copiaDeportes()==true)cout<<endl;
                    else cout<<"No se ha podido generar la copia de seguridad."<<endl;
                    break;
            case 3: if(obj.copiaEquipos()==true)cout<<endl;
                    else cout<<"No se ha podido generar la copia de seguridad."<<endl;
                    break;
            case 4: if(obj.copiaTipos()==true)cout<<endl;
                    else cout<<"No se ha podido generar la copia de seguridad."<<endl;
                    break;
            case 5: if(obj.restaurarJugadores()==true)cout<<endl;
                    else cout<<"No se ha podido completar la restauracion."<<endl;
                    break;
            case 6: if(obj.restaurarDeportes()==true)cout<<endl;
                    else cout<<"No se ha podido completar la restauracion."<<endl;
                    break;
            case 7: if(obj.restaurarEquipos()==true)cout<<endl;
                    else cout<<"No se ha podido completar la restauracion."<<endl;;
                    break;
            case 8: if(obj.restaurarTipos()==true)cout<<endl;
                    else cout<<"No se ha podido completar la restauracion."<<endl;;
                    break;
            case 9: if(obj.inicioJUGADORES()==true && obj.inicioDEPORTES()==true && obj.inicioEQUIPOS()==true && obj.inicioTIPOS()==true)cout<<endl;
                    else cout<<"No se ha podido completar la copia de archivos."<<endl;
                    break;
            case 0: return 0;
                    break;
            default: cout<<"VALOR INCORRECTO"<<endl;
                    break;
            }
            system("pause");
        }
}

#endif // MENUCONFIGURACION_H_INCLUDED
