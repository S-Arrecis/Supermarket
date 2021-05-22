#include <iostream>
#include <string>
//#include <Windows.h>
#include "ConexionBD.h"
#include "Persona.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Marca.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Puesto.h"

using namespace std; 

//l
//using namespace std;
//prototipos
void menu_Principal();
void munu_Puestos();
void menu_Empleados();
void menu_Clientes();
void menu_Marcas();
void menu_Productos();
void menu_Proveedores();

ConexionBD conec = ConexionBD();

int opcion_menu, opcion_sub_menu, op1; // variables para las opciones de los switch
string puesto,marca,ID; //variable para enviar datos al puesto
string nombre, apellido, nit, telefono, correo, fechaing;
char genero;
int main(){
    
  
    cout << "\n\t\t\t   .:BIENVENIDO:. \n\n";
	conec.primera_conexion();
	menu_Principal();

   return 0;
}

void menu_Principal(){
	system("cls");

	do{

		cout << "\t\t*****************MENU******************" << endl << endl;
		cout << "\t\t\tQue desea Realizar hoy\n\n"<< endl;

		cout << "\t\tPuestos..............................1" << endl;
		cout << "\t\tEmpleados............................2" << endl;
		cout << "\t\tClientes.............................3" << endl;
		cout << "\t\tMarcas...............................4" << endl;
		cout << "\t\tProductos............................5" << endl;
		cout << "\t\tProveedores..........................6" << endl;		
		cout << "\t\tSalir................................7" << endl;
		cout << "\n\tDigite una opcion: ";
		cin >> opcion_menu;

		switch (opcion_menu) {

			case 1: munu_Puestos(); break;
			case 2: menu_Empleados(); break;
			case 3: menu_Clientes(); break;
			case 4: menu_Marcas(); break;
			case 5: menu_Productos(); break;
			case 6: menu_Proveedores(); break;
			case 7: system("cls"); cout << "Saliendo del Sistema...\n\n\n"; Sleep(1000); system("pause"); exit(1); break;

			default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)\n\n\n" << endl; system("pause");
		}

	} while (opcion_menu !=7);
	
}

void munu_Puestos(){
	system("cls");

	do {
		cout << "\n\t\t.:PUESTOS:.\n\n" << endl;//
		cout << "1. Editar Puesto." << endl;
		cout << "2. Eliminar Puesto." << endl;
		cout << "3. Ver Puesto." << endl;
		cout << "4. Insertar Puesto." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu) {
		case 1: {
			system("cls");

			Puesto p = Puesto();
			p.leer();

			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del puesto que desea actualizar: ";
			cin >> ID;
			cout << endl;
			cout << "-----------A continuacion ingrese los nuevos datos para reemplazar---------" << endl << endl;
			cout << "Ingrese Nuevo Puesto: ";
			cin >> puesto;
			
			Puesto p1 = Puesto(puesto,ID);

			p1.actualizar();


			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
		}
	
			break;
		case 2: 
			{
			system("cls");

			Puesto p = Puesto();
			p.leer();

			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del cliente que desea eliminar: ";
			cin >> ID;

			Puesto  p1 = Puesto(puesto,ID);
			p1.eliminar();

			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }

		}break;
		case 3: {

			Puesto p = Puesto();
			p.leer();
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
			switch (op1) { case 1: system("cls"); main(); break; default:system("exit"); }
		
		} break;
		case 4: {

			cout << "INGRESE EL NOMBRE DEL PUESTO QUE DESEA INSERTAR" << endl;
			cin >> puesto;

			Puesto p = Puesto(puesto,ID);

			p.crear();

			system("pause");
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }

		
		}break;
		case 5: menu_Principal(); break;
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

		} while (opcion_sub_menu != 5);
	}

void menu_Empleados(){
	system("cls");


	do {
		cout << "\n\t\t.:EMPLEADO:.\n\n" << endl;
		cout << "1. Editar Empleado." << endl;
		cout << "2. Eliminar Empleado." << endl;
		cout << "3. Ver Empleado." << endl;
		cout << "4. Insertar Empleado." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: menu_Principal(); break;
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

	} while (opcion_sub_menu != 4);

}

