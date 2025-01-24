#ifndef CLSEQUIPOS_H_INCLUDED
#define CLSEQUIPOS_H_INCLUDED

class Equipos{
private:
    int ID, nivel;
    char nombre[30];
    bool estado;
public:
    Equipos(int id=0, const char *n="nada", int niv=0){
    ID=id;
    strcpy(nombre, n);
    nivel=niv;
    }

    bool Cargar(int idEquipo){
        ID=idEquipo;
        cout<<"Nombre: "<<endl;
        cargarCadena(nombre, 29);
        cout<<"Nivel (entre 1 y 3): "<<endl;
        cin>>nivel;
        int contErrores=0;
        if(nivel<1 || nivel>3){
            while(nivel<1 || nivel>3){
                contErrores++;
                cout<<"El numero ingresado no es valido."<<endl;
                cout<<"Por favor intentelo de nuevo."<<endl<<endl;
                cout<<"Nivel (entre 1 y 3): "<<endl;
                cin>>nivel;
                if(contErrores==3){
                    cout<<endl<<"Se ha ingresado un valor no valido repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return false;
                }
            }
        }
        estado=true;
        return true;
    }

    void Mostrar(){
        cout<<"ID de equipo: "<<ID<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Nivel: "<<nivel<<endl<<endl;
    }

    ///Sets
    void setIDequipos(int id){ID=id;}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setNivel(int N){nivel=N;}
    void setEstado(bool e){estado=e;}
    ///Gets
    int getIDequipos(){return ID;}
    const char *getNombre(){return nombre;}
    int getNivel(){return nivel;}
    bool getEstado(){return estado;}

};

#endif // CLSEQUIPOS_H_INCLUDED
