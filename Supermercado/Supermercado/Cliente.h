#pragma once
#include "Persona.h"
class Cliente : public Persona{
private: string nit, correo;

public: Cliente() {

}

public:
    Cliente(string _nombres, string _apellidos, string _telefono, string _fecha_ingreso, char _genero, string _nit, string _correo) :Persona(_nombres, _apellidos, _telefono, _fecha_ingreso, _genero) {

        nit = _nit;
        correo = _correo;
    }

    void set_Nit(string _nit) {
        nit = _nit;
    }

    void set_Correo(string _correo) {
        correo = _correo;
    }
    //creado metodos get de la clase Cliente

    string get_Nit() {
        return nit;
    }
    string get_Correo() {
        return correo;
    }

public: void menu() {
    int opc;

    do {
        cout << "\n\t\t.:CLIENTES:.\n\n" << endl;
        cout << "1. Editar Cliente." << endl;
        cout << "2. Eliminar Cliente." << endl;
        cout << "3. Ver Cliente." << endl;
        cout << "4. Insertar Cliente." << endl;
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

