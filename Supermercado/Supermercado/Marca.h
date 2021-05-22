#pragma once
#include <iostream>
#include"ConexionBD.h"
#include<mysql.h>
using namespace std;

class Marca{

    //private: int id;
private: string marca;
       //Metodos COnstructores
public: Marca() {

}

public: Marca(string _marca) {
    marca = _marca;
}
      //metodos set
public: void set_Marca(string _marca) {
    marca = _marca;
}
      //metodos get
public: string get_Marca() {
    return marca;
}

public: void insertar() {
       
     int q_estado;
     ConexionBD cn = ConexionBD();
     cn.abrir_conexion();
     if (cn.getConectar()) {


         string insert = "INSERT INTO marcas(marca)VALUES('" + marca + "')";
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

      void consultar() {

          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {

              string consulta = "select * from marcas";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());

                  cout << "------------------------------Marcas------------------------------\n" << endl;
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << fila[0] << ", " << fila[1] << endl;


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

      void ver() {

          int q_estado;
          ConexionBD cn = ConexionBD();
          MYSQL_ROW fila;
          MYSQL_RES* resultado;
          cn.abrir_conexion();
          if (cn.getConectar()) {

              string consulta = "select * from marcas";
              const char* c = consulta.c_str();
              q_estado = mysql_query(cn.getConectar(), c);
              if (!q_estado) {
                  resultado = mysql_store_result(cn.getConectar());

                  cout << "\t\t------------------------------Identifica la Marca a Eliminar---------------------------\n" << endl;
                  while (fila = mysql_fetch_row(resultado)) {
                      cout << fila[0] << ", " << fila[1] << endl;


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
          ver();
          //cout << "\n------------------------------Eliminar Marcas------------------------------\n" << endl;
          string id;
          cout << "\n\nDigite el ID de la marca que desea eliminar: "; cin >> id;
          cn.abrir_conexion();
          
          if (cn.getConectar()) {
              string  insertar = "DELETE FROM marcas  WHERE (idmarcas = '" + id + "')";
              const char* i = insertar.c_str();
              // executar el query
              q_estado = mysql_query(cn.getConectar(), i);
              if (!q_estado) {
                  cout << "Eliminacion  Exitosa ..." << endl;
              }
              else {
                  cout << " xxx Error al Eliminar  xxx" << endl;
              }
          }
          else {
              cout << " xxx Error en la Conexion xxxx" << endl;
          }
          cn.cerrar_conexion();

      }

};

