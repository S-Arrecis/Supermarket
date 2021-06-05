#include <iostream>

//#include <Windows.h>
#include "ConexionBD.h"
#include "Persona.h"
#include "Cliente.h"
#include "Empleado.h"
#include "Marca.h"
#include "Producto.h"
#include "Proveedor.h"
#include "Puesto.h"
#include "crear_factura.h"
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
void menu_factura();
void agregar_un_cliente(string);
void agregar_al_carrito();
void carritoactualizar(string);

ConexionBD conec = ConexionBD();

int opcion_menu, opcion_sub_menu, op1,items=1; // variables para las opciones de los switch
string puesto,marca,ID; //variable para enviar datos al puesto
string nombre, apellido, nit, telefono, correo, fechaing,direccion,fechanacimiento,idpuesto,fechainitlab;
char genero;
int main(){
    
  
    cout << "\n\t\t\t   .:BIENVENIDO:. \n\n";
	conec.primera_conexion();
	//crear_factura m = crear_factura();
	//m.ingresar_datos();
	menu_Principal();

   return 0;
}

void carritoactualizar(string factura) {
	string No_factura;
	system("cls");
	string producto, cantidad, id,actualizar;
	id = "NULL";
	char res;
	string total = "NULL";
	crear_factura c1 = crear_factura();
	c1.editarVentaDetalle(factura);

	cout << "Digite el ID del item que desea actualizar: "; cin >> actualizar;
	Producto p1 = Producto();
	p1.ver();
	cout << endl;
	cout << "ingresa ID producto: "; cin >> producto;
	id = p1.buscarProducto(producto);
	cout << "ingrese cantidad: "; cin >> cantidad;
	total = p1.buscarPrecioProducto(producto, cantidad);

	if (total == "NULL") {
		system("cls");
		cout << "ERROR\n";
		Sleep(2000);
		cout << "Estableciendo nueva conexion.. \n\n";
		Sleep(2000);
		system("pause");
		fflush(stdin);
		menu_Principal();
	}
	else {
		Venta v1 = Venta();
		No_factura = v1.factura();

		crear_factura venta = crear_factura();
		venta.actualizar_Venta_Detalle(actualizar, producto, cantidad, total);
	}

	cout << "\nDesea editar otra compra (s/n): "; cin >> res;
	switch (res) {
	case 's':
	case 'S': carritoactualizar(factura); break;
	case 'n':
	case 'N': system("cls"); break;
	}
	system("cls");
	crear_factura m = crear_factura();
	//m.consultarVenta1(factura);
//	m.consultarVentaDetalle();
	m.mostrarCompra(factura);
	m.mostrarVentaDetalle(factura);
	cout << "\n\n\n";
	system("pause");
	menu_factura();

}
void agregar_al_carrito() {
	string No_factura;
	system("cls");
	string producto, cantidad,id;
	id = "NULL";
	char res;
	string total = "NULL";
	Producto p1 = Producto();
	p1.ver();
	cout << "\t\t\t\t\tItems agregados: " << items;
	cout << endl;
	cout << "ingresa ID producto: "; cin >> producto;
	id = p1.buscarProducto(producto);
	cout << "ingrese cantidad: "; cin >> cantidad;
	total = p1.buscarPrecioProducto(producto, cantidad);

	if (total == "NULL") {
		system("cls");
		cout << "ERROR\n";
		Sleep(2000);
		cout << "Estableciendo nueva conexion.. \n\n";
		Sleep(2000);
		system("pause");
		fflush(stdin);
		menu_Principal();
	}
	else {
		Venta v1 = Venta();
		No_factura = v1.factura();

		crear_factura venta = crear_factura();
		venta.insertar_Venta_Detalle(No_factura, producto, cantidad, total);
		items ++;
	}
	cout << "\nDesea agregar otra compra (s/n): "; cin >> res;
	switch (res) {
	case 's':
	case 'S': agregar_al_carrito(); break;
	case 'n':
	case 'N': system("cls"); break;
	}
	system("cls");
	crear_factura mostrar = crear_factura();
	mostrar.mostrarCompra(No_factura);
	mostrar.mostrarVentaDetalle(No_factura);
	cout << "\n\n\n";
	system("pause");
	menu_factura();


}

