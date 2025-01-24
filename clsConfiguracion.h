#ifndef CLSCONFIGURACION_H_INCLUDED
#define CLSCONFIGURACION_H_INCLUDED

class Configuracion{
private:
    Jugadores obj;
    Deportes obj2;
    Equipos obj3;
    TipoDeporte obj4;
public:

    ///1 Copia seguridad JUGADORES
    bool copiaJugadores(){
        Jugadores obj;
        ///Archivo bkp
        FILE *aCJUJ;
        aCJUJ=fopen("Jugadores.bkp", "wb");
        if(aCJUJ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Archivo original
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "rb");
        if(aJUJ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        while(fread(&obj, sizeof(Jugadores), 1, aJUJ)==1){
            bool escribe=fwrite(&obj, sizeof(Jugadores), 1, aCJUJ);
            if(escribe==0){
                cout<<"Algo fallo durante la copia"<<endl;
                fclose(aCJUJ);
                fclose(aJUJ);
                return false;
            }
        }
        fclose(aCJUJ);
        fclose(aJUJ);
        cout<<endl<<"Copia terminada."<<endl;
        return true;
    }
    /*///Prueba jugadores bkp
    int listarJugadores(){
        bool hayQUEmostrar=0;
        Jugadores obj;
        FILE *aCJUJ;
        aCJUJ=fopen("Jugadores.bkp", "rb");
        if(aCJUJ==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof(Jugadores), 1, aCJUJ)==1){
                obj.Mostrar();
                hayQUEmostrar=1;
                cout<<endl<<endl;
        }
        fclose(aCJUJ);
        return hayQUEmostrar;
    }*/

    ///2 Copia seguridad DEPORTES
    bool copiaDeportes(){
        Deportes obj2;
        ///Archivo bkp
        FILE *aCDERP;
        aCDERP=fopen("deportes.bkp", "wb");
        if(aCDERP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Archivo original
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "rb");
        if(aDERP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        while(fread(&obj, sizeof(Deportes), 1, aDERP)==1){
            bool escribe=fwrite(&obj, sizeof(Deportes), 1, aCDERP);
            if(escribe==0){
                cout<<"Algo fallo durante la copia"<<endl;
                fclose(aCDERP);
                fclose(aDERP);
                return false;
            }
        }
        fclose(aCDERP);
        fclose(aDERP);
        cout<<endl<<"Copia terminada."<<endl;
        return true;
    }
    /*///Prueba deportes bkp
    int listarDeportes(){
        bool hayQUEmostrar=0;
        Deportes obj2;
        FILE *aCDERP;
        aCDERP=fopen("deportes.bkp", "rb");
        if(aCDERP==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj2, sizeof(Deportes), 1, aCDERP)==1){
                obj2.Mostrar();
                hayQUEmostrar=1;
                cout<<endl<<endl;
        }
        fclose(aCDERP);
        return hayQUEmostrar;
    }*/

    ///3 Copia seguridad EQUIPOS
    bool copiaEquipos(){
        Equipos obj3;
        ///Archivo bkp
        FILE *aCEQ;
        aCEQ=fopen("equipos.bkp", "wb");
        if(aCEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Archivo original
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "rb");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        while(fread(&obj3, sizeof(Equipos), 1, aEQ)==1){
            bool escribe=fwrite(&obj3, sizeof(Equipos), 1, aCEQ);
            if(escribe==0){
                cout<<"Algo fallo durante la copia"<<endl;
                fclose(aCEQ);
                fclose(aEQ);
                return false;
            }
        }
        fclose(aCEQ);
        fclose(aEQ);
        cout<<endl<<"Copia terminada."<<endl;
        return true;
    }
    /*///Prueba EQUIPOS bkp
    int listarEquipos(){
        bool hayQUEmostrar=0;
        Equipos obj3;
        FILE *aCEQ;
        aCEQ=fopen("equipos.bkp", "rb");
        if(aCEQ==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj3, sizeof(Equipos), 1, aCEQ)==1){
                obj3.Mostrar();
                hayQUEmostrar=1;
                cout<<endl<<endl;
        }
        fclose(aCEQ);
        return hayQUEmostrar;
    }*/

    ///4 Copia seguridad TIPOS DE DEPORTES
    bool copiaTipos(){
        TipoDeporte obj4;
        ///Archivo bkp
        FILE *aCTIP;
        aCTIP=fopen("TipodeDeporte.bkp", "wb");
        if(aCTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Archivo original
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "rb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        while(fread(&obj4, sizeof(TipoDeporte), 1, aTIP)==1){
            bool escribe=fwrite(&obj4, sizeof(TipoDeporte), 1, aCTIP);
            if(escribe==0){
                cout<<"Algo fallo durante la copia"<<endl;
                fclose(aCTIP);
                fclose(aTIP);
                return false;
            }
        }
        fclose(aCTIP);
        fclose(aTIP);
        cout<<endl<<"Copia terminada."<<endl;
        return true;
    }
    /*///Prueba TIPOS DE DEPORTES bkp
    int listarTipos(){
        bool hayQUEmostrar=0;
        TipoDeporte obj4;
        FILE *aCTIP;
        aCTIP=fopen("TipodeDeporte.bkp", "rb");
        if(aCTIP==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj4, sizeof(TipoDeporte), 1, aCTIP)==1){
                obj4.Mostrar();
                hayQUEmostrar=1;
                cout<<endl<<endl;
        }
        fclose(aCTIP);
        return hayQUEmostrar;
    }*/

    ///5 Restaurar archivo JUGADORES
    bool restaurarJugadores(){
        Jugadores obj;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "wb");
        if(aJUJ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo backup
        FILE *aCJUJ;
        aCJUJ=fopen("Jugadores.bkp", "rb");
        if(aCJUJ==NULL){
            cout<<"Error al leer el archivo."<<endl;
            return false;
        }
        ///Leo el backup y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj, sizeof(Jugadores), 1, aCJUJ)==1){
                bool escribe=fwrite(&obj, sizeof(Jugadores), 1, aJUJ);
                if(escribe==0){
                    cout<<"Algo fallo durante la restauracion."<<endl;
                    fclose(aJUJ);
                    fclose(aCJUJ);
                    return false;
                }
        }
        fclose(aJUJ);
        fclose(aCJUJ);
        cout<<endl<<"Restauracion terminada."<<endl;
        return true;
    }

    ///6 Restaurar archivo DEPORTES
    bool restaurarDeportes(){
        Deportes obj2;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "wb");
        if(aDERP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo backup
        FILE *aCDERP;
        aCDERP=fopen("deportes.bkp", "rb");
        if(aCDERP==NULL){
            cout<<"Error al leer el archivo."<<endl;
            return false;
        }
        ///Leo el backup y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj2, sizeof(Deportes), 1, aCDERP)==1){
                bool escribe=fwrite(&obj2, sizeof(Deportes), 1, aDERP);
                if(escribe==0){
                    cout<<"Algo fallo durante la restauracion."<<endl;
                    fclose(aDERP);
                    fclose(aCDERP);
                    return false;
                }
        }
        fclose(aDERP);
        fclose(aCDERP);
        cout<<endl<<"Restauracion terminada."<<endl;
        return true;
    }

