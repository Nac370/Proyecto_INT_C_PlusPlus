#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

///Punto 1
///Generar un archivo / con los deportes / que tengan un nivel de dificultad 3.
///Cada registro / debe tener el ID de deporte, / el nombre del deporte / y el tipo de deporte.
///Archivos que debo usar: deportes y TipodeDeportes
class deportesDificultad3{
private:
    int ID, tipo;
    char nombre[30];
public:
    deportesDificultad3(int id=0, const char *n="nada", int t=0){
    ID=id;
    strcpy(nombre, n);
    tipo=t;
    }

    void Mostrar(){
        cout<<"ID de deporte: "<<ID<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Tipo de deporte: "<<tipo<<endl<<endl;
    }

    bool listarArchivo(){
        deportesDificultad3 obj;
        FILE *aDIF;
        aDIF=fopen("DeportesDificultad3.dat", "rb");
        if(aDIF==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        while(fread(&obj, sizeof(deportesDificultad3), 1, aDIF)==1){
            obj.Mostrar();
        }
        fclose(aDIF);
        return true;

    }

    int contarRegistros(){
        FILE *aDIF;
        aDIF=fopen("DeportesDificultad3.dat", "rb");
        if(aDIF==NULL){
            cout<<"Error de archivo."<<endl;
            return -1;
        }
        fseek(aDIF, 0,2);
        int tam=ftell(aDIF);
        fclose(aDIF);
        return tam/sizeof(deportesDificultad3);
    }

    deportesDificultad3 leerRegistro(int pos){
        deportesDificultad3 obj;
        FILE *aDIF;
        aDIF=fopen("DeportesDificultad3.dat", "rb");
        if(aDIF==NULL) return obj;
        fseek(aDIF, sizeof obj*pos,0);
        fread(&obj, sizeof obj,1, aDIF);
        fclose(aDIF);
        return obj;
    }

    bool generarArchivo(){
        Deportes obj;
        TipoDeporte obj1;
        deportesDificultad3 obj2;

        ///Abro los archivos
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "rb");
        if(aDERP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        FILE *aDIF;
        aDIF=fopen("DeportesDificultad3.dat", "wb");
        if(aDIF==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }

        int id_anterior=0;
        ///Genero el archivo
        while(fread(&obj1, sizeof(TipoDeporte), 1, aTIP)==1){
            if(obj1.getEstado()==true){
                if(obj1.getDificultad()==3){
                    while(fread(&obj, sizeof(Deportes), 1, aDERP)==1){
                        if(obj.getEstado()==true){
                            if(obj1.getID()==obj.getTipoDeporte() && id_anterior!=obj.getID_deporte()){
                                obj2.setTipo(obj1.getID());
                                obj2.setID(obj.getID_deporte());
                                obj2.setNombre(obj.getNombre());
                                id_anterior=obj.getID_deporte();
                                bool escribio=fwrite(&obj2, sizeof(deportesDificultad3), 1, aDIF);
                                if(escribio==false){
                                    cout<<"Error en la escritura."<<endl;
                                    fclose(aDERP);
                                    fclose(aTIP);
                                    fclose(aDIF);
                                    return false;
                                }
                            }
                        }
                    }
                    fseek(aDERP, 0, 0);
                }
            }
        }
        ///Cierro los archivos
        fclose(aDERP);
        fclose(aTIP);
        fclose(aDIF);
        return true;
    }

    ///Sets
    void setID(int id){ID=id;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setTipo(int t){tipo=t;}

    ///Gets
    int getID(){return ID;}
    const char *getNombre(){return nombre;}
    int getTipo(){return tipo;}

};


///Punto 2
///Informar el mes / de este año / con mayor cantidad / de jugadores inscriptos.
///año=2023 / los meses pueden ser un vector de tam=11.
///Archivos que necesito: jugadores.
bool mayorMes(){
    Jugadores obj;
    FILE *aJUJ;
    aJUJ=fopen("Jugadores.dat", "rb");
    if(aJUJ==NULL){
        cout<<"Error de archivo."<<endl;
        return false;
    }

    int vec[11]={0};

    while(fread(&obj, sizeof(Jugadores), 1, aJUJ)==1){
        if(obj.getEstado()==true){
            if(obj.getFechaInscripcion().getAnio()==2023){
                vec[(obj.getFechaInscripcion().getMes())-1]++;
            }
        }
    }
    fclose(aJUJ);

    int mesMayor=0, cantMayor=0;
    for(int i=0;i<11;i++){
        if(vec[i]>cantMayor){
            cantMayor=vec[i];
            mesMayor=i+1;
        }
    }
    cout<<"El mes de este anio con mayor cantidad de jugadores inscriptos es el: "<<mesMayor<<endl;
    return true;
}


///Punto 3
///Hacer una función / para generar un vector dinámico / para cargar los registros / del archivo generado en el punto 1.
///Listar el vector.
bool vectorDificultad(){
    deportesDificultad3 obj, *v;

    int cantReg=obj.contarRegistros();
    if(cantReg==0){
        cout<<"No hay registros en el archivo."<<endl;
        return false;
    }

    v=new deportesDificultad3[cantReg];
    if(v==NULL){
        cout<<"Error de memoria."<<endl;
        return false;
    }
    for(int i=0;i<cantReg;i++){
        v[i]=obj.leerRegistro(i);
    }
    for(int i=0;i<cantReg;i++){
        v[i].Mostrar();
    }
    delete v;
    return true;
}


int MenuReportes(){

    deportesDificultad3 obj;
    int opc;
    while(true)
        {
        system("cls");
        cout<<"MENU REPORTES "<<endl;
        cout<<"--------------"<<endl;
        cout<<"1) PUNTO 1 "<<endl;
        cout<<"2) PUNTO 2 "<<endl;
        cout<<"3) PUNTO 3 "<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) VOLVER AL MENU PRINCIPAL "<<endl;
        cin>>opc;

        system("cls");

        switch(opc)
            {
            case 1: obj.generarArchivo();
                    break;
            case 2: mayorMes();
                    break;
            case 3: vectorDificultad();
                    break;
            case 0: return 0;
                    break;
            default: cout<<"VALOR INCORRECTO"<<endl;
                    break;
            }
            system("pause");
        }
}

#endif // MENUREPORTES_H_INCLUDED
