#ifndef CLSDEPORTES_H_INCLUDED
#define CLSDEPORTES_H_INCLUDED



class Deportes{
private:
    int ID_deporte;
    char nombre[30];
    int tipoDeporte, aOrigen;
    bool estado;
    FechaActual obj;
    ArchivoTiposDeporte obj1;
public:
    Deportes(int id=0, const char *n="nada", int td=0, int ao=0){
    ID_deporte=id;
    strcpy(nombre,n);
    tipoDeporte=td;
    aOrigen=ao;
    }
    bool Cargar(int pos, int deporte){
        ID_deporte=deporte;
        if(ID_deporte>10){
            cout<<"Error en la cantidad de ID de deportes."<<endl;
            return false;
        }
        cout<<"Nombre: ";
        cargarCadena(nombre, 29);
        cout<<endl<<"Tipo de deporte: ";
        cin>>tipoDeporte;
        int contErroresTipoDeporte=0;
        if(tipoDeporte<1 || tipoDeporte>21){
            while(tipoDeporte<1 || tipoDeporte>21){
                contErroresTipoDeporte++;
                cout<<endl<<"El tipo de deporte ingresado no es valido."<<endl;
                cout<<"Por favor, intentelo de nuevo."<<endl;
                cout<<endl<<"Tipo de deporte: "<<endl;
                cin>>tipoDeporte;
                if(contErroresTipoDeporte==3){
                    cout<<endl<<"Se ha ingresado un tipo no valido repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return false;
                }
            }
        }
        contErroresTipoDeporte=0;
        if(obj1.buscarID(tipoDeporte)==-1){
            while(obj1.buscarID(tipoDeporte)==-1){
                contErroresTipoDeporte++;
                cout<<endl<<"El tipo de deporte ingresado no se encuentra en el archivo de equipos."<<endl;
                cout<<"Por favor, intentelo de nuevo."<<endl;
                cout<<endl<<"Tipo de deporte: "<<endl;
                cin>>tipoDeporte;
                if(contErroresTipoDeporte==3){
                    cout<<endl<<"Ha introducido un tipo no valido repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return false;
                }
            }
        }
        cout<<endl<<"Anio de origen: ";
        cin>>aOrigen;
        int contErroresOrigen=0;
        if(aOrigen<1800 || aOrigen>obj.getAnio()){
            while(aOrigen<1800 || aOrigen>obj.getAnio()){
                contErroresOrigen++;
                cout<<endl<<"El anio de origen ingresado no es valido."<<endl;
                cout<<"Por favor, intentelo de nuevo."<<endl;
                cout<<endl<<"Anio de origen: "<<endl;
                cin>>aOrigen;
                if(contErroresOrigen==3){
                    cout<<endl<<"Se ha ingresado un anio de origen no valido repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return false;
                }
            }
        }
        cout<<endl;
        estado=true;
        return true;
    }
    void Mostrar(){
        if(estado==true){
            cout<<"ID de deporte: "<<ID_deporte<<endl;
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Tipo de deporte: "<<tipoDeporte<<endl;
            cout<<"Anio de origen: "<<aOrigen<<endl;
        }
    }
    ///Sets
    void setID_deporte(int id){ID_deporte=id;}
    void setNombre(const char *n){strcpy(nombre, n);}
    void setTipoDeporte(int td){tipoDeporte=td;}
    void setAnioOrigen(int ao){aOrigen=ao;}
    void setEstado(bool e){estado=e;}
    ///Gets
    int getID_deporte(){return ID_deporte;}
    const char *getNombre(){return nombre;}
    int getTipoDeporte(){return tipoDeporte;}
    int getAnioOrigen(){return aOrigen;}
    bool getEstado(){return estado;}
};

#endif // CLSDEPORTES_H_INCLUDED
