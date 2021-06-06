#pragma once
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include"ConexionBD.h"
#include<mysql.h>
#include "Venta.h"
#include "venta_Detalle.h"
#include <fstream>
#include <iomanip>
#include"Impresion.h"


using namespace std;
ofstream imp("factura.txt");
char resp;
typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;
class crear_factura {



private:
	char serie;
private:
	string fecha_factura, fecha_ingreso, cantidad, id, No_factura, nit_cliente, id_empleado, venta, id_producto, SERIE, precio, buscar;
private: float precio_unitario;

	   // char* No_Factura;
public: crear_factura() {

}


public: void ingresar_datos(string id_cliente, string id_empleado) {
	system("cls");
	/*
	cout << "\n\t\t.:DATOS DE FACTURACION:. \n\n";
	//cout << "Digite el id venta: "; cin >> id;
	//cin.ignore();
	//cout << "Digite la Serie: "; cin >> SERIE;

	cout << "Digite el Nit del Cliente: "; cin >> nit_cliente;

	cout << "\nDite el ID del Empleado: "; cin >> id_empleado;*/

	Venta v1 = Venta();
	No_factura = v1.factura();
	int aux = atoi(No_factura.c_str());
	aux += 1;

	No_factura = to_string(aux);
	v1 = Venta(No_factura, "A", fecha_factura, id_cliente, id_empleado, fecha_ingreso);
	v1.insertar();
	id = v1.ver();
	//insertar_Venta_Detalle();
	/*
	cout << "\n\t\t.:VENTA DETALLE:.\n" << endl;
	cout << "ingresa ID producto: "; cin >> id_producto;
	cout << "ingrese cantidad: "; cin >> cantidad;
	cout << "digite precio: "; cin >> precio;

	venta_Detalle v2 = venta_Detalle(id, id_producto, cantidad,precio);
	v2.insertar();
	cout << "\n\n";
	system("pause");*/
}
	  void insertar_Venta_Detalle(string id_factura, string id_producto, string cantidad, string precio) {

		  //cout << "\n\t\t.:VENTA DETALLE:.\n" << endl;
		  //cout << "ingresa ID producto: "; cin >> id_producto;
		  //cout << "ingrese cantidad: "; cin >> cantidad;
		  //cout << "digite precio: "; cin >> precio;


		  venta_Detalle v2 = venta_Detalle(id_factura, id_producto, cantidad, precio);
		  v2.insertar();
		  cout << "\n\n";
		  system("pause");
	  }

