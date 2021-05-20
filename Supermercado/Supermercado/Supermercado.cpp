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

int main(){
    int op, op1; // variables para las opciones de los switch
  
    cout << "\n\t     .:BIENVENIDO:. \n\n";
 

	cout << "*****************MENU******************" << endl << endl;
	cout << "SELECCIONE LA TABLA QUE DESEA EDITAR:" << endl << endl;
	cout << "Marcas...............................1" << endl;
	cout << "Clientes............................." << endl;
	cout << "ETC.................................." << endl;
	cout << "Salir................................" << endl << endl;
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
	};
		

   return 0;
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
