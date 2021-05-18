#include <iostream>

using namespace std;

class Puesto{

    private : string puesto;

    public : Puesto(){

    }
    public: Puesto(string _puesto){
        puesto = _puesto;
    }


    void set_Puesto(string _puesto){
        puesto = _puesto;
    }
    
    string get_Puesto(){
        return puesto;
    }

    public: void menu(){
        int opc;

        do{
            cout<<"\n\t\t.:PUESTOS:.\n\n"<<endl;
            cout<<"1. Editar Puesto."<<endl;
            cout<<"2. Eliminar Puesto."<<endl;
            cout<<"3. Ver Puesto."<<endl;
            cout<<"4. Insertar Puesto."<<endl;
            cout<<"5.  <-----< Regresar."<<endl;
            cout<<"Digite un opcion: "; cin>> opc;

            switch(opc){
                case 1: break;
                case 2: break;
                case 3: break;
                case 4: break;
                case 5: break;
                default: cout<<" (TwT) Opcion no valida intenta otra vez.. (TwT)"<<endl; 
            }

        }while(opc!=5);
    }
};
