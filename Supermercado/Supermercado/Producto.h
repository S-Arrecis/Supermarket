#pragma once
#include <iostream>

using namespace std;

class Producto{
	
private:
    string productos, descripcion, fecha_ingreso;

private:
    float precio_costo, precio_venta;

private:
    int id_marca, existencia;

public:
    Producto()
    {
    }

public:
    Producto(string _productos, int _id_marca, string _descripcion, float _precio_costo, float _precio_venta, int _existencia, string _fecha_ingreso)
    {

        productos = _productos;
        id_marca = _id_marca;
        descripcion = _descripcion;
        precio_costo = _precio_costo;
        precio_venta = _precio_venta;
        existencia = _existencia;
        fecha_ingreso = _fecha_ingreso;
    }

public: void set_Productos(string _productos) {
    productos = _productos;
}
public: void set_ID_marca(int _id) {
    id_marca = _id;
}
public: void set_Descripcioin(string _descripcion) {
    descripcion = _descripcion;
}

public: void set_Precio_costo(float _precio) {
    precio_costo = _precio;
}

public: void set_Precio_venta(float _precio_V) {
    precio_venta = _precio_V;
}

public: void set_Existencia(int _existencias) {
    existencia = _existencias;
}

public: void set_Fecha_Ingreso(string _Fecha) {
    fecha_ingreso = _Fecha;
}

      //Metodos Get

public: string get_Productos() {
    return productos;
}
public: int get_ID_marca() {
    return id_marca;
}
public: string get_Descripcioin() {
    return descripcion;
}

public: float get_Precio_costo() {
    return precio_costo;
}

public: float get_Precio_venta() {
    return precio_venta;
}

public: int get_Existencia() {
    return existencia;
}

public: string get_Fecha_Ingreso() {
    return fecha_ingreso;
}

public: void menu() {
    int opc;

    do {
        cout << "\n\t\t.:PRODUCTOS:.\n\n" << endl;
        cout << "1. Editar Producto." << endl;
        cout << "2. Eliminar Producto." << endl;
        cout << "3. Ver Producto." << endl;
        cout << "4. Insertar Producto." << endl;
        cout << "5.  <-----< Regresar." << endl;
        cout << "Digite un opcion: "; cin >> opc;

        switch (opc) {

        case 1:
            break;

        case 2:
            break;

        case 3:
            break;

        case 4:
            break;

        case 5: //llamamos al main para regresar
            break;
        default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
        }

    } while (opc != 5);
}

};

