#pragma once
#include <iostream>
#include <string>
#include"ConexionBD.h"
#include<mysql.h>

using namespace std;

class Venta{
    

	private:
		string fecha_factura, fecha_ingreso,No_factura, id_cliente, id_empleado, serie,dato, num, numF;

	public: Venta() {

	}
public: Venta(string _No_factura, string _serie,string _fechaF,string _id_cliente, string _id_empleado,string fechaI) {
	No_factura = _No_factura;
    serie = _serie;
    fecha_factura = _fechaF;
	id_cliente = _id_cliente;
	id_empleado = _id_empleado;
    fecha_ingreso = fechaI;
}

public: void insertar() {

          int q_estado;
          ConexionBD cn = ConexionBD();
          fecha_factura = "now()";
          fecha_ingreso = "now()";
          cn.abrir_conexion();
          if (cn.getConectar()) {

              string insert = " INSERT INTO db_super_mercado.ventas (nofactura,serie,fechafactura,idcliente,idempleado,fecha_ingreso) VALUES('" + No_factura + "','" + serie + "'," + fecha_factura  +",'" + id_cliente + "','" + id_empleado + "'," + fecha_ingreso + ");";
              const char* i = insert.c_str();
             
              q_estado = mysql_query(cn.getConectar(), i);

              ///cout << insert << endl;
              system("pause");
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

      string ver() {
          
          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {

              string consulta = "select * from ventas";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());

                 // cout << "------------------------------Productos------------------------------\n" << endl;
                  while (fila = mysql_fetch_row(resultado)) {
                      //cout << fila[0] << ", " << fila[1] << endl;
                      num = fila[0];
                  }
                  return num;
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
     
      string factura() {

          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {

              string consulta = "select * from ventas";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());

                  // cout << "------------------------------Productos------------------------------\n" << endl;
                  while (fila = mysql_fetch_row(resultado)) {
                      //cout << fila[0] << ", " << fila[1] << endl;
                      numF = fila[1];
                  }
                  return numF;
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

