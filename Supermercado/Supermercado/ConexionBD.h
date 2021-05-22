#pragma once
#include<mysql.h>
#include <iostream>

using namespace std;
class ConexionBD
{
private : MYSQL* conectar;
public: 
	void abrir_conexion(){
	
		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_super_mercado", 3306, NULL, 0);
			
	}

	void primera_conexion() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "root", "12345678", "db_super_mercado", 3306, NULL, 0);
		if (conectar) {
			system("color 02");
			cout << "\n\n\t\tConexion exitosa...\n\n" << endl;
			system("pause");
		}

		else {
			system("color 0c");
			cout << "\n\n\t\tError al realizar la conexion..\n\n" << endl;
			system("pause");
		}

	}

	MYSQL* getConectar() {
		return conectar;

	}
	void cerrar_conexion(){
		mysql_close(conectar);
	
	}
	



};

