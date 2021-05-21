#include <iostream>
#include "ConexionBD.h"
#include "Persona.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Marca.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Puesto.h"

using namespace std;

void menu_Principal();
void munu_Puestos();
void menu_Empleados();
void menu_Clientes();
void menu_Marcas();
void menu_Productos();
void menu_Proveedores();

int opcion_menu, opcion_sub_menu; // variables para las opciones de los switch

int main(){
    
  
    cout << "\n\t\t\t   .:BIENVENIDO:. \n\n";
	
	menu_Principal();
	/*
	cout << "*****************MENU******************" << endl << endl;
	cout << "SELECCIONE LA TABLA QUE DESEA EDITAR:" << endl << endl;
	cout << "Marcas...............................1" << endl;
	cout << "Clientes.............................2" << endl;
	cout << "ETC..................................3" << endl;
	cout << "Salir................................4" << endl << endl;
	cin >> op;
	switch (op) {

	case 1: system("cls");

		cout << "*************Editar_Marcas**************" << endl << endl;
		cout << "SELECCIONE LA OPERACION QUE DESEA REALIZAR..." << endl << endl;
		cout << "Crear registro.......................1" << endl;
		cout << "Leer registro........................2" << endl;
		cout << "Actualizar registro..................3" << endl;
		cout << "Borrar registro......................4" << endl;
		cout << "Regresar.............................5" << endl << endl;
		cin >> op1;

		switch (op1) {
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5: system("cls"); main();
			break;
		default:cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}
		break;
	};*/
		

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
		cout << "\n\t\t.:PUESTOS:.\n\n" << endl;
		cout << "1. Editar Puesto." << endl;
		cout << "2. Eliminar Puesto." << endl;
		cout << "3. Ver Puesto." << endl;
		cout << "4. Insertar Puesto." << endl;
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
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
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
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
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
		case 1: break;
		case 2: break;
		case 3: break;
		case 4: break;
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

	} while (opcion_sub_menu != 4);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
