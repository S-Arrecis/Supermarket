#include"ConexionBD.h"
#include<mysql.h>
#include <iostream>
using namespace std;

class Proveedor{

private: string Nombre_Proveedor, nit, direccion, telefono, ID;

public: Proveedor() {

}

public: Proveedor(string nombre, string _nit, string _direccion, string _telefono, string id) {
    Nombre_Proveedor = nombre;
    nit = _nit;
    direccion = _direccion;
    telefono = _telefono;
	ID = id;
}
	  void crear() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {


			  string insert = "INSERT INTO proveedores(proveedores,nit,direccion,telefono) VALUES('" + Nombre_Proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
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

			  string consulta = "select * from proveedores";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());

				  cout << "------------------------------Proveedores------------------------------" << endl << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << " " << fila[1] << " " << fila[2] << " " << fila[3] << " " << fila[4] << endl;
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
		  string ID;
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cout << "\n-------------------------------------------------------------------" << endl;
		  cout << "\nIngrese la ID del proveedor que desea eliminar: ";
		  cin >> ID;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string update = "delete from db_super_mercado.proveedores  where('" + ID + "') = idproveedores";
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
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string update = "update db_super_mercado.proveedores set  proveedores = ('" + Nombre_Proveedor + "'),nit = ('" + nit + "'),direccion = ('" + direccion + "'),telefono = ('" + telefono + "')  where('" + ID + "')=idproveedores";
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

