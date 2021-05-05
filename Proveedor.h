#include <iostream>
using namespace std;

class Proveedor{

    private: string Nombre_Proveedor,nit,direccion,telefono;

    public: Proveedor(){

    }

    public: Proveedor(string nombre,string _nit,string _direccion,string _telefono){
        Nombre_Proveedor = nombre;
        nit = _nit;
        direccion = _direccion;
        telefono = _telefono;
    }

    //metodos set

    public: void set_nombre_Proveedor(string nombres){
        Nombre_Proveedor = nombres;
    }

    public: void set_Nit(string _nit){
        nit =_nit;
    }
    public: void set_Direccion(string _direccion){
        direccion = _direccion;
    }
    public: void set_Telefono(string _telefono){
        telefono = _telefono;
    }
    //metodos get

    public: string get_Nombre_Proveedor(){
        return Nombre_Proveedor;
    }
    public: string get_Nit(){
        return nit;
    }
    public: string get_Direccion(){
        return direccion;
    }
    public: string get_Telefono(){
        return telefono;
    }

};