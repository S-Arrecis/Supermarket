#include <iostream>
using namespace std;

class Marca{

    //private: int id;
    private: string marca;
    //Metodos COnstructores
    public: Marca(){

    }

    public: Marca(string _marca){
        marca = _marca;
    }
    //metodos set
    public: void set_Marca(string _marca){
        marca = _marca;
    }
    //metodos get
    public: string get_Marca(){
        return marca;
    }

    public: void menu(){
        int opc;

        do{
            cout<<"\n\t\t.:EDITAR MARCA:.\n\n"<<endl;
            cout<<"1. Editar Marca."<<endl;
            cout<<"2. Eliminar Marca."<<endl;
            cout<<"3. Ver Marcas."<<endl;
            cout<<"4.  <-----< Regresar."<<endl;
            cout<<"Digite un opcion: "; cin>> opc;

            switch(opc){
                case 1: 
                break;
                
                case 2: 
                break;
                
                case 3: 
                break;
                
                case 4: //madamos a llamar al main o bien ejecutnado de nuevo
                break;
                
                default: cout<<" (TwT) Opcion no valida intenta otra vez.. (TwT)"<<endl; 
            }

        }while(opc!=4);
    }
    
};