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

  
  void leer() {
	  int q_estado;
	  ConexionBD cn = ConexionBD();
	  MYSQL_ROW fila;
	  MYSQL_RES* resultado;
	  cn.abrir_conexion();
	  if (cn.getConectar()) {

		  string consulta = "select * from puestos";
		  const char* c = consulta.c_str();
		  q_estado = mysql_query(cn.getConectar(), c);
		  if (!q_estado) {
			  resultado = mysql_store_result(cn.getConectar());

			  cout << "------------------------------Clietes------------------------------" << endl << endl;
			  while (fila = mysql_fetch_row(resultado)) {
				  cout << fila[0] << endl;


			  }

		  }
		  else {
			  cout << "error al consultar..." << endl;
		  }





	  }
	  else {
		  cout << "Error en la conexión..." << endl;
	  }
	  cn.cerrar_conexion();
  }

  







};

