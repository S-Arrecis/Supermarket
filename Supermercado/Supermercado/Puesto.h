#include"ConexionBD.h"
#include<mysql.h>
#include <iostream>
using namespace std;

class Puesto{

private: string _puesto;

public: Puesto() {

}
    Puesto(string puesto) {
    _puesto = puesto;
  
}

  void crear() {
          int q_estado;
          ConexionBD cn = ConexionBD();
          cn.abrir_conexion();
          if (cn.getConectar()) {
           

              string insert = "INSERT INTO puestos(puesto)VALUES('" + _puesto + "')";
              const char* i = insert.c_str();
              q_estado = mysql_query(cn.getConectar(), i);
              if (!q_estado) {
                  cout << "Ingreso exitoso..." << endl;
              }
              else {
                  cout << "error al ingresar..." << endl;
              }

          }
          else {
              cout << "Error en la conexión..." << endl;
          }
          cn.cerrar_conexion();

      }

  

  







};

