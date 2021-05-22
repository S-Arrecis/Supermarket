#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include"ConexionBD.h"
#include<mysql.h>

using namespace std;

class Producto{
	
private:
    string productos, descripcion, fecha_ingreso, precio_costo, precio_venta, id_marca, existencia;



public:
    Producto()
    {
    }

public:
    Producto(string _productos, string _id_marca, string _descripcion, string _precio_costo, string _precio_venta, string _existencia, string _fecha_ingreso)
    {

        productos = _productos;
        id_marca = _id_marca;
        descripcion = _descripcion;
        precio_costo = _precio_costo;
        precio_venta = _precio_venta;
        existencia = _existencia;
        fecha_ingreso = _fecha_ingreso;
    }

public: void set_Productos(string _productos) {
    productos = _productos;
}
public: void set_ID_marca(int _id) {
    id_marca = _id;
}
public: void set_Descripcioin(string _descripcion) {
    descripcion = _descripcion;
}

public: void set_Precio_costo(float _precio) {
    precio_costo = _precio;
}

public: void set_Precio_venta(float _precio_V) {
    precio_venta = _precio_V;
}

public: void set_Existencia(int _existencias) {
    existencia = _existencias;
}

public: void set_Fecha_Ingreso(string _Fecha) {
    fecha_ingreso = _Fecha;
}

      //Metodos Get

public: string get_Productos() {
    return productos;
}
public: string get_ID_marca() {
    return id_marca;
}
public: string get_Descripcioin() {
    return descripcion;
}

public: string get_Precio_costo() {
    return precio_costo;
}

public: string get_Precio_venta() {
    return precio_venta;
}

public: string get_Existencia() {
    return existencia;
}

public: string get_Fecha_Ingreso() {
    return fecha_ingreso;
}


 void insertar() {
     
     int q_estado;
     ConexionBD cn = ConexionBD();
       cn.abrir_conexion();
     if (cn.getConectar()) {

         string insert = "INSERT INTO `db_super_mercado`.`productos` (`producto`, `idmarca`, `descripcion`, `|precio_costo`, `precio_venta`, `existencia`, `fehca_ingreso`) VALUES('" + productos + "','"+id_marca+"','" + descripcion + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "'  )";
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

 void consultar() {

     int q_estado;
     ConexionBD cn = ConexionBD();
     MYSQL_ROW fila;
     MYSQL_RES* resultado;
     cn.abrir_conexion();
     if (cn.getConectar()) {

         string consulta = "select * from productos";
         const char* c = consulta.c_str();
         q_estado = mysql_query(cn.getConectar(), c);
         if (!q_estado) {
             resultado = mysql_store_result(cn.getConectar());

             cout << "------------------------------Productos------------------------------\n" << endl;
             while (fila = mysql_fetch_row(resultado)) {
                 cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[5] << ", " << fila[6] << ", " << fila[7] << ", " << fila[8] << endl;
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

         string consulta = "select * from productos";
         const char* c = consulta.c_str();
         q_estado = mysql_query(cn.getConectar(), c);
         if (!q_estado) {
             resultado = mysql_store_result(cn.getConectar());

             cout << "------------------------------Productos------------------------------\n" << endl;
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
     cout << "\n\t\t------------------------------Eliminar Productos------------------------------\n" << endl;
     string id;
     cout << "\n\nDigite el ID del Producto que desea eliminar: "; cin >> id;
     cn.abrir_conexion();

     if (cn.getConectar()) {
         string  insertar = "DELETE FROM productos  WHERE (idproductos = '" + id + "')";
         const char* i = insertar.c_str();
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
 //
 void modificar() {
     ConexionBD cn = ConexionBD();
     
     int q_estado;
     string producto, id_marca, descripcion, precio_costo, precio_venta, existencia, fecha, dato_antiguo;
     cn.abrir_conexion();
     ver();
     cout << "\n\n\t\t.:Modificar Producto:. \n\n" << endl;
     cout << "\nDigite el ID del producto a modificar: ";
     cin >> dato_antiguo;
     cin.ignore();
     cout << "Ingrese Nombre del producto: ";
     getline(cin, producto);
     fflush(stdin);
     cout << "Ingresse el ID de la Marca: ";
     cin >> id_marca;
     fflush(stdin);
     fflush(stdin);
     cin.ignore();
     cout << "Ingrese la descripcion: ";
     getline(cin, descripcion);
     fflush(stdin);
     fflush(stdin);
     cout << "Digita el Precio de compra del producto: ";
     cin >> precio_costo;
     fflush(stdin);
     cout << "Digita el precio de venta del producto: ";
     cin >> precio_venta;
     fflush(stdin);
     fflush(stdin);
     cout << "Digita cuantas existencias hay de este producto: ";
     cin >> existencia;
     fflush(stdin);
     fflush(stdin);
     fecha = "now()";

     string consulta = "UPDATE `db_super_mercado`.`productos` SET `producto` = '" + producto + "' , `idmarca` =  '" + id_marca + "',`descripcion`= '" + descripcion + "',`|precio_costo` = '" + precio_costo + "',  `precio_venta` = '" + precio_venta + "', `existencia` = '" + existencia + "',`fehca_ingreso`="+fecha+" WHERE (`idproductos` = '" + dato_antiguo + "')";

  
     const char* insertar = consulta.c_str();
     q_estado = mysql_query(cn.getConectar(), insertar);

     if (!q_estado) {

         cout << "\n\n\t\tDatos agregados con exito...\n\n" << endl;
     }
     else {
         cout << "\n\n\t\tError al agregar los datos..\n\n" << endl;

     }

 }

};

