#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

int diasXmes(int dia, int mes, int anio);

class FechaActual{
private:
    time_t tiempo=time(NULL);
    struct tm *tmPtr = localtime(&tiempo);
public:
    ///tmPtr = localtime(&tiempo);

    int getDia(){return tmPtr->tm_mday;}
    int getMes(){return tmPtr->tm_mon+1;}
    int getAnio(){return 1900+tmPtr->tm_year;}
};

class Fecha{
    private:
        int dia, mes, anio;
        FechaActual obj;
    public:
        bool Cargar(){
            cout<<"DIA: ";
            cin>>dia;
            cout<<"MES: ";
            cin>>mes;
            cout<<"ANIO: ";
            cin>>anio;

            ///Comparación con fecha actual
            if(anio>obj.getAnio()){
                cout<<"El anio introducido no es valido."<<endl;
                return false;
            }
            if(anio==obj.getAnio() && mes>obj.getMes()){
                cout<<"El mes introducido no es valido."<<endl;
                return false;
            }
            if(anio==obj.getAnio() && mes==obj.getMes() && dia>obj.getDia()){
                cout<<"El dia introducido no es valido."<<endl;
                return false;
            }

            ///Analizo los días mes x mes
            if(diasXmes(dia, mes, anio)==1){
                return true;
            }
            else return false;
        }
        void Mostrar(){
            cout<<"DIA: "<<dia<<endl;
            cout<<"MES: "<<mes<<endl;
            cout<<"ANIO: "<<anio<<endl;
        }
        void mostrarEnLinea(){
            cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
        }
        ///Sets
        void setDia(int d){
            if(d>=1 && d<=31) dia=d;
            else dia=-1;
        }
        void setMes(int m){
            if(m>=1 && m<=12) mes=m;
            else mes=-1;
        }
        void setAnio(int a){
            if(a>0) anio=a;
            else anio=-1;
        }
        ///Gets
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};

bool esBisiesto(int anio){
    if(anio%400==0){
        return true;
    }
    if(anio%4==0 && anio%100!=0){
        return true;
    }
    return false;
}

int diasXmes(int dia, int mes, int anio){
    if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12){
        if(dia>=1 && dia<=31){
            return 1;
        }
        else return 0;
    }
    if(mes==4 || mes==6 || mes==9 || mes==11){
        if(dia>=1 && dia<=30){
            return 1;
        }
        else return 0;
    }
    else if(esBisiesto(anio)==true){
        if(dia>=1 && dia<=29){
            return 1;
        }
        else return 0;
        }
    else if(dia>=1 && dia<=28){
            return 1;
        }
    else return 0;
}


#endif // CLSFECHA_H_INCLUDED
