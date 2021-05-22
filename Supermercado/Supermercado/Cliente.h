#include"ConexionBD.h"
#include<mysql.h>
#include "Persona.h"
class Cliente : public Persona{
private: string nit, correo, ID;

public: Cliente() {

}

public:
    Cliente(string _nombres, string _apellidos, string _telefono, string _fecha_ingreso, char _genero, string _nit, string _correo, string id) :Persona(_nombres, _apellidos, _telefono, _fecha_ingreso, _genero) {

        nit = _nit;
        correo = _correo;
		ID = id;

    }


  

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {


			string insert = "INSERT INTO clientes(nombres,apellidos,NIT,genero,telefono,correo_electronico,fecha_ingreso)  VALUES('" + nombres + "','" + apellidos + "','" + nit + "','" + genero + "','" + telefono + "','" + correo + "','" + fecha_ingreso + "')";
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
			cout << "Error en la conexi�n..." << endl;
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

			string consulta = "select * from clientes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				cout << "------------------------------Clietes------------------------------" << endl << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " " << fila[1]<< " " << fila[2]<< " " << fila[3]<< " " << fila[4]<<" " << fila[5] << " " << fila[6]<< " " << fila[7]<< endl;
				}

			}
			else {
				cout << "error al consultar..." << endl;
			}
		}
		else {
			cout << "Error en la conexi�n..." << endl;
		}
		cn.cerrar_conexion();
	}
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string update = "delete from db_super_mercado.clientes  where('" + ID + "')=idCliente";
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

			string update = "update db_super_mercado.clientes set  nombres=('" + nombres + "'),apellidos = ('" + apellidos + "'),NIT = ('" + nit + "'),genero =('" + genero + "'),telefono =('" + telefono + "'),correo_electronico = ('" + correo + "'),fecha_ingreso = ('" + fecha_ingreso + "')   where('" + ID + "')=idCliente";
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