    ///7 Restaurar archivo EQUIPOS
    bool restaurarEquipos(){
        Equipos obj3;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "wb");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo backup
        FILE *aCEQ;
        aCEQ=fopen("equipos.bkp", "rb");
        if(aCEQ==NULL){
            cout<<"Error al leer el archivo."<<endl;
            return false;
        }
        ///Leo el backup y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj3, sizeof(Equipos), 1, aCEQ)==1){
                bool escribe=fwrite(&obj3, sizeof(Equipos), 1, aEQ);
                if(escribe==0){
                    cout<<"Algo fallo durante la restauracion."<<endl;
                    fclose(aEQ);
                    fclose(aCEQ);
                    return false;
                }
        }
        fclose(aEQ);
        fclose(aCEQ);
        cout<<endl<<"Restauracion terminada."<<endl;
        return true;
    }

    ///8 Restaurar archivo TIPOS DE DEPORTES
    bool restaurarTipos(){
        TipoDeporte obj4;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "wb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo backup
        FILE *aCTIP;
        aCTIP=fopen("TipodeDeporte.bkp", "rb");
        if(aCTIP==NULL){
            cout<<"Error al leer el archivo."<<endl;
            return false;
        }
        ///Leo el backup y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj4, sizeof(TipoDeporte), 1, aCTIP)==1){
                bool escribe=fwrite(&obj4, sizeof(TipoDeporte), 1, aTIP);
                if(escribe==0){
                    cout<<"Algo fallo durante la restauracion."<<endl;
                    fclose(aTIP);
                    fclose(aCTIP);
                    return false;
                }
        }
        fclose(aTIP);
        fclose(aCTIP);
        cout<<endl<<"Restauracion terminada."<<endl;
        return true;
    }

    ///9 Datos de inicio
    ///Carga JUGADORES
    bool inicioJUGADORES(){
        Jugadores obj1;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "wb");
        if(aJUJ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo ini
        FILE *aIJUJ;
        aIJUJ=fopen("Jugadores.ini", "rb");
        if(aIJUJ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Leo el ini y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj1, sizeof(Jugadores), 1, aIJUJ)==1){
                bool escribe=fwrite(&obj1, sizeof(Jugadores), 1, aJUJ);
                if(escribe==0){
                    cout<<"Algo fallo durante la copia."<<endl;
                    fclose(aJUJ);
                    fclose(aIJUJ);
                    return false;
                }
        }
        fclose(aJUJ);
        fclose(aIJUJ);
        return true;
    }

    ///Carga DEPORTES
    bool inicioDEPORTES(){
        Deportes obj2;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aDERP;
        aDERP=fopen("deportes.dat", "wb");
        if(aDERP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo ini
        FILE *aIDERP;
        aIDERP=fopen("deportes.ini", "rb");
        if(aIDERP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Leo el ini y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj2, sizeof(Deportes), 1, aIDERP)==1){
                bool escribe=fwrite(&obj2, sizeof(Deportes), 1, aDERP);
                if(escribe==0){
                    cout<<"Algo fallo durante la copia."<<endl;
                    fclose(aDERP);
                    fclose(aIDERP);
                    return false;
                }
        }
        fclose(aDERP);
        fclose(aIDERP);
        return true;
    }

    ///Carga EQUIPOS
    bool inicioEQUIPOS(){
        Equipos obj3;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "wb");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo ini
        FILE *aIEQ;
        aIEQ=fopen("equipos.ini", "rb");
        if(aIEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Leo el ini y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj3, sizeof(Equipos), 1, aIEQ)==1){
                bool escribe=fwrite(&obj3, sizeof(Equipos), 1, aEQ);
                if(escribe==0){
                    cout<<"Algo fallo durante la copia."<<endl;
                    fclose(aEQ);
                    fclose(aIEQ);
                    return false;
                }
        }
        fclose(aEQ);
        fclose(aIEQ);
        return true;
    }

    ///Carga TIPOS
    bool inicioTIPOS(){
        TipoDeporte obj4;
        ///Abro archivo "original" o más bien lo abro en limpio con "wb"
        FILE *aTIP;
        aTIP=fopen("TipodeDeporte.dat", "wb");
        if(aTIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Abro archivo ini
        FILE *aITIP;
        aITIP=fopen("TipodeDeporte.ini", "rb");
        if(aITIP==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        ///Leo el ini y lo voy escribiendo/copiando al "original" tal va leyendo los registros
        while(fread(&obj4, sizeof(TipoDeporte), 1, aITIP)==1){
                bool escribe=fwrite(&obj4, sizeof(TipoDeporte), 1, aTIP);
                if(escribe==0){
                    cout<<"Algo fallo durante la copia."<<endl;
                    fclose(aTIP);
                    fclose(aITIP);
                    return false;
                }
        }
        fclose(aTIP);
        fclose(aITIP);
        cout<<"Copia realizada con exito."<<endl;
        return true;
    }

};

#endif // CLSCONFIGURACION_H_INCLUDED
