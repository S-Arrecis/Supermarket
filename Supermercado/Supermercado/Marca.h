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

};

