#ifndef CLSARCHIVOJUGADORES_H_INCLUDED
#define CLSARCHIVOJUGADORES_H_INCLUDED



class ArchivoJugadores{
private:
    Jugadores obj;
public:

    int buscarDNI(int dni){
        Jugadores obj;
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat","rb");
        if(aJUJ==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -3;
        }
        int posRegistro=-1;
        while(fread(&obj,sizeof(Jugadores),1,aJUJ)==1){
            posRegistro++;
            if(obj.getDNI()==dni){
                if(obj.getEstado()==true){
                    fclose(aJUJ);
                    return posRegistro;
                }
                fclose(aJUJ);
                return -2;
            }
        }
        fclose(aJUJ);
        return -1;
    }

    ///1)
    bool cargarJugador(){
        Jugadores obj;
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "ab");
        if(aJUJ==NULL){
            cout<<"Error de archivo";
            return false;
        }
        int dni;
        cout<<"Ingresar DNI: ";
        cin>>dni;
        cout<<endl;
        int pos=buscarDNI(dni);
        if(pos==-1){
            if(obj.Cargar(pos, dni)==true){
                bool escribio=fwrite(&obj, sizeof(Jugadores), 1, aJUJ);
                fclose(aJUJ);
                return escribio;
            }
            else cout<<"No se pudo agregar el jugador, intentelo de nuevo."<<endl;
            return false;
        }
        if(pos==-2){
            cout<<"El DNI ingresado ya existe pero fue dado de baja."<<endl;
            fclose(aJUJ);
            return false;
        }
        cout<<"El DNI ingresado ya existe en los registros."<<endl;
        fclose(aJUJ);
        return false;
    }

    int contarJugadores(){
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "rb");
        if(aJUJ==NULL) return -1;
        fseek(aJUJ, 0,2);
        int tam=ftell(aJUJ);
        fclose(aJUJ);
        return tam/sizeof(Jugadores);
    }
    Jugadores leerJugador(int pos){
		Jugadores obj;
        obj.setDNI(-1);
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat","rb");
        if(aJUJ==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return obj;
        }
        fseek(aJUJ,sizeof obj*pos,0);

        int leyo=fread(&obj,sizeof(Jugadores),1,aJUJ);
        fclose(aJUJ);

        if(leyo==0) obj.setDNI(-1);
        return obj;
    }
    int modificarJugadores(int pos){
        Jugadores obj;
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat","rb");
        if(aJUJ==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -1;
        }
        fseek(aJUJ,sizeof obj*pos,0);
        bool escribio=fwrite(&obj,sizeof(Jugadores),1,aJUJ);
        fclose(aJUJ);
        return escribio;
    }

    ///2
    int listarJugadorDNI(){
        int dni;
        cout<<"Ingresar DNI del jugador que quiere listar: ";
        cin>>dni;
        cout<<endl;
        bool encontrado=0;
        Jugadores obj;
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "rb");
        if(aJUJ==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof(Jugadores), 1, aJUJ)==1){
            if(obj.getDNI()==dni){
                if(obj.getEstado()==true){
                obj.Mostrar();
                encontrado=1;
                return encontrado;
                }
            }
        }
        fclose(aJUJ);
        return encontrado;
    }
    ///3
    int listarJugadores(){
        bool hayQUEmostrar=0;
        Jugadores obj;
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "rb");
        if(aJUJ==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
        }
        while(fread(&obj, sizeof(Jugadores), 1, aJUJ)==1){
                obj.Mostrar();
                hayQUEmostrar=1;
                cout<<endl<<endl;
        }
        fclose(aJUJ);
        return hayQUEmostrar;
    }
    ///4 MODIFICAR FECHA DE INSCRIPCION
    int modificarFechaInscripcion(){
        Jugadores obj;
        int dni;
        cout<<"Ingresar DNI del jugador: ";
        cin>>dni;
        cout<<endl;
        int pos=buscarDNI(dni);
        if(pos==-1){
            return 0;
        }
        else{
            int posCAMBIO=0;
            bool encontrado=0;
            FILE *aJUJ;
            aJUJ=fopen("Jugadores.dat","rb+");
            if(aJUJ==NULL){
            cout<<"Error al leer el archivo"<<endl;
            return -1;
            }
            while(fread(&obj, sizeof(Jugadores), 1, aJUJ)==1){
                if(obj.getDNI()==dni){
                    if(obj.getEstado()==true){
                    encontrado=1;
                    cout<<"Ingresar nueva fecha de inscripcion: "<<endl;
                    Fecha objNuevo;
                    objNuevo.Cargar();
                    obj.setFechaIns(objNuevo);
                    fseek(aJUJ,sizeof obj*pos,0);
                    bool escribio=fwrite(&obj, sizeof(Jugadores), 1, aJUJ);
                    if(escribio==1){
                        cout<<"Fecha modificada."<<endl;
                        fclose(aJUJ);
                        return 1;
                    }
                    else cout<<"Error al escribir el archivo"<<endl;
                    fclose(aJUJ);
                    return -1;
                    }
                }
                posCAMBIO++;
            }
            if(encontrado==0){
                fclose(aJUJ);
                return 0;
            }
        }
    return 0;
    }

    ///Modificar Jugador(para dar de baja)
    bool modificarJugador(Jugadores obj, int pos){
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat","rb+");
        if(aJUJ==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return false;
        }
        fseek(aJUJ,sizeof obj*pos,0);
        bool escribio=fwrite(&obj,sizeof(Jugadores),1,aJUJ);
        fclose(aJUJ);
        return escribio;
    }

    ///5 BAJA LOGICA
    bool bajaLogica(){
        FILE *aJUJ;
        aJUJ=fopen("Jugadores.dat", "rb");
        if(aJUJ==NULL){
            cout<<"Error al abrir el archivo."<<endl;
            return 0;
        }
        int dni;
        cout<<"Ingresar DNI del jugador que quiera dar de baja: ";
        cin>>dni;
        cout<<endl;

        int pos=buscarDNI(dni);
        if(pos==-1){
            cout<<"El jugador no fue encontrado."<<endl;
            return 0;
        }
        Jugadores obj;
        obj=leerJugador(pos);
        if(obj.getDNI()==-1){
            cout<<"No existe el jugador."<<endl;
            return 0;
        }
        obj.setEstado(false);
        bool quepaso=modificarJugador(obj,pos);
        return quepaso;
    }
};

#endif // CLSARCHIVOJUGADORES_H_INCLUDED
