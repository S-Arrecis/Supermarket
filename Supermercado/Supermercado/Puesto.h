#include"ConexionBD.h"
#include<mysql.h>
#include <iostream>
using namespace std;

class Puesto{

private: string _puesto, ID;

public: Puesto() {

}
    Puesto(string puesto, string id) {
    _puesto = puesto;
	ID = id;
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
	  system("cls");
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
				  cout << fila[0]<<" "<< fila[1] << endl;
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
  void eliminar() {
	  int q_estado;
	  ConexionBD cn = ConexionBD();
	  cout << "\n-------------------------------------------------------------------" << endl;
	  cout << "\nIngrese la ID del cliente que desea eliminar: ";
	  cin >> ID;
	  cn.abrir_conexion();
	  if (cn.getConectar()) {
		  string update = "delete from db_super_mercado.puestos  where('" + ID + "')=idpuesto";
		  const char* i = update.c_str();
		  q_estado = mysql_query(cn.getConectar(), i);
		  if (!q_estado) {
			  cout << "Eliminacion exitosa..." << endl;
		  }
		  else {
			  cout << "Error al eliminar..." << endl;
		  }
	  }
	  else {
		  cout << "Error en la conexion..." << endl;
	  }cn.cerrar_conexion();
  }
  
  void actualizar() {
	  int q_estado;
	  ConexionBD cn = ConexionBD();

	  cout << "\n-------------------------------------------------------------------" << endl;
	  cout << "\nIngrese la ID del puesto que desea actualizar: ";
	  cin >> ID;
	  cout << endl;
	  cout << "-----------A continuacion ingrese los nuevos datos para reemplazar---------" << endl << endl;
	  cout << "Ingrese Nuevo Puesto: ";
	  cin >> puesto;

	  cn.abrir_conexion();
	  if (cn.getConectar()) {
		 
		  //system("pause");
		  string update = "update db_super_mercado.puestos set puesto = ('"+ _puesto +"')  where('" + ID + "')=idpuesto";
		  const char* i = update.c_str();
		  q_estado = mysql_query(cn.getConectar(), i);

		  if (!q_estado) {
			  cout << "Actualizacion exitosa..." << endl;
		  }
		  else {
			  cout << "Error al Actualizar..." << endl;
		  }
	  }
	  else {
		  cout << "Error en la conexion..." << endl;
	  }cn.cerrar_conexion();


  }






};