void menu_Clientes(){
	system("cls");
	do {
		cout << "\n\t\t.:CLIENTES:.\n\n" << endl;
		cout << "1. Editar Cliente." << endl;
		cout << "2. Eliminar Cliente." << endl;
		cout << "3. Ver Cliente." << endl;
		cout << "4. Insertar Cliente." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu) {
		case 1: {
			system("cls");

			Cliente C = Cliente();
			C.leer();

			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del cliente que desea actualizar: ";
			cin >> ID;
			cout << endl;
			cout << "-----------A continuacion ingrese los nuevos datos para reemplazar---------" << endl << endl;
			
			cout << endl << "INGRESE EL NOMBRE DEL CLIENTE: " << endl;
			getline(cin, nombre);
			cout << endl << "INGRESE EL APELLIDO DEL CLIENTE: " << endl;
			getline(cin, apellido);
			cout << endl << "INGRESE EL NIT DEL CLIENTE: " << endl;
			getline(cin, nit);
			cout << endl << "INGRESE EL GENERO DEL CLIENTE (F O M): " << endl;
			cin >> genero;
			cout << endl << "INGRESE EL TELEFONO DEL CLIENTE: " << endl;
			getline(cin, telefono);
			cout << endl << "INGRESE EL CORREO ELECTRONICO DEL CLIENTE: " << endl;
			getline(cin, correo);
			cout << endl << "INGRESE LA FECHA DE INGRESO DEL CLIENTE EN FORMATO AAAA-MM-DD: " << endl;
			getline(cin, fechaing);
			cin.ignore();

			Cliente c = Cliente(nombre, apellido, telefono, fechaing, genero, nit, correo, ID);

			c.actualizar();


			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
		}

			  break;
		case 2:
		{
			system("cls");

			Cliente C = Cliente();
			C.leer();

			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del cliente que desea eliminar: ";
			cin >> ID;

			Cliente c = Cliente(nombre, apellido, telefono, fechaing, genero, nit, correo,ID);
			c.eliminar();

			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }

		}break;
		case 3: {

			Cliente C = Cliente();
			C.leer();
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; default:system("exit"); }

		} break;
		case 4: {
			cin.ignore();
			cout<<endl << "INGRESE EL NOMBRE DEL CLIENTE: " << endl;
			getline(cin,nombre);
			cout << endl << "INGRESE EL APELLIDO DEL CLIENTE: " << endl;
			getline(cin, apellido);
			cout << endl << "INGRESE EL NIT DEL CLIENTE: " << endl;
			getline(cin, nit);
			cout << endl << "INGRESE EL GENERO DEL CLIENTE (F O M): " << endl;
			cin >> genero;
			cin.ignore();
			cout << endl << "INGRESE EL TELEFONO DEL CLIENTE: " << endl;
			getline(cin, telefono);
			cout << endl << "INGRESE EL CORREO ELECTRONICO DEL CLIENTE: " << endl;
			getline(cin, correo);
			cout << endl << "INGRESE LA FECHA DE INGRESO DEL CLIENTE EN FORMATO AAAA-MM-DD: " << endl;
			getline(cin, fechaing);
			cin.ignore();

			Cliente C = Cliente(nombre,apellido,telefono,fechaing,genero,nit,correo,ID);

			C.crear();

			system("pause");
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }


		}break;
		case 5: menu_Principal(); break;
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

	} while (opcion_sub_menu != 4);
}

void menu_Marcas(){
	system("cls");

	do {
		cout << "\n\t\t.:MARCAS:.\n\n" << endl;
		cout << "1. Editar Marca." << endl;
		cout << "2. Eliminar Marca." << endl;
		cout << "3. Ver Marcas." << endl;
		cout << "4. Insertar Marca." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu) {
		case 1: {system("cls"); 
			Marca mc = Marca();
			mc.editar(); cout << "\n\n"; menu_Marcas(); } break;
		
		case 2: { system("cls"); Marca mc = Marca(); mc.eliminar(); cout << "\n\n"; system("pause"); menu_Marcas();  } break;
		
		case 3: {
			system("cls");
			cout << "\t\tCONSULTAR MARCAS\n\n";
			Marca mc = Marca();
			mc.consultar();
			cout << "\n\n"; system("pause"); menu_Marcas();
			
		} break;
		
		case 4: { system("cls");
			Marca mc = Marca();
			mc.insertar();
			cout << "\n\n"; system("pause"); menu_Marcas();
		}break;
		
		case 5: menu_Principal(); break;
		
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

	} while (opcion_sub_menu != 4);

}

void menu_Productos(){
	system("cls");

	do {
		cout << "\n\t\t.:PRODUCTOS:.\n\n" << endl;
		cout << "1. Editar Producto." << endl;
		cout << "2. Eliminar Producto." << endl;
		cout << "3. Ver Producto." << endl;
		cout << "4. Insertar Producto." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu) {
		case 1: {
			system("cls"); Producto p = Producto(); p.modificar(); cout << "\n\n"; system("pause"); menu_Productos();
		} break;
		case 2: {
			system("cls");
			Producto p = Producto(); p.eliminar(); cout << "\n\n"; system("pause"); menu_Productos();
		}break;
		case 3: {Producto p = Producto(); system("cls"); p.consultar(); cout << "\n\n"; system("pause"); menu_Productos(); } break;
		case 4: {
			string producto, id, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso;
			system("cls");
			cout << "\t\t\t----------------------Insertar Datos de Productos--------------------\n\n";
			Marca mc = Marca();
			cin.ignore();
			cout << "\nIngrese el nombre del Producto: ";
			getline(cin, producto);
			mc.ver();
			cout << "\nIngrese el id de la marca: "; cin >> id;
			cin.ignore();
			cout << "Ingrese la Descripcion del producto: "; getline(cin, descripcion);
			cout << "Digite el Costo del producto ( " + producto + " ): "; getline(cin, precio_costo);
			cout << "Digite el Costo de venta del producto ( " + producto + " ): "; getline(cin, precio_venta);
			cout << "Digte cuantas existencias tenemos del producto ( " + producto + " ): "; cin >> existencia;
			cout << "Digite la fecha cuando ingreso el producto ( " + producto + " ) en formato YYYY-MM-DD "; cin >> fecha_ingreso;

			Producto p = Producto(producto, id, descripcion, precio_costo, precio_venta, existencia, fecha_ingreso);
			p.insertar();
			fflush(stdin);
			cout << "\n\n"; system("pause"); menu_Productos();
			
		} break;
		case 5: menu_Principal(); break;
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

	} while (opcion_sub_menu != 4);

}

void menu_Proveedores(){
	system("cls");

	do {
		cout << "\n\t\t.:PROVEEDORES:.\n\n" << endl;
		cout << "1. Editar Proveedor." << endl;
		cout << "2. Eliminar Proveedor." << endl;
		cout << "3. Ver Proveedor." << endl;
		cout << "4. Insertar Proveedor." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu) {
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
		case 5: menu_Principal(); break;
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

	} while (opcion_sub_menu != 4); //pruebas comit desde visual
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
