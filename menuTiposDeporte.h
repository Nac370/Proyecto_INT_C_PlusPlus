#ifndef MENUTIPOSDEPORTE_H_INCLUDED
#define MENUTIPOSDEPORTE_H_INCLUDED

int MenuTiposDeporte(){
    ArchivoTiposDeporte obj;
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU TIPOS DE DEPORTE "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) AGREGAR TIPO "<<endl;
        cout<<"2) LISTAR TIPO POR ID "<<endl;
        cout<<"3) LISTAR TODO "<<endl;
        cout<<"4) MODIFICAR NIVEL DE DIFICULTAD "<<endl;
        cout<<"5) ELIMINAR REGISTRO "<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: obj.cargarTipo();
                    break;
            case 2: obj.mostrarID();
                    break;
            case 3: obj.mostrarTipos();
                    break;
            case 4: obj.dificultadTipos();
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

#endif // MENUTIPOSDEPORTE_H_INCLUDED
