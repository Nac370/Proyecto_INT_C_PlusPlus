#ifndef CLSARCHIVOEQUIPOS_H_INCLUDED
#define CLSARCHIVOEQUIPOS_H_INCLUDED

class ArchivoEquipos{
private:
    Equipos obj;
public:

    int buscarIDequipo(int ID){
        Equipos obj;
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "rb");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return -3;
        }
        int pos=-1;
        while(fread(&obj, sizeof(Equipos), 1, aEQ)==1){
            pos++;
            if(obj.getIDequipos()==ID){
                if(obj.getEstado()==true){
                    fclose(aEQ);
                    return pos;
                }
                fclose(aEQ);
                return -2;
            }
        }
        fclose(aEQ);
        return -1;
    }

    ///1
    bool cargarEquipo(){
        Equipos obj;
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "ab");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID de equipo: "<<endl;
        cin>>ID;
        int pos=buscarIDequipo(ID);
        if(pos==-1){
            if(obj.Cargar(ID)==true){
                bool escribio=fwrite(&obj, sizeof(Equipos), 1, aEQ);
                if(escribio==true){
                    cout<<"Equipo dado de alta."<<endl;
                    fclose(aEQ);
                    return true;
                }
                cout<<"Error en escritura."<<endl;
                fclose(aEQ);
                return false;
            }
        }
        if(pos==-2){
            cout<<"La ID de equipo ingresada ya existe pero fue dada de baja."<<endl;
            fclose(aEQ);
            return false;
        }
        cout<<"La ID de equipo ingresada ya existe en los registros."<<endl;
        fclose(aEQ);
        return false;
    }

    ///2
    bool mostrarIDequipo(){
        Equipos obj;
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "rb");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del equipo que desea mostrar: "<<endl;
        cin>>ID;
        cout<<endl;
        int pos=buscarIDequipo(ID);
        if(pos==-1){
            cout<<"La ID ingresada no fue encontrada en los registros."<<endl;
            fclose(aEQ);
            return false;
        }
        fseek(aEQ, sizeof(Equipos)*pos, 0);
        fread(&obj, sizeof(Equipos), 1, aEQ);
        if(obj.getEstado()==false){
            cout<<"El equipo que quiere listar existe pero fue dado de baja."<<endl;
            fclose(aEQ);
            return false;
        }
        obj.Mostrar();
        fclose(aEQ);
        return true;
    }

    ///3
    bool mostrarEquipos(){
        Equipos obj;
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "rb");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        bool contenido=false;
        while(fread(&obj, sizeof(Equipos), 1, aEQ)==1){
            if(obj.getEstado()==true){
                obj.Mostrar();
                cout<<endl;
                contenido=true;
            }
        }
        fclose(aEQ);
        if(contenido==true){
            return true;
        }
        cout<<"No hay registros para listar."<<endl;
        return false;
    }

    ///4
    bool nombreEquipos(){
        Equipos obj;
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "rb+");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del equipo al que quiere modificar el nombre: "<<endl;
        cin>>ID;
        int pos=buscarIDequipo(ID);
        if(pos==-1){
            cout<<"La ID ingresada no fue encontrada en los registros."<<endl;
            fclose(aEQ);
            return false;
        }
        fseek(aEQ, sizeof(Equipos)*pos, 0);
        fread(&obj, sizeof(Equipos), 1, aEQ);
        char nombre[30];
        cout<<"Ingresar nombre que reemplazara al anterior: "<<endl;
        cargarCadena(nombre, 29);
        obj.setNombre(nombre);
        fseek(aEQ, sizeof(Equipos)*pos, 0);
        bool escribio=fwrite(&obj, sizeof(Equipos), 1, aEQ);
        fclose(aEQ);
        if(escribio==true){
            cout<<"Nombre modificado."<<endl;
            return true;
        }
        cout<<"Error al modificar el nombre."<<endl;
        return false;
    }

    ///5
    bool bajaLogica(){
        Equipos obj;
        FILE *aEQ;
        aEQ=fopen("equipos.dat", "rb+");
        if(aEQ==NULL){
            cout<<"Error de archivo."<<endl;
            return false;
        }
        int ID;
        cout<<"Ingresar ID del equipo al que quiere dar de baja: "<<endl;
        cin>>ID;
        int pos=buscarIDequipo(ID);
        if(pos==-1){
            cout<<"La ID ingresada no fue encontrada en los registros."<<endl;
            fclose(aEQ);
            return false;
        }
        fseek(aEQ, sizeof(Equipos)*pos, 0);
        fread(&obj, sizeof(Equipos), 1, aEQ);
        obj.setEstado(false);
        fseek(aEQ, sizeof(Equipos)*pos, 0);
        bool escribio=fwrite(&obj, sizeof(Equipos), 1, aEQ);
        fclose(aEQ);
        if(escribio==true){
            cout<<"Equipo dado de baja."<<endl;
            return true;
        }
        cout<<"Error al dar de baja el equipo."<<endl;
        return false;
    }

};

#endif // CLSARCHIVOEQUIPOS_H_INCLUDED