void menu_factura() {


	system("cls");

	do {
		cout << "\n\t\t.:FACTURA:.\n\n" << endl;//
		cout << "1. Editar FACTURA." << endl;
		cout << "2. Eliminar FACTURA." << endl;
		cout << "3. Ver FACTURA." << endl;
		cout << "4. Insertar FACTURA." << endl;
		cout << "5.  <-----< Regresar." << endl;
		cout << "Digite un opcion: "; cin >> opcion_sub_menu;

		switch (opcion_sub_menu){
		case 1: {
			system("cls");
			Cliente C1 = Cliente();
			string id;
			id = "NULL";
			string nit, empleado,factura;
			system("cls");
			cout << "Digite el numero factura que desea actuliazar: "; cin >> factura;

			cout << "\t\t.:EDTITAR FACTURA:.\n\n";
			cout << "\t....Editando Cliente.....\n\n";
			cout << "Digite el Nit del nuevo cliente: "; cin >> nit;

			id = C1.buscarCliente(nit);
			if (id == "NULL") {
				system("cls");
				cout << "Cliente con el NIT ( " + nit + ") no esta registrado en el sistema..\n";
				Sleep(2000);
				cout << "Comenzando proceso de registro del nuevo cliente con el nit ( " + nit + "). \n\n";
				Sleep(2000);
				system("pause");
				fflush(stdin);
				agregar_un_cliente(nit);
			}
			cout << "\nDite el ID del Empleado: "; cin >> empleado;
			
			crear_factura m = crear_factura();
			m.actualizar_datos(id,empleado,factura);
			carritoactualizar(factura);


		}  break;
		case 2: {
			int res;
			do {
				system("cls");
				cout << "\n\n\t\t.:Eliminar Facturas:.\n\n" << endl;
				cout << "1. Elimiar Detalle " << endl;
				cout << "2. Eliminar Factura. " << endl;
				cout << "3. <----- Regresar. " << endl;
				cout << "\nDigite una opcion: "; cin>> res;

				switch (res) {
					
				case 1: {
					crear_factura m = crear_factura(); 
					m.eliminarVentaDetalle(); cout << "\n\n"; system("pause");
				
				} break;
				case 2: {
					crear_factura m = crear_factura();
					m.ellimiartodo(); cout << "\n\n"; system("pause");
				}break;
				case 3: menu_factura(); break;

				default: cout << "Opcion no valida..\n\n"; system("pause"); menu_factura();

				}
			
			} while (res !=3);
		
		
		} break;
		case 3: {
			system("cls");
			crear_factura m = crear_factura();
			m.consultarVenta();
			m.consultarVentaDetalle();
			cout << "\n\n";
			system("pause");
			menu_factura();
		
		} break;
		case 4: {
			system("cls");
			Cliente C1 = Cliente();
			string nit, empleado, id;
			id = "NULL";
			char res;
			cout << "\n\t\t.:DATOS DE FACTURACION:. \n\n";
		
			cout << "Digite el Nit del Cliente: "; cin >> nit;
			id = C1.buscarCliente(nit);
			if (id == "NULL") {
				system("cls");
				cout << "Cliente con el NIT ( "+nit+") no esta registrado en el sistema..\n";
				Sleep(2000);
				cout << "Comenzando proceso de registro del nuevo cliente con el nit ( "+nit+"). \n\n";
				Sleep(2000);
				system("pause");
				fflush(stdin);
				agregar_un_cliente(nit);
			}
			else {

				string total = "NULL";
				
				cout << "\nDite el ID del Empleado: "; cin >> empleado;
				crear_factura m = crear_factura();
				m.ingresar_datos(id, empleado);
				cout << "\n\n";
				string producto, id, cantidad;
				cout << "\n\t\t.:VENTA DETALLE:.\n" << endl;
				
				agregar_al_carrito();
				//menu_factura();
			}
		}break;
		case 5: menu_Principal(); break;
		default: cout << "Error....\n\n"; system("pause"); menu_factura();
		}

	} while (opcion_sub_menu != 5);


	
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
		cout << "\t\tFacturas.............................7" << endl;
		cout << "\t\tSalir................................8" << endl;
		cout << "\n\tDigite una opcion: ";
		cin >> opcion_menu;

		switch (opcion_menu) {

			case 1: munu_Puestos(); break;
			case 2: menu_Empleados(); break;
			case 3: menu_Clientes(); break;
			case 4: menu_Marcas(); break;
			case 5: menu_Productos(); break;
			case 6: menu_Proveedores(); break;
			case 7: menu_factura(); break;
			case 8: system("cls"); cout << "Saliendo del Sistema...\n\n\n"; Sleep(1000); system("pause"); exit(1); break;

			default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)\n\n\n" << endl; system("pause");
		}

	} while (opcion_menu !=8);
	
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
		case 1: {
			system("cls");

			Empleado E = Empleado();
			E.leer();

			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del empleado que desea actualizar: ";
			cin >> ID;
			cout << endl;
			cout << "-----------A continuacion ingrese los nuevos datos para reemplazar---------" << endl << endl;
			cin.ignore();
			cout << endl << "INGRESE EL NOMBRE DEL EMPLEADO: " << endl;
			getline(cin, nombre);
			cout << endl << "INGRESE EL APELLIDO DEL EMPLEADO: " << endl;
			getline(cin, apellido);
			cout << endl << "INGRESE LA DIRECCION DEL EMPLEADO: " << endl;
			getline(cin, direccion);
			cout << endl << "INGRESE EL TELEFONO DEL EMPLEADO: " << endl;
			getline(cin, telefono);
		CONDICIONEMP:
			cout << endl << "INGRESE EL GENERO DEL EMPLEADO (F o M): " << endl;
			cin >> genero;
			if (genero != 'F') {
				if (genero != 'f') {
					if (genero != 'M') {
						if (genero != 'm') {
							system("cls");
							cout << endl << "!!EL DATO INGRESADO ES INVALIDO!!" << endl;
							system("color 0c");
							goto CONDICIONEMP;
						}
					}
				}
			}
			system("color 02");
			cin.ignore();
			cout << endl << "INGRESE LA FECHA DE NACIMIENTO DEL EMPLEADO EN FORMATO AAA-MM-DD: " << endl;
			getline(cin, fechanacimiento);
			cout << endl << "INGRESE EL ID DEL PUESTO DEL EMPLEADO: " << endl;
			getline(cin, idpuesto);
			cout << endl << "INGRESE LA FECHA DE INICIO DE LABORES DEL EMPLEADO EN FORMATO AAA-MM-DD: " << endl;
			getline(cin, fechainitlab);
			cin.ignore();

			Empleado e = Empleado(nombre, apellido, telefono, fechaing, genero, direccion, fechanacimiento, fechainitlab, idpuesto, ID);

			e.actualizar();


			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }
		} break;
		case 2: {
			system("cls");

			Empleado E = Empleado();
			E.leer();

			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del empleado que desea eliminar: ";
			cin >> ID;

			Empleado e = Empleado(nombre, apellido, telefono, fechaing, genero, direccion, fechanacimiento, fechainitlab, idpuesto,ID);
			e.eliminar();

			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }

		} break;
		case 3: {

			Empleado E = Empleado();
			E.leer();
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }

		} break;
		case 4: {
			cin.ignore();
			cout << endl << "INGRESE EL NOMBRE DEL EMPLEADO: " << endl;
			getline(cin, nombre);
			cout << endl << "INGRESE EL APELLIDO DEL EMPLEADO: " << endl;
			getline(cin, apellido);
			cout << endl << "INGRESE LA DIRECCION DEL EMPLEADO: " << endl;
			getline(cin, direccion);
			cout << endl << "INGRESE EL TELEFONO DEL EMPLEADO: " << endl;
			getline(cin, telefono);
		CONDICIONEMP1:
			cout << endl << "INGRESE EL GENERO DEL EMPLEADO (F o M): " << endl;
			cin >> genero;
			if (genero != 'F') {
				if (genero != 'f') {
					if (genero != 'M') {
						if (genero != 'm') {
							system("cls");
							cout << endl << "!!EL DATO INGRESADO ES INVALIDO!!" << endl;
							system("color 0c");
							goto CONDICIONEMP1;
						}
					}
				}
			}
			system("color 02");
			cin.ignore();
			cout << endl << "INGRESE LA FECHA DE NACIMIENTO DEL EMPLEADO EN FORMATO AAA-MM-DD: " << endl;
			getline(cin, fechanacimiento);
			cout << endl << "INGRESE EL ID DEL PUESTO DEL EMPLEADO: " << endl;
			getline(cin, idpuesto);
			cout << endl << "INGRESE LA FECHA DE INICIO DE LABORES DEL EMPLEADO EN FORMATO AAA-MM-DD: " << endl;
			getline(cin, fechainitlab);
			cin.ignore();

			Empleado E = Empleado(nombre,apellido, telefono, fechaing,genero,direccion, fechanacimiento,fechainitlab,idpuesto,ID);

			E.crear();

			system("pause");
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }


		}break;
		case 5: menu_Principal(); break;
		default: cout << " (TwT) Opcion no valida intenta otra vez.. (TwT)" << endl;
		}

	} while (opcion_sub_menu != 4);

}
void agregar_un_cliente(string nit) {
	system("cls");
	cin.ignore();
	cout << endl << "INGRESE EL NOMBRE DEL CLIENTE: ";
	getline(cin, nombre);
	cout << endl << "INGRESE EL APELLIDO DEL CLIENTE: ";
	getline(cin, apellido);
	//cout << endl << "INGRESE EL NIT DEL CLIENTE: " << endl;
	//getline(cin, nit);

CONDICION1:
	cout << endl << "INGRESE EL GENERO DEL CLIENTE (F o M): ";
	cin >> genero;

	if (genero != 'F') {
		if (genero != 'f') {
			if (genero != 'M') {
				if (genero != 'm') {
					system("cls");
					cout << endl << "!!EL DATO INGRESADO ES INVALIDO!!" << endl;
					system("color 0c");
					goto CONDICION1;
				}
			}
		}
	}
	system("color 02");

	cin.ignore();
	cout << endl << "INGRESE EL TELEFONO DEL CLIENTE: ";
	getline(cin, telefono);
	cout << endl << "INGRESE EL CORREO ELECTRONICO DEL CLIENTE: ";
	getline(cin, correo);
	cin.ignore();

	Cliente C = Cliente(nombre, apellido, telefono, fechaing, genero, nit, correo, ID);

	C.crear();
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
			cin.ignore();
			cout << endl << "INGRESE EL NOMBRE DEL CLIENTE: " << endl;
			getline(cin, nombre);
			cout << endl << "INGRESE EL APELLIDO DEL CLIENTE: " << endl;
			getline(cin, apellido);
			cout << endl << "INGRESE EL NIT DEL CLIENTE: " << endl;
			getline(cin, nit);

		CONDICION:
			cout << endl << "INGRESE EL GENERO DEL CLIENTE (F o M): " << endl;
			cin >> genero;
			
			if (genero != 'F') {
				if (genero != 'f') {
					if (genero != 'M') {
						if (genero != 'm') {
							system("cls");
							cout << endl << "!!EL DATO INGRESADO ES INVALIDO!!" << endl;
							system("color 0c");
							goto CONDICION;
						}
					}
				}
			}
			system("color 02");
			cin.ignore();
			cout << endl << "INGRESE EL TELEFONO DEL CLIENTE: " << endl;
			getline(cin, telefono);
			cout << endl << "INGRESE EL CORREO ELECTRONICO DEL CLIENTE: " << endl;
			getline(cin, correo);
			cin.ignore();

			Cliente c = Cliente(nombre, apellido, telefono, fechaing, genero, nit, correo, ID);

			c.actualizar();


			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }
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
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }

		}break;
		case 3: {

			Cliente C = Cliente();
			C.leer();
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }

		} break;
		case 4: {
			cin.ignore();
			/*cout << endl << "INGRESE EL NIT DEL CLIENTE: " << endl;
			getline(cin, nit);
			agregar_un_cliente(nit);*/
			
			cout<<endl << "INGRESE EL NOMBRE DEL CLIENTE: ";
			getline(cin,nombre);
			cout << endl << "INGRESE EL APELLIDO DEL CLIENTE: ";
			getline(cin, apellido);
			cout << endl << "INGRESE EL NIT DEL CLIENTE: ";
			getline(cin, nit);

		CONDICION1:
			cout << endl << "INGRESE EL GENERO DEL CLIENTE (F o M): ";
			cin >> genero;

			if (genero != 'F') {
				if (genero != 'f') {
					if (genero != 'M') {
						if (genero != 'm') {
							system("cls");
							cout << endl << "!!EL DATO INGRESADO ES INVALIDO!!" << endl;
							system("color 0c");
							goto CONDICION1;
						}
					}
				}
			}
			system("color 02");

			cin.ignore();
			cout << endl << "INGRESE EL TELEFONO DEL CLIENTE: ";
			getline(cin, telefono);
			cout << endl << "INGRESE EL CORREO ELECTRONICO DEL CLIENTE: ";
			getline(cin, correo);
			cin.ignore();

			Cliente C = Cliente(nombre,apellido,telefono,fechaing,genero,nit,correo,ID);

			C.crear();
			
			cout << "\n" << endl;
			system("pause");
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); menu_Principal(); break; default: system("exit"); }


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
			//cout << "Digite la fecha cuando ingreso el producto ( " + producto + " ) en formato YYYY-MM-DD "; cin >> fecha_ingreso;

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
		case 1: {
			system("cls");
			Proveedor P = Proveedor();
			P.leer();
			cout << endl << "-------------------------------------------------------------------" << endl;
			cout << endl << "Ingrese la ID del Proveedor que desea actualizar: ";
			cin >> ID;
			cout << endl;
			cout << "-----------A continuacion ingrese los nuevos datos para reemplazar---------" << endl << endl;
			cin.ignore();
			cout << "INGRESE EL NOMBRE DEL PROVEEDOR" << endl;
			getline(cin, nombre);
			cout << "INGRESE EL NIT DEL PROVEEDOR" << endl;
			getline(cin, nit);
			cout << "INGRESE LA DIRECCION DEL PROVEEDOR" << endl;
			getline(cin, direccion);
			cout << "INGRESE EL TELEFONO DEL PROVEEDOR" << endl;
			getline(cin, telefono);
			cin.ignore();

			

			Proveedor p = Proveedor(nombre, nit, direccion, telefono,ID);
			p.actualizar();

			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }
		} break;
		case 2: {
			system("cls");

			Proveedor P = Proveedor();
			P.leer();

			Proveedor p = Proveedor();
			p.eliminar();

			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }

		}break;
		case 3: {

			Proveedor P = Proveedor();
			P.leer();

			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; default:system("exit"); }

		} break;
		case 4: {

			cin.ignore();
			cout << "INGRESE EL NOMBRE DEL PROVEEDOR QUE DESEA INSERTAR" << endl;
			getline(cin, nombre);
			cout << "INGRESE EL NIT DEL PROVEEDOR QUE DESEA INSERTAR" << endl;
			getline(cin, nit);
			cout << "INGRESE LA DIRECCION DEL PROVEEDOR QUE DESEA INSERTAR" << endl;
			getline(cin, direccion);
			cout << "INGRESE EL TELEFONO DEL PROVEEDOR QUE DESEA INSERTAR" << endl;
			getline(cin, telefono);
			cin.ignore();

			Proveedor P	 = Proveedor(nombre,nit,direccion,telefono,ID);

			P.crear();

			system("pause");
			cout << endl << endl << "*si desea regresar al menu principal ingrese: 1, para salir ingrese 2*" << endl;
			cin >> op1;
		switch (op1) { case 1: system("cls"); main(); break; system("exit"); }


		} break;
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
