#ifndef MENUDEPORTES_H_INCLUDED
#define MENUDEPORTES_H_INCLUDED

int MenuDeportes(){
    ArchivoDeportes obj;
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU DEPORTES "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) AGREGAR DEPORTE "<<endl;
        cout<<"2) LISTAR DEPORTE POR ID "<<endl;
        cout<<"3) LISTAR TODO "<<endl;
        cout<<"4) MODIFICAR ANIO DE ORIGEN "<<endl;
        cout<<"5) ELIMINAR REGISTRO "<<endl;
        cout<<"-------------- "<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: obj.cargarDeporte();
                    break;
            case 2: if(obj.listarDeporteID()==1)cout<<endl;
                    else cout<<"No hay deporte con la ID ingresada"<<endl;
                    break;
            case 3: if(obj.listarDeportes()==1)cout<<endl;
                    else cout<<"No hay deportes para listar"<<endl;
                    break;
            case 4: if(obj.modificarAnioOrigen()==1)cout<<endl;
                    else cout<<"El deporte que intenta buscar con esa ID no existe"<<endl;
                    break;
            case 5: if(obj.bajaLogica()==true)cout<<"Deporte dado de baja."<<endl;
                    else cout<<"El deporte no se ha podido dar de baja."<<endl;
                    break;
            case 0: return 0;
                    break;
            default: cout<<"VALOR INCORRECTO"<<endl;
                    break;
            }
            system("pause");
        }
}

#endif // MENUDEPORTES_H_INCLUDED
