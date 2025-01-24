#ifndef MENUJUGADORES_H_INCLUDED
#define MENUJUGADORES_H_INCLUDED

int MenuJugadores(){
    ArchivoJugadores obj;
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU JUGADORES "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) AGREGAR JUGADOR "<<endl;
        cout<<"2) LISTAR JUGADOR POR DNI "<<endl;
        cout<<"3) LISTAR TODOS LOS JUGADORES "<<endl;
        cout<<"4) MODIFICAR FECHA DE INSCRIPCION "<<endl;
        cout<<"5) ELIMINAR REGISTRO DE JUGADOR "<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: obj.cargarJugador();
                    break;
            case 2: if(obj.listarJugadorDNI()==1)cout<<endl;
                    else cout<<"No hay jugador con el DNI ingresado"<<endl;
                    break;
            case 3: if(obj.listarJugadores()==1)cout<<endl;
                    else cout<<"No hay jugadores para listar"<<endl;
                    break;
            case 4: if(obj.modificarFechaInscripcion()==1)cout<<endl;
                    else cout<<"El jugador que intenta buscar no existe"<<endl;
                    break;
            case 5: if(obj.bajaLogica()==true)cout<<"Jugador dado de baja."<<endl;
                    else cout<<"El jugador no se ha podido dar de baja."<<endl;
                    break;
            case 0: return 0;
                    break;
            default: cout<<"VALOR INCORRECTO"<<endl;
                    break;
            }
            system("pause");
        }
}

#endif // MENUJUGADORES_H_INCLUDED
