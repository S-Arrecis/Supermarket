#pragma once
#include "Persona.h"
class Empleado : public Persona{

private: string dpi, fecha_nacimiento, fecha_inicio_labores;
private: int id_puesto;

       //Constructores
public: Empleado() : Persona() {

}

public: Empleado(string _nombres, string _apellidos, string _telefono, string _fecha_ingreso, char _genero, string _dpi, string _fecha_nacimiento, string _fecha_inicio_labores, int _id_puesto) :Persona(_nombres, _apellidos, _telefono, _fecha_ingreso, _genero) {
    dpi = _dpi;
    fecha_nacimiento = _fecha_nacimiento;
    fecha_inicio_labores = _fecha_inicio_labores;
    id_puesto = _id_puesto;
}
      //Metodos

      //set (modificamos los datos almacenados en las varibles)
      void set_dpi(string _dpi) {
          dpi = _dpi;
      }

      void set_fecha_nacimiento(string _fecha_nacimiento) {
          fecha_nacimiento = _fecha_nacimiento;
      }

      void set_fecha_inicio_labores(string _fecha_inicio_labores) {
          fecha_inicio_labores = _fecha_inicio_labores;
      }

      void set_id_puesto(int _id_puesto) {
          id_puesto = _id_puesto;
      }

      //get (mostramos los datos almacenados en las variables)
      string get_dpi() {
          return dpi;
      }

      string get_fecha_nacimiento() {
          return fecha_nacimiento;
      }

      string get_fecha_incio_labores() {
          return fecha_inicio_labores;
      }

      int get_id_puesto() {
          return id_puesto;
      }

public: void menu() {
    int opc;

    do {
        cout << "\n\t\t.:EMPLEADO:.\n\n" << endl;
        cout << "1. Editar Empleado." << endl;
        cout << "2. Eliminar Empleado." << endl;
        cout << "3. Ver Empleado." << endl;
        cout << "4. Insertar Empleado." << endl;
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

