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
			string insert = "INSERT INTO clientes(nombres,apellidos,NIT,genero,telefono,correo_electronico,fecha_ingreso)  VALUES('" + nombres + "','" + apellidos + "','" + nit + "'," + GeneroBit + ",'" + telefono + "','" + correo + "'," + fecha_ingreso + ")";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout <<endl<< "Ingreso exitoso..." << endl;
				
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
		M = "Masculino";
		F = "Femenino";

		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string consulta = "SELECT *, if(genero=0,'" + M + "','" + F + "')  FROM clientes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				cout << "------------------------------Clietes------------------------------" << endl << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ", " << fila[1]<< ", " << fila[2]<< ", " << fila[3]<< ", " << fila[8]<<", " << fila[5] << ", " << fila[6]<< ", " << fila[7]<< endl;
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

	string buscarCliente(string nit_cliente) {
		string id;
		int q_estado;
		M = "Masculino";
		F = "Femenino";

		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string consulta = "SELECT *, if(genero=0,'" + M + "','" + F + "')  FROM clientes WHERE (NIT='"+nit_cliente+"')";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				cout << "\n------------------------------Clietes Encontrado------------------------------" << endl << endl;
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[1] << ", " << fila[2] << ", " << fila[3] << ", "  << fila[5] << ", " << fila[6] << endl;
					id = fila[0];
				}

				if (id == "") {
					id = "NULL";
				}
				
				return id;
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
			string update = "update db_super_mercado.clientes set  nombres=('" + nombres + "'),apellidos = ('" + apellidos + "'),NIT = ('" + nit + "'),genero =(" + GeneroBit + "),telefono =('" + telefono + "'),correo_electronico = ('" + correo + "'),fecha_ingreso = (" + fecha_ingreso + ")   where('" + ID + "')=idCliente";
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

