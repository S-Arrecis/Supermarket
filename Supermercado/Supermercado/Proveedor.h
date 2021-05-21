#pragma once
#include <iostream>
using namespace std;

class Proveedor{

private: string Nombre_Proveedor, nit, direccion, telefono;

public: Proveedor() {

}

public: Proveedor(string nombre, string _nit, string _direccion, string _telefono) {
    Nombre_Proveedor = nombre;
    nit = _nit;
    direccion = _direccion;
    telefono = _telefono;
}

      //metodos set

public: void set_nombre_Proveedor(string nombres) {
    Nombre_Proveedor = nombres;
}

public: void set_Nit(string _nit) {
    nit = _nit;
}
public: void set_Direccion(string _direccion) {
    direccion = _direccion;
}
public: void set_Telefono(string _telefono) {
    telefono = _telefono;
}
      //metodos get

public: string get_Nombre_Proveedor() {
    return Nombre_Proveedor;
}
public: string get_Nit() {
    return nit;
}
public: string get_Direccion() {
    return direccion;
}
public: string get_Telefono() {
    return telefono;
}

public: void menu() {
    int opc;

    do {
        cout << "\n\t\t.:PROVEEDORES:.\n\n" << endl;
        cout << "1. Editar Proveedor." << endl;
        cout << "2. Eliminar Proveedor." << endl;
        cout << "3. Ver Proveedor." << endl;
        cout << "4. Insertar Proveedor." << endl;
        cout << "5.  <-----< Regresar." << endl;
        cout << "Digite un opcion: "; cin >> opc;

        switch (opc) {
        case 1: break;
        case 2: break;
        case 3: break;
        case 4: break;
        case 5: break;
        default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
        }

    } while (opc != 4);
}

};

