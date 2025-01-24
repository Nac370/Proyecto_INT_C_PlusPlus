#ifndef MENUEQUIPOS_H_INCLUDED
#define MENUEQUIPOS_H_INCLUDED

int MenuEquipos(){
    ArchivoEquipos obj;
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU EQUIPOS "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) AGREGAR EQUIPO "<<endl;
        cout<<"2) LISTAR EQUIPO POR ID "<<endl;
        cout<<"3) LISTAR TODO "<<endl;
        cout<<"4) MODIFICAR NOMBRE "<<endl;
        cout<<"5) ELIMINAR REGISTRO "<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: obj.cargarEquipo();
                    break;
            case 2: obj.mostrarIDequipo();
                    break;
            case 3: obj.mostrarEquipos();
                    break;
            case 4: obj.nombreEquipos();
                    break;
            case 5: obj.bajaLogica();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"VALOR INCORRECTO"<<endl;
                    break;
            }
            system("pause");
        }
}

#endif // MENUEQUIPOS_H_INCLUDED
