#ifndef CLSTIPOSDEPORTE_H_INCLUDED
#define CLSTIPOSDEPORTE_H_INCLUDED

class TipoDeporte{
private:
    int ID, dificultad;
    char nombre[30];
    bool estado;
public:
    TipoDeporte(int id=0, const char *n="nada", int d=0, bool e=false){
    ID=id;
    strcpy(nombre,n);
    dificultad=d;
    }

    bool Cargar(int id){
        ID=id;
        cout<<"Nombre: "<<endl;
        cargarCadena(nombre,29);
        cout<<"Nivel de dificultad (entre 1 y 8): "<<endl;
        cin>>dificultad;
        int contErroresDificultad=0;
        if(dificultad<1 || dificultad>8){
            while(dificultad<1 || dificultad>8){
                contErroresDificultad++;
                cout<<endl<<"El nivel de dificultad ingresado no es valido."<<endl;
                cout<<"Por favor, intentelo de nuevo."<<endl;
                cout<<endl<<"Nivel de dificultad (entre 1 y 8): "<<endl;
                cin>>dificultad;
                if(contErroresDificultad==3){
                    cout<<endl<<"Se ha ingresado un nivel de dificultad no valido repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return false;
                }
            }
        }
        estado=true;
        return true;
    }

    void Mostrar(){
        cout<<"ID: "<<ID<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Nivel de dificultad: "<<dificultad<<endl;
    }

    ///Sets
    void setID(int id){ID=id;}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setDificultad(int d){dificultad=d;}
    void setEstado(bool e){estado=e;}

    ///Gets
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getDificultad(){return dificultad;}
    bool getEstado(){return estado;}

};

#endif // CLSTIPOSDEPORTE_H_INCLUDED
