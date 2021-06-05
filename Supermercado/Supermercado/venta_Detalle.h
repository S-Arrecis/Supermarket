#pragma once
#include <iostream>
#include <string>
#include"ConexionBD.h"
#include<mysql.h>

using namespace std;

class venta_Detalle{

	//private: int id_venta, id_producto;
	private: string cantidad, id_venta, id_producto,precio_unitario;
	//private: double precio_unitario;

	public: venta_Detalle() {

	}

	public: venta_Detalle(string _id_venta,string _id_producto, string _cantidad,string _precio_unitario) {

		id_venta = _id_venta;
		id_producto = _id_producto;
		cantidad = _cantidad;
		precio_unitario = _precio_unitario;
	}
	
		  void mostrar() {
			  cout <<"id venta xd: " <<id_venta << " ; " <<endl;
		  }

public: void insertar() {

    int q_estado;
    ConexionBD cn = ConexionBD();
   
    cn.abrir_conexion();
    if (cn.getConectar()) {

        string insert = " INSERT INTO db_super_mercado.ventas_detalle (idventa,idproducto,cantidad,precio_unitario) VALUES('" + id_venta + "','" + id_producto + "'," + cantidad + ",'" + precio_unitario + "');";
        const char* i = insert.c_str();
        //cout << "\n\n" << insert << endl;
        q_estado = mysql_query(cn.getConectar(), i);

        ///cout << insert << endl;
        system("pause");
        if (!q_estado) {
            cout << "Ingreso exitoso..." << endl;
        }
        else {
            cout << "\n\n\tcenta detalle: " << insert;
            cout << "error al ingresar..." << endl;
        }

    }
    else {
        cout << "Error en la conexión..." << endl;
    }
    cn.cerrar_conexion();
}

      void modificar(string id_venta,string id_producto,string cantidad,string precio_unitario) {

          int q_estado;
          ConexionBD cn = ConexionBD();

          cn.abrir_conexion();
          if (cn.getConectar()) {

              string insert = " update db_super_mercado.ventas_detalle set  idproducto =('" + id_producto + "'), cantidad = (" + cantidad + "),precio_unitario =('" + precio_unitario + "') where (idventas_detalle ='"+id_venta+"')";
              const char* i = insert.c_str();
              //cout << "\n\n" << insert << endl;
              q_estado = mysql_query(cn.getConectar(), i);

              ///cout << insert << endl;
              system("pause");
              if (!q_estado) {
                  cout << "modificacion exitosa..." << endl;
              }
              else {
                  cout << "\n\n\tcenta detalle: " << insert;
                  cout << "error al ingresar..." << endl;
              }

          }
          else {
              cout << "Error en la conexión..." << endl;
          }
          cn.cerrar_conexion();
      }

};