	  void consultarVenta1(string buscar) {
		  cout << "\t\t\t\t\thola: " << buscar;
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;

		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "select ventas.idventas,ventas.nofactura,ventas.serie,ventas.fechafactura,clientes.nombres,empleados.nombres,ventas.fecha_ingreso FROM db_super_mercado.ventas INNER JOIN db_super_mercado.clientes on ventas.idcliente = clientes.idCliente INNER JOIN db_super_mercado.empleados  on ventas.idempleado = empleados.idEmpleado  where  ventas.idventas = ('" + buscar + "')";

			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  // cout << "------------------------------Ventas------------------------------\n" << endl;

			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  //cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << endl;
					  system("cls");
					  cout << "***********************************************************" << endl;
					  cout << " No Factura: " << fila[1] << "          Serie: " << fila[2] << "        Fecha: " << fila[3] << endl << endl;
					  cout << " Cliente: " << fila[4] << "                         Empleado: " << fila[5] << endl << endl;
					  cout << "**********************************************************" << endl;
					  cout << " Cantidad             Descripcion               Total " << endl << endl;

					  imp << "***********************************************************" << endl;
					  imp << " No Factura: " << fila[1] << "          Serie: " << fila[2] << "        Fecha: " << fila[3] << endl << endl;
					  imp << " Cliente: " << fila[4] << "                           Empleado: " << fila[5] << endl << endl;
					  imp << "***********************************************************" << endl;
					  imp << " Cantidad             Descripcion                   Total " << endl << endl;

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

	  void consultarVenta() {

		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cout << "Digite el numero de factura que desea visualizar: "; cin >> buscar;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "select ventas.idventas,ventas.nofactura,ventas.serie,ventas.fechafactura,clientes.nombres,empleados.nombres,ventas.fecha_ingreso FROM db_super_mercado.ventas INNER JOIN db_super_mercado.clientes on ventas.idcliente = clientes.idCliente INNER JOIN db_super_mercado.empleados  on ventas.idempleado = empleados.idEmpleado  where  ventas.idventas = ('" + buscar + "')";

			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  // cout << "------------------------------Ventas------------------------------\n" << endl;

			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  //cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << endl;
					  system("cls");
					  cout << "***********************************************************" << endl;
					  cout << " No Factura: " << fila[1] << "          Serie: " << fila[2] << "        Fecha: " << fila[3] << endl << endl;
					  cout << " Cliente: " << fila[4] << "                         Empleado: " << fila[5] << endl << endl;
					  cout << "**********************************************************" << endl;
					  cout << " Cantidad             Descripcion               Total " << endl << endl;

					  imp << "***********************************************************" << endl;
					  imp << " No Factura: " << fila[1] << "          Serie: " << fila[2] << "        Fecha: " << fila[3] << endl << endl;
					  imp << " Cliente: " << fila[4] << "                           Empleado: " << fila[5] << endl << endl;
					  imp << "***********************************************************" << endl;
					  imp << " Cantidad             Descripcion                   Total " << endl << endl;

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

	  void mostrarCompra(string buscar) {

		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila = 0;
		  MYSQL_RES* resultado;
		  ///cout << "Digite el numero de factura que desea visualizar: "; cin >> buscar;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "select ventas.idventas,ventas.nofactura,ventas.serie,ventas.fechafactura,clientes.nombres,empleados.nombres,ventas.fecha_ingreso FROM db_super_mercado.ventas INNER JOIN db_super_mercado.clientes on ventas.idcliente = clientes.idCliente INNER JOIN db_super_mercado.empleados  on ventas.idempleado = empleados.idEmpleado  where  ventas.idventas = ('" + buscar + "')";

			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  // cout << "------------------------------Ventas------------------------------\n" << endl;

			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());
				  while (fila = mysql_fetch_row(resultado)) {
					  //cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4] << ", " << fila[5] << ", " << fila[6] << endl;
					  system("cls");
					  cout << "***********************************************************" << endl;
					  cout << " No Factura: " << fila[1] << "          Serie: " << fila[2] << "        Fecha: " << fila[3] << endl << endl;
					  cout << " Cliente: " << fila[4] << "                         Empleado: " << fila[5] << endl << endl;
					  cout << "**********************************************************" << endl;
					  cout << " Cantidad             Descripcion               Total " << endl << endl;

					  imp << "***********************************************************" << endl;
					  imp << " No Factura: " << fila[1] << "          Serie: " << fila[2] << "        Fecha: " << fila[3] << endl << endl;
					  imp << " Cliente: " << fila[4] << "                           Empleado: " << fila[5] << endl << endl;
					  imp << "***********************************************************" << endl;
					  imp << " Cantidad             Descripcion                   Total " << endl << endl;

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



	  
	 
	  //aux += 1;

	  

	  void consultarVentaDetalle() {
		  float suma=0;
		  string totalventa, sub_total;
		  //cout << "\n\n\n";
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila=0;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "Select ventas_detalle.idventas_detalle,ventas.idventas,productos.producto,ventas_detalle.cantidad,ventas_detalle.precio_unitario from db_super_mercado.ventas_detalle INNER JOIN db_super_mercado.ventas on ventas_detalle.idventa = ventas.idventas INNER JOIN db_super_mercado.productos on ventas_detalle.idproducto = productos.idproductos where   ventas.idventas = ('" + buscar + "')";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());

				 // cout << "------------------------------Venta DETALLE------------------------------\n" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  //cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4]  << endl;

					  cout <<" "<<fila[3]<< "                     " << fila[2]<< "                     " << fila[4]<< endl;
					  
					  sub_total = fila[4];
					 // suma += atoi(sub_total.c_str());
					  suma += stof(sub_total);
					  suma *= 100;
					  suma=round(suma);
					  suma /= 100;
					  totalventa = to_string(suma);
					  imp << " " << fila[3] << "                         " << fila[2] << "                               " << fila[4] << endl;

				  }
				  cout << "\n\n";
				  cout << "**************** TOTAL A PAGAR: " <<totalventa<<"  ******************" << endl;
				  
				  cout << endl << endl << endl << endl;
				  cout << "                   Gracias por tu compra					" << endl;
				  cout << "                       Vuelve Pronto						" << endl<<endl;
				  cout << "**********************************************************" << endl;
				  imp << "\n\n";
				  imp << "**************** TOTAL A PAGAR: "  << totalventa << "  ******************" << endl;
				  imp << endl << endl << endl << endl;
				  imp << "                      Gracias por tu compra					" << endl;
				  imp << "                              Vuelve Pronto						" << endl << endl;
				  imp << "**********************************************************" << endl;

				
				
				  imp.close();
				  cout << "\nDesea imprimir la factura (S / N): ";
				  cin >> resp;
				  if (resp == 'S' || resp == 's') {

					  imprimir();

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





	  void mostrarVentaDetalle(string buscar) {
		  //cout << "\n\n\n";
		  float suma = 0;
		  string totalventa, sub_total;
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "Select ventas_detalle.idventas_detalle,ventas.idventas,productos.producto,ventas_detalle.cantidad,ventas_detalle.precio_unitario from db_super_mercado.ventas_detalle INNER JOIN db_super_mercado.ventas on ventas_detalle.idventa = ventas.idventas INNER JOIN db_super_mercado.productos on ventas_detalle.idproducto = productos.idproductos where   ventas.idventas = ('" + buscar + "')";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());

				  // cout << "------------------------------Venta DETALLE------------------------------\n" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  //cout << fila[0] << ", " << fila[1] << ", " << fila[2] << ", " << fila[3] << ", " << fila[4]  << endl;

					  cout << " " << fila[3] << "                     " << fila[2] << "                     " << fila[4] << endl;

					  sub_total = fila[4];
					  //suma += atoi(sub_total.c_str());

					  suma += stof(sub_total);
					  					  
					  totalventa = to_string(suma);

					  imp << " " << fila[3] << "                         " << fila[2] << "                               " << fila[4] << endl;

				  }
				  cout << "\n\n";
				  cout << "**************** TOTAL A PAGAR: " <<totalventa << "  ******************" << endl;
				  cout << endl << endl << endl << endl;
				  cout << "                   Gracias por tu compra					" << endl;
				  cout << "                       Vuelve Pronto						" << endl << endl;
				  cout << "**********************************************************" << endl;
				  imp << "\n\n";
				  imp << "**************** TOTAL A PAGAR: " << totalventa << "  ******************" << endl;
				  imp << endl << endl << endl << endl;
				  imp << "                      Gracias por tu compra					" << endl;
				  imp << "                              Vuelve Pronto						" << endl << endl;
				  imp << "**********************************************************" << endl;
				  imp.close();
				
				  cout << "\nDesea imprimir la factura (S / N): ";
				  cin >> resp;
				  if (resp == 'S' || resp == 's') {

					  imprimir();

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


	  void editarVentaDetalle(string buscar) {
		  //cout << "\n\n\n";
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  MYSQL_ROW fila;
		  MYSQL_RES* resultado;
		  cn.abrir_conexion();
		  if (cn.getConectar()) {

			  string consulta = "Select ventas_detalle.idventas_detalle,ventas.idventas,productos.producto,ventas_detalle.cantidad,ventas_detalle.precio_unitario from db_super_mercado.ventas_detalle INNER JOIN db_super_mercado.ventas on ventas_detalle.idventa = ventas.idventas INNER JOIN db_super_mercado.productos on ventas_detalle.idproducto = productos.idproductos where   ventas.idventas = ('" + buscar + "')";
			  const char* c = consulta.c_str();
			  q_estado = mysql_query(cn.getConectar(), c);
			  if (!q_estado) {
				  resultado = mysql_store_result(cn.getConectar());

				  // cout << "------------------------------Venta DETALLE------------------------------\n" << endl;
				  cout << "ID" << "\t Id venta" << "\tID Producto" << "\t Cantidad" << "\t Total" << endl;
				  while (fila = mysql_fetch_row(resultado)) {
					  cout << fila[0] << ",\t " << fila[1] << ", \t" << fila[2] << ", \t" << fila[3] << ", \t" << fila[4]  << endl;

					  //cout << " " << fila[3] << "                     " << fila[2] << "                     " << fila[4] << endl;

					  //imp << " " << fila[3] << "                         " << fila[2] << "                               " << fila[4] << endl;

				  }


				  cout << endl << endl;
				 

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



	  void eliminarVentaDetalle() {
		  
		  int q_estado;
		  ConexionBD cn = ConexionBD();
		  cout << "Digite el numero de factura al que desea eliminar un detalle: "; cin >> buscar;

		  consultarVentaDetalle();
		  cout << "\n\t\t------------------------------Eliminar Detalle------------------------------\n" << endl;
		  //string id;
		  cout << "\n\nDigite el ID del Detalle que desea eliminar: "; cin >> buscar;

		  cn.abrir_conexion();

		  if (cn.getConectar()) {
			  string  insertar = "DELETE FROM ventas_detalle  WHERE (idventas_detalle = '" + buscar + "')";
			  const char* i = insertar.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
				  cout << " xxx Error al Eliminar  xxx" << endl;
			  if (!q_estado) {
				  cout << "Eliminacion  Exitosa ..." << endl;
			  }
			  else {
			  }
		  }
		  else {
			  cout << " xxx Error en la Conexion xxxx" << endl;
		  }
		  cn.cerrar_conexion();
	  }

	  void eliminarVenta1() {
		  int q_estado;

		  ConexionBD cn = ConexionBD();
		  //cout << "\n\t\t------------------------------Eliminar Factura------------------------------\n" << endl;
		  //string id;
		  //cout << "\n\nDigite el ID del Producto que desea eliminar: "; cin >> ;
		  //cout << "Digite el numero de factura que desea visualizar: "; cin >> buscar;
		  cn.abrir_conexion();

		  if (cn.getConectar()) {
			  string  insertar = "DELETE FROM ventas  WHERE (nofactura = '" + buscar + "')";
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
	  void eliminarVentaDetalle1() {

		  int q_estado;

		  ConexionBD cn = ConexionBD();
		  cout << "\n\t\t------------------------------Eliminar Factura------------------------------\n" << endl;
		  //string id;
		  cout << "\n\nDigite el No de factura que desea eliminar: "; cin >> buscar;

		  cn.abrir_conexion();

		  if (cn.getConectar()) {
			  string  insertar = "DELETE FROM ventas_detalle  WHERE (idventa = '" + buscar + "')";
			  const char* i = insertar.c_str();
			  q_estado = mysql_query(cn.getConectar(), i);
			  if (!q_estado) {
				 // cout << "Eliminacion  Exitosa ..." << endl;
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

	  void imprimir()
	  {
		  Impresion I = Impresion();

		  
		  string texto;

		  tifstream in(TEXT("factura.txt"));  /*acá va escrito el nombre del archivo que quieres imprimir */
		  I.PrintFile(in);
		  in.close();

	  }
	  
	  void ellimiartodo() {

		  eliminarVentaDetalle1();
		  eliminarVenta1();
	  }


	  void actualizar_datos(string id_cliente, string id_empleado,string ID) {
		  system("cls");
		 
		  Venta v1 = Venta();
		
		  v1.actualizar(id_cliente,id_empleado,ID);
		  id = v1.ver();
	
	  }
	  void actualizar_Venta_Detalle(string id_factura, string id_producto, string cantidad, string precio) {

		

		  venta_Detalle v2 = venta_Detalle();
		  v2.modificar(id_factura, id_producto, cantidad, precio);
		  cout << "\n\n";
		  system("pause");
	  }


};

