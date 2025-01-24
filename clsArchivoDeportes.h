#ifndef CLSARCHIVODEPORTES_H_INCLUDED
#define CLSARCHIVODEPORTES_H_INCLUDED



class ArchivoDeportes{
private:
    Deportes obj;
public:

    int buscarDeportesRegistroJugadores(int deporte){
        Deportes obj;
        FILE *aDERP;
        aDERP=fopen("deportes.dat","rb");
        if(aDERP==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -1;
        }
        bool posRegistro=0;
        while(fread(&obj,sizeof(Deportes),1,aDERP)==1){
            if(obj.getID_deporte()==deporte){
                fclose(aDERP);
                return posRegistro=1;
            }
        }
        fclose(aDERP);
        return posRegistro=0;
    }

    int buscarDeportes(int deporte){
        Deportes obj;
        FILE *aDERP;
        aDERP=fopen("deportes.dat","rb");
        if(aDERP==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -3;
        }
        int posRegistro=-1;
        while(fread(&obj,sizeof(Deportes),1,aDERP)==1){
            posRegistro++;
            if(obj.getID_deporte()==deporte){
                if(obj.getEstado()==true){
                    fclose(aDERP);
                    return posRegistro;
                }
                fclose(aDERP);
                return -2;
            }
        }
        fclose(aDERP);
        return -1;
    }

    int contarDeportes(){
    FILE *aDERP;
    aDERP=fopen("deportes.dat", "rb");
    if(aDERP==NULL) return -1;
    fseek(aDERP, 0,2);
    int tam=ftell(aDERP);
    fclose(aDERP);
    return tam/sizeof(Deportes);
    }

    Deportes leerDeporte(int pos){
		Deportes obj;
        obj.setID_deporte(-1);
        FILE *aDERP;
        aDERP=fopen("deportes.dat","rb");
        if(aDERP==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return obj;
        }
        fseek(aDERP,sizeof obj*pos,0);

        int leyo=fread(&obj,sizeof(Deportes),1,aDERP);
        fclose(aDERP);

        if(leyo==0) obj.setID_deporte(-1);
        return obj;
    }

    ///1)
    bool cargarDeporte(){
    Deportes obj;
    FILE *aDERP;
    aDERP=fopen("deportes.dat", "ab");
    if(aDERP==NULL){
        cout<<"Error de archivo";
        return false;
    }
    int deporte;
    cout<<"Ingresar ID de deporte: ";
    cin>>deporte;
    cout<<endl;
    int pos=buscarDeportes(deporte);
    int cant=contarDeportes();
    if(cant>=10){
        cout<<"Se alcanzo la cantidad maxima de ID de deportes."<<endl;
        fclose(aDERP);
        return false;
    }
    if(pos==-1){
        if(obj.Cargar(pos, deporte)==true){
            bool escribio=fwrite(&obj, sizeof(Deportes), 1, aDERP);
            fclose(aDERP);
            return escribio;
        }
        else cout<<"No se pudo agregar el deporte, intentelo de nuevo."<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"La ID de deporte ingresada ya existe pero fue dada de baja."<<endl;
        fclose(aDERP);
        return false;
    }
    cout<<"La ID de deporte ingresada ya existe en los registros."<<endl;
    fclose(aDERP);
    return false;
    }

    ///2
    int listarDeporteID(){
        int id;
        cout<<"Ingresar ID del deporte que quiere listar: ";
        cin>>id;
        cout<<endl;
        bool encontrado=0;
        Deportes obj;
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "rb");
        if(aDERP==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof(Deportes), 1, aDERP)==1){
            if(obj.getID_deporte()==id){
                if(obj.getEstado()==true){
                obj.Mostrar();
                encontrado=1;
                return encontrado;
                }
                else {cout<<"El deporte que intenta listar existe pero fue dado de baja."<<endl;
                return encontrado;
                }
            }
        }
        fclose(aDERP);
        return encontrado;
    }

    ///3
    int listarDeportes(){
        bool hayQUEmostrar=0;
        Deportes obj;
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "rb");
        if(aDERP==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof(Deportes), 1, aDERP)==1){
                obj.Mostrar();
                hayQUEmostrar=1;
                cout<<endl<<endl;
        }
        fclose(aDERP);
        return hayQUEmostrar;
    }

    ///4
    int modificarAnioOrigen(){
        Deportes obj;
        int id;
        cout<<"Ingresar ID del deporte cuyo anio de origen quiere modificar: ";
        cin>>id;
        cout<<endl;
        int an;

        int pos=buscarDeportes(id);
        if(pos==-1){
            return 0;
        }
        else{
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "rb+");
        if(aDERP==NULL){
            cout<<"Error al leer el archivo."<<endl;
            return -1;
        }
        fseek(aDERP, sizeof obj*pos, 0);
        fread(&obj, sizeof(Deportes), 1, aDERP);
        cout<<"Ingresar a que anio se desea modificar: ";
        cin>>an;
        obj.setAnioOrigen(an);
        fseek(aDERP, sizeof obj*pos, 0);
        bool escribio=fwrite(&obj, sizeof(Deportes), 1, aDERP);
        if(escribio==1){
            fclose(aDERP);
            return 1;
        }
        else{
            fclose(aDERP);
            return 0;
            }
        }
    }

    ///Modificar Jugador(para dar de baja)
    bool modificarDeporte(Deportes obj, int pos){
        FILE *aDERP;
        aDERP=fopen("deportes.dat","rb+");
        if(aDERP==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        fseek(aDERP,sizeof obj*pos,0);
        bool escribio=fwrite(&obj,sizeof(Deportes),1,aDERP);
        fclose(aDERP);
        return escribio;
    }

    ///5 BAJA LOGICA
    bool bajaLogica(){
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "rb");
        if(aDERP==NULL){
            cout<<"Error al abrir el archivo."<<endl;
            return 0;
        }
        int id;
        cout<<"Ingresar ID del deporte que quiera dar de baja: ";
        cin>>id;
        cout<<endl;

        int pos=buscarDeportes(id);
        if(pos==-1){
            cout<<"El deporte con esa ID no fue encontrado."<<endl;
            return 0;
        }
        Deportes obj;
        obj=leerDeporte(pos);
        if(obj.getID_deporte()==-1){
            cout<<"No existe el jugador."<<endl;
            return 0;
        }
        obj.setEstado(false);
        bool quepaso=modificarDeporte(obj,pos);
        return quepaso;
    }
};

#endif // CLSARCHIVODEPORTES_H_INCLUDED
