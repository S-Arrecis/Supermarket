#include"ConexionBD.h"
#include<mysql.h>
#include "Persona.h"
class Empleado : public Persona{

private: string direccion, fecha_nacimiento, fecha_inicio_labores;
private: string id_puesto, ID;

       //Constructores
public: Empleado() : Persona() {

}

public: Empleado(string _nombres, string _apellidos, string _telefono, string _fecha_ingreso, char _genero, string _direccion, string _fecha_nacimiento, string _fecha_inicio_labores, string _id_puesto, string id) :Persona(_nombres, _apellidos, _telefono, _fecha_ingreso, _genero) {
	direccion = _direccion;
	fecha_nacimiento = _fecha_nacimiento;
	fecha_inicio_labores = _fecha_inicio_labores;
	id_puesto = _id_puesto;
	ID = id;
}
	  string M, F, GeneroBit;
	  bool Bit;
	  void crear() {

		  int q_estado;
		  if (genero == 'M' || 'm') {
			  GeneroBit = '0';
		  }
		  else
		  {
			  GeneroBit = '1';
		  }

		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  fecha_ingreso = "now()";
			  string insert = "INSERT INTO empleados(nombres,apellidos,direccion,telefono,genero,fecha_nacimiento,idpuesto,fecha_inicio_labores,fecha_ingreso)  VALUES('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "'," + GeneroBit + ",'" + fecha_nacimiento + "','" + id_puesto + "','" + fecha_inicio_labores + "'," + fecha_ingreso + ")";
			  const char* i = insert.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				  cout << endl << "Ingreso exitoso..." << endl;

			  }
			  else {
				  cout << "error al ingresar..." << endl;
			  }

		  }
		  else {
			  cout << "Error en la conexi?n..." << endl;
		  }
		  cn.cerrar_conexion();

	  }
	 
	  void leer() {
		  system("cls");
		  int q_estado;
		  M = "Masculino";
		  F = "Femenino";

		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "SELECT idEmpleado,nombres,apellidos,direccion,telefono,genero,fecha_nacimiento,puesto,fecha_inicio_labores,fecha_ingreso,if(genero=0,'" + M + "','" + F + "')  FROM db_super_mercado.empleados INNER JOIN  db_super_mercado.puestos ON empleados.idpuesto = puestos.idpuesto;";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());

				  cout << "------------------------------Clietes------------------------------" << endl << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[10] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << ", " << fila[9]<< endl;
				  }

			  }
			  else {
				  cout << "error al consultar..." << endl;
			  }
		  }
		  else {
			  cout << "Error en la conexi?n..." << endl;
		  }
		  cn.cerrar_conexion();
	  }
	  
	  void eliminar() {
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  string update = "delete from db_super_mercado.empleados  where('" + ID + "')=idEmpleado";
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
		  if ((genero == 'M') || (genero == 'm')) {
			  GeneroBit = '0';
		  }
		  else
		  {
			  GeneroBit = '1';
		  }
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cn.abrir_conexion();
		  if (cn.getConectar()) {
			  fecha_ingreso = "now()";
			  string update = "update db_super_mercado.empleados set  nombres=('" + nombres + "'),apellidos = ('" + apellidos + "'), direccion = ('" + direccion + "'),telefono =('" + telefono + "'),genero =(" + GeneroBit + "),fecha_nacimiento = ('" + fecha_nacimiento + "'),idpuesto = ('" + id_puesto + "'),fecha_inicio_labores = ('" + fecha_inicio_labores + "') ,fecha_ingreso = (" + fecha_ingreso + ")  where('" + ID + "')=idEmpleado";
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

