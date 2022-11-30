#include "ControladorRegistro.h"
#include "Utileria.h"
#include "ValidarDatos.h"

#include <string>
#include <sstream>

using namespace std;

// INGRESO GENERAL
void ControladorRegistro::registrarEmpleado() {
	ValidarDatos val;
	// Declarar variables para el constructor Empleado
	std::string cedula;
	std::string nombres;
	std::string apellidos;
	std::string cargo;

	std::cout << "Registrar cliente:" << std::endl << std::endl;

	rewind(stdin);
	apellidos = val.validarLetras("Ingrese los apellidos: "); // validaciones
	rewind(stdin);
	nombres = val.validarLetras("Ingrese los nombres: "); // validaciones
	rewind(stdin);
	cargo = val.validarLetras("Ingrese el cargo: "); // validaciones
	rewind(stdin);
	// variable auto identifica el tipo de variable automaticamente
	// leerEmpleadosLC: lee el txt los datos guardados y los almacena en una lista que se asigna a clientes 
	auto empleados = leerEmpleadosLC(); // listaCircularDoble<Empleado> empleados = leerEmpleadosLC();

	do {
		// leer_cadena_regex en Utileria.h hace un cliclo que se rompe hasta que se ingrese un formato de cedula correcto 10 digitos
		cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		// validaciones 
		if (!Utileria::cedula_valida(cedula)) {
			Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		// usamos la variable auto que se le va a asignar un puntero NodoCircular<T>*	
		// empleados.buscar() es una funcion que retorna NodoCircular<T>*
		// Usa una funcion lamda en los [] van las variables de entorno que declaramos y queremos usar en el lamda en este caso estamos mandando la [cedula]
		// En () se mandan los parametros como cualquier funcion normal en este caso estamos mandando la variable T de tipo Empleado ya que es una plantilla                

		// A la funcion buscar estamos mandando como Empleado c y comparamos con la cedula ingresada en los [cedula]
		auto encontrado = empleados.buscar([cedula](Empleado c) {
			return c.getCedula() == cedula;
			// Comprarmos si las cedulas son iguales
		});

		// Si las cedulas son iguales no nos permite ingresar ya que ya existe ese empleado
		if (encontrado) {
			Utileria::mostrar_mensaje("Cedula ya registrada", TipoMensaje::Error);
			continue;
		}

		break;
	} while (true);

	Empleado empleado(nombres, apellidos, cedula, cargo);
	guardarEmpleado(empleado);
	Utileria::mostrar_mensaje("Datos guardados", TipoMensaje::Correcto);
}

void ControladorRegistro::registrarRolPago() {
	ValidarDatos val;
	std::string cedula;
	auto empleados = leerEmpleadosLC(); // Lista tipo Empleado
	auto rolPagosE = leerRolDePagoLC();
	NodoCircular<Empleado>* encontrado;

	if (empleados.estaVacio()) {
		Utileria::mostrar_mensaje("No existen empleados registrados", TipoMensaje::Error);
		return;
	}



	do {
		cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		auto encontrado1 = rolPagosE.buscar([cedula](RolDePago c) {
			return c.getEmpleado().getCedula() == cedula;
			// Comprarmos si las cedulas son iguales
		});

		if (encontrado1) {
			Utileria::mostrar_mensaje("Ya existe un rol de pago con esta cedula", TipoMensaje::Error);
			return;
		}

		if (!Utileria::cedula_valida(cedula)) {
			Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		encontrado = empleados.buscar([cedula](Empleado c) {
			return c.getCedula() == cedula;
		});

		if (!encontrado) {
			Utileria::mostrar_mensaje("Cedula no registrada", TipoMensaje::Error);
			return;
		}

		break;
	} while (true);


	float salarioR = val.validarDoubles("Ingrese el monto del salario: ");
	float horasR = val.validarDoubles("Ingrese el salario horas extras: ");
	float feriadoR = val.validarDoubles("Ingrese el salario por feriados: ");
	float prestamoR = val.validarDoubles("Ingrese el prestamo realizado al IESS: ");

	Empleado cliente = encontrado->getValor();
	RolDePago rolPagoE(cliente, salarioR, horasR, feriadoR, prestamoR);
	guardarRolDePago(rolPagoE);
	Utileria::mostrar_mensaje("Datos guardados", TipoMensaje::Correcto);
}

// LISTA CIRCULARES
ListaCircularDoble<Empleado> ControladorRegistro::leerEmpleadosLC() {
	ListaCircularDoble<Empleado> clientes;

	Utileria::leer_lineas("EmpleadosLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodo(0)->getValor();
		std::string nombres = columnas.obtenerNodo(1)->getValor();
		std::string apellidos = columnas.obtenerNodo(2)->getValor();
		std::string cargo = columnas.obtenerNodo(3)->getValor();

		Empleado cliente(nombres, apellidos, cedula, cargo);
		clientes.insertarFinal(cliente);

	});

	return clientes;
}

void ControladorRegistro::guardarEmpleado(Empleado cliente) {
	auto clientes = leerEmpleadosLC();
	std::ofstream archivo("EmpleadosLC.txt", std::ios::trunc);

	// El & nos permite usar todas las variables locales declaradas en la funcion en donde se encuentre el lamda en este caso
	// en guardarEmpleado & nos da acceso al std::ofstream archivo 

	clientes.recorrer([&](Empleado c) {
		archivo << c.toString() << std::endl;
	});

	archivo << cliente.toString() << std::endl;
	archivo.close();
}

void ControladorRegistro::eliminarEmpleado() {

	auto empleados = leerEmpleadosLC();
	NodoCircular<Empleado>* encontrado;

	if (empleados.estaVacio()) {
		Utileria::mostrar_mensaje("No existen empleados registrados", TipoMensaje::Error);
		return;
	}

	std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp.txt", std::ios::trunc);

	for (int i = 0; i < empleados.total(); i++) {
		encontrado = empleados.obtenerNodo(i);
		Empleado emp = encontrado->getValor();
		if (aux == emp.getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << emp.toString() << std::endl;
		}
	}

	entrada.close();
	
	eliminarRolDePago();

	remove("EmpleadosLC.txt");
	rename("Temp.txt", "EmpleadosLC.txt");
}

ListaCircularDoble<RolDePago> ControladorRegistro::leerRolDePagoLC() {
	ListaCircularDoble<RolDePago> rolPagos;
	auto empleados = leerEmpleadosLC();

	Utileria::leer_lineas("RoldePagoLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodo(0)->getValor();
		std::string salarioU = columnas.obtenerNodo(1)->getValor();
		std::string salarioH = columnas.obtenerNodo(2)->getValor();
		std::string feriadosU = columnas.obtenerNodo(3)->getValor();
		std::string prestamoI = columnas.obtenerNodo(8)->getValor();

		// transformamos los valores obtenidos de string a float y los alamacenamos en el constructor RolDePago
		float salarioU1 = std::stof(salarioU);
		float salarioH1 = std::stof(salarioH);
		float feriadosU1 = std::stof(feriadosU);
		float prestamoI1 = std::stof(prestamoI);

		// buscar la cedula ya registrada
		auto encontrado = empleados.buscar([&](Empleado cliente) {
			return cliente.getCedula() == cedula;
		});

		// por si no se encuentra la cedula
		if (!encontrado) {
			return;
		}

		Empleado empleado = encontrado->getValor();  // obtenemos los valores del Empleado
		RolDePago rolPago(empleado, salarioU1, salarioH1, feriadosU1, prestamoI1);
		rolPagos.insertarFinal(rolPago);

	});

	return rolPagos;
}

void ControladorRegistro::guardarRolDePago(RolDePago rolPago) {
	auto rolPagos = leerRolDePagoLC();
	std::ofstream archivo("RoldePagoLC.txt", std::ios::trunc);

	rolPagos.recorrer([&](RolDePago r) {
		archivo << r.toString() << std::endl;
	});

	archivo << rolPago.toString() << std::endl;
	archivo.close();
}

void ControladorRegistro::eliminarRolDePago(){
	auto rolPagos = leerRolDePagoLC();
	NodoCircular<RolDePago>* encontrado;
	
	if (rolPagos.estaVacio()) {
		Utileria::mostrar_mensaje("No existen rol de pagos registrados", TipoMensaje::Error);
		return;
	}
	
	std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp1.txt", std::ios::trunc);

	for (int i = 0; i < rolPagos.total(); i++) {
		encontrado = rolPagos.obtenerNodo(i);
		RolDePago rol = encontrado->getValor();
		if (aux == rol.getEmpleado().getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << rol.toString() << std::endl;
		}
	}

	entrada.close();

	remove("RoldePagoLC.txt");
	rename("Temp1.txt", "RoldePagoLC.txt");
}
