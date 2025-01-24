#ifndef CLSARCHIVOTIPOSDEPORTE_H_INCLUDED
#define CLSARCHIVOTIPOSDEPORTE_H_INCLUDED

class ArchivoTiposDeporte{
private:
    TipoDeporte obj;
public:

    int buscarID(int ID){
        TipoDeporte obj;
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return -3;
        }
        int pos=-1;
        while(fread(&obj, sizeof(TipoDeporte), 1, aTIP)==1){
            pos++;
            if(obj.getID()==ID){
                if(obj.getEstado()==true){
                    fclose(aTIP);
                    return pos;
                }
                return -2;
            }
        }
        fclose(aTIP);
        return -1;
    }

    ///1
    bool cargarTipo(){
        TipoDeporte obj;
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "ab");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del tipo de deporte (entre 1 y 21): "<<endl;
        cin>>ID;
        int contErroresID=0;
        if(ID<1 || ID>21){
            while(ID<1 || ID>21){
                contErroresID++;
                cout<<endl<<"La ID ingresada no es valida."<<endl;
                cout<<"Por favor intentelo de nuevo."<<endl;
                cout<<endl<<"Ingresar ID del tipo de deporte (entre 1 y 21): "<<endl;
                cin>>ID;
                if(contErroresID==3){
                    cout<<endl<<"Se ingreso una ID no valida repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    fclose(aTIP);
                    return false;
                }
            }
        }
        int pos=buscarID(ID);
        if(pos==-1){
            if(obj.Cargar(ID)==true){
                bool escribio=fwrite(&obj, sizeof(TipoDeporte), 1, aTIP);
                if(escribio==true){
                    cout<<"Tipo de deporte dado de alta."<<endl;
                    fclose(aTIP);
                    return true;
                }
                cout<<"Error al dar de alta."<<endl;
                fclose(aTIP);
                return false;
            }
        }
        if(pos==-2){
            cout<<"La ID ingresada ya existe pero fue dada de baja."<<endl;
            fclose(aTIP);
            return false;
        }
        cout<<"La ID ingresada ya existe en los registros."<<endl;
        fclose(aTIP);
        return false;
    }

    ///2
    bool mostrarID(){
        TipoDeporte obj;
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del tipo que desea buscar: "<<endl;
        cin>>ID;
        cout<<endl;
        int pos=buscarID(ID);
        if(pos==-1){
            cout<<"La ID ingresada no fue encontrada en los registros."<<endl;
            fclose(aTIP);
            return false;
        }
        fseek(aTIP, sizeof(TipoDeporte)*pos, 0);
        fread(&obj, sizeof(TipoDeporte), 1, aTIP);
        if(obj.getEstado()==false){
            cout<<"El equipo que quiere listar existe pero fue dado de baja."<<endl;
            fclose(aTIP);
            return false;
        }
        obj.Mostrar();
        cout<<endl;
        fclose(aTIP);
        return true;
    }

    ///3
    bool mostrarTipos(){
        TipoDeporte obj;
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        bool contenido=false;
        while(fread(&obj, sizeof(TipoDeporte), 1, aTIP)==1){
            if(obj.getEstado()==true){
                obj.Mostrar();
                cout<<endl;
                contenido=true;
            }
        }
        fclose(aTIP);
        if(contenido==true){
            return true;
        }
        cout<<"No hay registros para listar."<<endl;
        return false;
    }

    ///4
    bool dificultadTipos(){
        TipoDeporte obj;
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb+");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del tipo de deporte al que quiere modificar la dificultad: "<<endl;
        cin>>ID;
        int pos=buscarID(ID);
        if(pos==-1){
            cout<<"La ID ingresada no fue encontrada en los registros."<<endl;
            fclose(aTIP);
            return false;
        }
        fseek(aTIP, sizeof(TipoDeporte)*pos, 0);
        fread(&obj, sizeof(TipoDeporte), 1, aTIP);
        int nivel;
        cout<<"Ingresar nivel de dificultad que reemplazara a la anterior: "<<endl;
        cin>>nivel;
        obj.setDificultad(nivel);
        fseek(aTIP, sizeof(TipoDeporte)*pos, 0);
        bool escribio=fwrite(&obj, sizeof(TipoDeporte), 1, aTIP);
        fclose(aTIP);
        if(escribio==true){
            cout<<"Nivel de dificultad modificado."<<endl;
            return true;
        }
        cout<<"Error al modificar el nivel de dificultad."<<endl;
        return false;
    }

    ///5
    bool bajaLogica(){
        TipoDeporte obj;
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb+");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del tipo de deporte al que quiere dar de baja: "<<endl;
        cin>>ID;
        int pos=buscarID(ID);
        if(pos==-1){
            cout<<"La ID ingresada no fue encontrada en los registros."<<endl;
            fclose(aTIP);
            return false;
        }
        fseek(aTIP, sizeof(TipoDeporte)*pos, 0);
        fread(&obj, sizeof(TipoDeporte), 1, aTIP);
        obj.setEstado(false);
        fseek(aTIP, sizeof(TipoDeporte)*pos, 0);
        bool escribio=fwrite(&obj, sizeof(TipoDeporte), 1, aTIP);
        fclose(aTIP);
        if(escribio==true){
            cout<<"Tipo de deporte dado de baja."<<endl;
            return true;
        }
        cout<<"Error al dar de baja el tipo de deporte."<<endl;
        return false;
    }

};

#endif // CLSARCHIVOTIPOSDEPORTE_H_INCLUDED
