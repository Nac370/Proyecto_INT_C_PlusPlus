#ifndef CLSJUGADORES_H_INCLUDED
#define CLSJUGADORES_H_INCLUDED



class Jugadores{
private:
    int DNI;
    char nombre[30], apellido[30], email[30], telefono[30];
    int claustro, deporte, nEquipo;
    Fecha fechaInscripcion;
    float matricula;
    bool estado;
    ArchivoDeportes obj;
    ArchivoEquipos obj1;
public:
    Jugadores(int dni=0, const char *n="nadie", const char *a="ninguno", const char *e="nada", const char *t="0000-0000", int dia=0, int mes=0, int anio=0, float m=0){
        DNI=dni;
        strcpy(nombre,n);
        strcpy(apellido,a);
        strcpy(email,e);
        strcpy(telefono,t);
        fechaInscripcion.setDia(dia);
        fechaInscripcion.setMes(mes);
        fechaInscripcion.setAnio(anio);
        matricula=m;
    }
    bool Cargar(int pos, int dni){
        DNI=dni;
        cout<<endl<<"Nombre: ";
        cargarCadena(nombre, 29);
        cout<<endl<<"Apellido: ";
        cargarCadena(apellido, 29);
        cout<<endl<<"Email: ";
        cargarCadena(email, 29);
        cout<<endl<<"Telefono: ";
        cargarCadena(telefono, 29);
        cout<<endl<<"Claustro: ";
        cin>>claustro;
        if(claustro<1 || claustro>4){
            cout<<"El claustro ingresado no es valido."<<endl;
            return 0;
        }
        cout<<endl<<"ID de deporte: ";
        cin>>deporte;
        if(deporte<1 || deporte>10){
            cout<<"La ID de deporte ingresada no es valida."<<endl;
            return 0;
        }

        int contErroresDeporte=0;
        ///Revisamos que exista la ID de deporte en el registro
        if(obj.buscarDeportesRegistroJugadores(deporte)==0){
            while(obj.buscarDeportesRegistroJugadores(deporte)==0){
                contErroresDeporte++;
                cout<<endl<<"La ID de deporte ingresada no se encuentra en el archivo de deportes."<<endl;
                cout<<"Por favor intentelo de nuevo."<<endl;
                cout<<endl<<"ID de deporte: "<<endl;
                cin>>deporte;
                if(contErroresDeporte==3){
                    cout<<endl<<"Ha introducido una ID no valida repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return 0;
                }
            }
        }

        cout<<endl<<"Numero de equipo: ";
        cin>>nEquipo;
        int contErroresEquipo=0;
        if(obj1.buscarIDequipo(nEquipo)==-1){
            while(obj1.buscarIDequipo(nEquipo)==-1){
                contErroresEquipo++;
                cout<<endl<<"La ID de equipo ingresada no se encuentra en el archivo de equipos."<<endl;
                cout<<"Por favor, intentelo de nuevo."<<endl;
                cout<<endl<<"Numero de equipo: "<<endl;
                cin>>nEquipo;
                if(contErroresEquipo==3){
                    cout<<endl<<"Ha introducido una ID no valida repetidas veces."<<endl;
                    cout<<"Por ende se cancelara la carga del registro."<<endl;
                    return 0;
                }
            }
        }


        cout<<endl<<"Fecha de inscripcion: "<<endl;
        if(fechaInscripcion.Cargar()==false){
            return 0;
        };
        cout<<endl<<"Matricula: ";
        cin>>matricula;
        if(matricula<0){
            cout<<"El valor de matricula ingresado no es valido."<<endl;
            return 0;
        }
        estado=true;
        return 1;
    }
    void Mostrar(){
        if(estado==true){
        cout<<"DNI: "<<DNI<<endl;
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Apellido: "<<apellido<<endl;
        cout<<"Email: "<<email<<endl;
        cout<<"Telefono: "<<telefono<<endl;
        cout<<"Claustro: "<<claustro<<endl;
        cout<<"ID de deporte: "<<deporte<<endl;
        cout<<"Numero de equipo: "<<nEquipo<<endl;
        cout<<"Fecha de inscripcion: "<<endl;
        fechaInscripcion.Mostrar();
        cout<<"Matricula: "<<matricula<<endl;
        }
    }
    ///Sets
    void setDNI(int dni){DNI=dni;}
    void setNombre(const char *n){
        strcpy(nombre, n);
    }
    void setApellido(const char *a){
        strcpy(apellido, a);
    }
    void setEmail(const char *em){strcpy(email, em);}
    void setTelefono(const char *t){
        strcpy(telefono, t);
    }
    void setClaustro(int c){claustro=c;}
    void setDeporte(int d){deporte=d;}
    void setNEquipo(int e){nEquipo=e;}
    void setFechaIns(Fecha f){fechaInscripcion=f;}
    void setMatricula(float m){matricula=m;}
    void setEstado(bool e){estado=e;}
    ///Gets
    int getDNI(){return DNI;}
    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    const char *getEmail(){return email;}
    const char *getTelefono(){return telefono;}
    int getClaustro(){return claustro;}
    int getDeporte(){return deporte;}
    int getNEquipo(){return nEquipo;}
    Fecha getFechaInscripcion(){return fechaInscripcion;}
    float getMatricula(){return matricula;}
    bool getEstado(){return estado;}

    ///Función de sobrecarga del operador == en la clase Jugadores.
    ///Compara la ID de deporte en el archivo Jugadores, con la ID en el archivo Deportes.
    /*bool operator==(Deportes &obj){
        if(getDeporte()==obj.getID_deporte())return true;
        return false;
    }*/

};

#endif // CLSJUGADORES_H_INCLUDED
