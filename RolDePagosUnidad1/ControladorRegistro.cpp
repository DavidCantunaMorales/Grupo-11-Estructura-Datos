#include "ControladorRegistro.h"
#include "Utileria.h"
#include "ValidarDatos.h"

#include <string>
#include <sstream>

using namespace std;

// INGRESO GENERAL
void ControladorRegistro::registrarEmpleado() {
	
	ValidarDatos val;

	std::string cedula;
	std::string nombres;
	std::string apellidos;
	std::string cargo;

	std::cout << "Registrar cliente:" << std::endl << std::endl;

	rewind(stdin);
	apellidos = val.validarLetras("Ingrese los apellidos: ");
	rewind(stdin);
	nombres = val.validarLetras("Ingrese los nombres: ");
	rewind(stdin);
	cargo = val.validarLetras("Ingrese el cargo: ");
	rewind(stdin);

	auto empleados = leerEmpleadoLC(); // listaCircular<T>* lc = new listaCircular();

	do {
		cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utileria::cedula_valida(cedula)) {
			Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		auto encontrado = empleados.buscar([cedula](Empleado c) {
			return c.getCedula() == cedula;
			});

		if (encontrado) {
			Utileria::mostrar_mensaje("Cedula ya registrada", TipoMensaje::Error);
			continue;
		}

		break;
	} while (true);

	Empleado empleado(nombres, apellidos, cedula, cargo);
	guardarEmpleadoLC(empleado);
	guardarEmpleadoLD(empleado);
	guardarEmpleadoLS(empleado);
	Utileria::mostrar_mensaje("Datos guardados", TipoMensaje::Correcto);
}
void ControladorRegistro::registrarRolPago() {

	ValidarDatos val;

	std::string cedula;
	auto empleados = leerEmpleadoLC(); // Lista tipo Empleado
	auto rolPagosE = leerRolDePagoLC();
	NodoCircular<Empleado>* encontrado;

	if (empleados.listaVacia()) {
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
			continue;
		}

		break;
	} while (true);

	float salarioR = val.validarDoubles("Ingrese el salario unificado: ");
	float horasR = val.validarDoubles("Ingrese el salario horas extras: ");
	float feriadoR = val.validarDoubles("Ingrese el salario por feriados: ");
	float prestamoR = val.validarDoubles("Ingrese el prestamo realizado al IESS: ");

	Empleado empleado = encontrado->getValor();
	RolDePago rolPagoE(empleado, salarioR, horasR, feriadoR, prestamoR);
	guardarRolDePagoLC(rolPagoE);
	guardarRolDePagoLD(rolPagoE);
	guardarRolDePagoLS(rolPagoE);
	Utileria::mostrar_mensaje("Datos guardados", TipoMensaje::Correcto);
}

// LISTA CIRCULARES
ListaCircularDoble<Empleado> ControladorRegistro::leerEmpleadoLC() {
	ListaCircularDoble<Empleado> empleados;

	Utileria::leer_lineas("EmpleadosLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodo(0)->getValor();
		std::string nombres = columnas.obtenerNodo(1)->getValor();
		std::string apellidos = columnas.obtenerNodo(2)->getValor();
		std::string cargo = columnas.obtenerNodo(3)->getValor();

		Empleado empleado(nombres, apellidos, cedula, cargo);
		empleados.insertarFinal(empleado);
	});

	return empleados;
}
void ControladorRegistro::guardarEmpleadoLC(Empleado emp) {
	auto empleados = leerEmpleadoLC();
	std::ofstream archivo("EmpleadosLC.txt", std::ios::trunc);

	empleados.recorrer([&](Empleado c) {
		archivo << c.toString() << std::endl;
	});

	archivo << emp.toString() << std::endl;
	archivo.close();
}
void ControladorRegistro::eliminarEmpleadoLC(){
	auto empleados = leerEmpleadoLC();
	NodoCircular<Empleado>* encontrado;

	if (empleados.listaVacia()) {
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

	eliminarRolDePagoCompletoLC(aux);

	remove("EmpleadosLC.txt");
	rename("Temp.txt", "EmpleadosLC.txt");
}

ListaCircularDoble<RolDePago> ControladorRegistro::leerRolDePagoLC() {
	ListaCircularDoble<RolDePago> rolPagosE;
	auto empleados = leerEmpleadoLC();

	Utileria::leer_lineas("RoldePagoLC.txt", [&](std::string linea, ListaCircularDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodo(0)->getValor();
		std::string salarioU = columnas.obtenerNodo(1)->getValor();
		std::string salarioH = columnas.obtenerNodo(2)->getValor();
		std::string feriadosU = columnas.obtenerNodo(3)->getValor();
		std::string prestamoI = columnas.obtenerNodo(8)->getValor();
		float salarioU1 = std::stof(salarioU);
		float salarioH1 = std::stof(salarioH);
		float feriadosU1 = std::stof(feriadosU);
		float prestamoI1 = std::stof(prestamoI);

		auto encontrado = empleados.buscar([&](Empleado emp) {
			return emp.getCedula() == cedula;
			});

		if (!encontrado) {
			return;
		}

		Empleado empleado = encontrado->getValor();
		RolDePago rolPagoE(empleado, salarioU1, salarioH1, feriadosU1, prestamoI1);
		rolPagosE.insertarFinal(rolPagoE);
	});

	return rolPagosE;
}
void ControladorRegistro::guardarRolDePagoLC(RolDePago rolP) {
	auto rolPagosE = leerRolDePagoLC();
	std::ofstream archivo("RoldePagoLC.txt", std::ios::trunc);

	rolPagosE.recorrer([&](RolDePago a) {
		archivo << a.toString() << std::endl;
		});

	archivo << rolP.toString() << std::endl;
	archivo.close();
}
void ControladorRegistro::eliminarRolDePagoLC(){
	auto rolPagos = leerRolDePagoLC();
	NodoCircular<RolDePago>* encontrado;

	if (rolPagos.listaVacia()) {
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
void ControladorRegistro::eliminarRolDePagoCompletoLC(string aux) {
	auto rolPagos = leerRolDePagoLC();
	NodoCircular<RolDePago>* encontrado;

	if (rolPagos.listaVacia()) {
		Utileria::mostrar_mensaje("No existen rol de pagos registrados", TipoMensaje::Error);
		return;
	}

	//std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

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

// LISTAS DOBLES
ListaDoble<Empleado> ControladorRegistro::leerEmpleadoLD() {
	ListaDoble<Empleado> empleados;

	Utileria::leer_lineasLD("EmpleadosLD.txt", [&](std::string linea, ListaDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLD(0)->getValor();
		std::string nombres = columnas.obtenerNodoLD(1)->getValor();
		std::string apellidos = columnas.obtenerNodoLD(2)->getValor();
		std::string cargo = columnas.obtenerNodoLD(3)->getValor();

		Empleado empleado(nombres, apellidos, cedula, cargo);
		empleados.insertarFinalLD(empleado);
	});

	return empleados;
}
void ControladorRegistro::guardarEmpleadoLD(Empleado emp) {
	auto empleados = leerEmpleadoLD();
	std::ofstream archivo("EmpleadosLD.txt", std::ios::trunc);

	empleados.recorrerLD([&](Empleado c) {
		archivo << c.toString() << std::endl;
	});

	archivo << emp.toString() << std::endl;
	archivo.close();
}
void ControladorRegistro::eliminarEmpleadoLD(){
	auto empleados = leerEmpleadoLD();
	NodoDoble<Empleado>* encontrado;

	if (empleados.estaVacioLD()) {
		Utileria::mostrar_mensaje("No existen empleados registrados", TipoMensaje::Error);
		return;
	}

	std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp.txt", std::ios::trunc);

	for (int i = 0; i < empleados.totalLD(); i++) {
		encontrado = empleados.obtenerNodoLD(i);
		Empleado emp = encontrado->getValor();
		if (aux == emp.getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << emp.toString() << std::endl;
		}
	}

	entrada.close();

	eliminarRolDePagoCompletoLD(aux);

	remove("EmpleadosLD.txt");
	rename("Temp.txt", "EmpleadosLD.txt");
}


ListaDoble<RolDePago> ControladorRegistro::leerRolDePagoLD() {
	ListaDoble<RolDePago> rolP;
	auto empleados = leerEmpleadoLD();

	Utileria::leer_lineasLD("RoldePagoLD.txt", [&](std::string linea, ListaDoble<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLD(0)->getValor();
		std::string salarioU = columnas.obtenerNodoLD(1)->getValor();
		std::string salarioH = columnas.obtenerNodoLD(2)->getValor();
		std::string feriadosU = columnas.obtenerNodoLD(3)->getValor();
		std::string prestamoI = columnas.obtenerNodoLD(8)->getValor();
		float salarioU1 = std::stof(salarioU);
		float salarioH1 = std::stof(salarioH);
		float feriadosU1 = std::stof(feriadosU);
		float prestamoI1 = std::stof(prestamoI);

		auto encontrado = empleados.buscarLD([&](Empleado emp) {
			return emp.getCedula() == cedula;
			});

		if (!encontrado) {
			return;
		}

		Empleado empleado = encontrado->getValor();
		RolDePago rolPago(empleado, salarioU1, salarioH1, feriadosU1, prestamoI1);
		rolP.insertarFinalLD(rolPago);
	});

	return rolP;
}
void ControladorRegistro::guardarRolDePagoLD(RolDePago rolpagos) {
	auto rolPagosE = leerRolDePagoLD();
	std::ofstream archivo("RoldePagoLD.txt", std::ios::trunc);

	rolPagosE.recorrerLD([&](RolDePago a) {
		archivo << a.toString() << std::endl;
		});

	archivo << rolpagos.toString() << std::endl;
	archivo.close();
}
void ControladorRegistro::eliminarRolDePagoLD() {
	auto rolPagos = leerRolDePagoLD();
	NodoDoble<RolDePago>* encontrado;

	if (rolPagos.estaVacioLD()) {
		Utileria::mostrar_mensaje("No existen rol de pagos registrados", TipoMensaje::Error);
		return;
	}

	std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp1.txt", std::ios::trunc);

	for (int i = 0; i < rolPagos.totalLD(); i++) {
		encontrado = rolPagos.obtenerNodoLD(i);
		RolDePago rol = encontrado->getValor();
		if (aux == rol.getEmpleado().getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << rol.toString() << std::endl;
		}
	}

	entrada.close();

	remove("RoldePagoLD.txt");
	rename("Temp1.txt", "RoldePagoLD.txt");
}
void ControladorRegistro::eliminarRolDePagoCompletoLD(string aux) {
	auto rolPagos = leerRolDePagoLD();
	NodoDoble<RolDePago>* encontrado;

	if (rolPagos.estaVacioLD()) {
		Utileria::mostrar_mensaje("No existen rol de pagos registrados", TipoMensaje::Error);
		return;
	}

	//std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp1.txt", std::ios::trunc);

	for (int i = 0; i < rolPagos.totalLD(); i++) {
		encontrado = rolPagos.obtenerNodoLD(i);
		RolDePago rol = encontrado->getValor();
		if (aux == rol.getEmpleado().getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << rol.toString() << std::endl;
		}
	}

	entrada.close();

	remove("RoldePagoLD.txt");
	rename("Temp1.txt", "RoldePagoLD.txt");
}

// LISTAS SIMPLES
ListaSimple<Empleado> ControladorRegistro::leerEmpleadoLS() {
	ListaSimple<Empleado> empleados;

	Utileria::leer_lineasLS("EmpleadosLS.txt", [&](std::string linea, ListaSimple<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLS(0)->getValor();
		std::string nombres = columnas.obtenerNodoLS(1)->getValor();
		std::string apellidos = columnas.obtenerNodoLS(2)->getValor();
		std::string cargo = columnas.obtenerNodoLS(3)->getValor();

		Empleado empleado(nombres, apellidos, cedula, cargo);
		empleados.insertarFinalLS(empleado);
	});

	return empleados;
}
void ControladorRegistro::guardarEmpleadoLS(Empleado emp) {
	auto empleados = leerEmpleadoLS();
	std::ofstream archivo("EmpleadosLS.txt", std::ios::trunc);

	empleados.recorrerLS([&](Empleado c) {
		archivo << c.toString() << std::endl;
	});

	archivo << emp.toString() << std::endl;
	archivo.close();
}
void ControladorRegistro::eliminarEmpleadoLS() {
	auto empleados = leerEmpleadoLS();
	NodoSimple<Empleado>* encontrado;

	if (empleados.estaVacioLS()) {
		Utileria::mostrar_mensaje("No existen empleados registrados", TipoMensaje::Error);
		return;
	}

	std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp.txt", std::ios::trunc);

	for (int i = 0; i < empleados.totalLS(); i++) {
		encontrado = empleados.obtenerNodoLS(i);
		Empleado emp = encontrado->getValor();
		if (aux == emp.getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << emp.toString() << std::endl;
		}
	}

	entrada.close();

	eliminarRolDePagoCompletoLS(aux);

	remove("EmpleadosLS.txt");
	rename("Temp.txt", "EmpleadosLS.txt");
}

ListaSimple<RolDePago> ControladorRegistro::leerRolDePagoLS() {
	ListaSimple<RolDePago> rolP;
	auto empleados = leerEmpleadoLS();

	Utileria::leer_lineasLS("RoldePagoLS.txt", [&](std::string linea, ListaSimple<std::string> columnas) {
		std::string cedula = columnas.obtenerNodoLS(0)->getValor();
		std::string salarioU = columnas.obtenerNodoLS(1)->getValor();
		std::string salarioH = columnas.obtenerNodoLS(2)->getValor();
		std::string feriadosU = columnas.obtenerNodoLS(3)->getValor();
		std::string prestamoI = columnas.obtenerNodoLS(8)->getValor();
		float salarioU1 = std::stof(salarioU);
		float salarioH1 = std::stof(salarioH);
		float feriadosU1 = std::stof(feriadosU);
		float prestamoI1 = std::stof(prestamoI);

		auto encontrado = empleados.buscarLS([&](Empleado cliente) {
			return cliente.getCedula() == cedula;
			});

		if (!encontrado) {
			return;
		}

		Empleado empleado = encontrado->getValor();
		RolDePago rolPago(empleado, salarioU1, salarioH1, feriadosU1, prestamoI1);
		rolP.insertarFinalLS(rolPago);
	});

	return rolP;
}
void ControladorRegistro::guardarRolDePagoLS(RolDePago rolpagos) {
	auto empleados = leerRolDePagoLS();
	std::ofstream archivo("RoldePagoLS.txt", std::ios::trunc);

	empleados.recorrerLS([&](RolDePago a) {
		archivo << a.toString() << std::endl;
	});

	archivo << rolpagos.toString() << std::endl;
	archivo.close();
}
void ControladorRegistro::eliminarRolDePagoLS() {
	auto rolPagos = leerRolDePagoLS();
	NodoSimple<RolDePago>* encontrado;

	if (rolPagos.estaVacioLS()) {
		Utileria::mostrar_mensaje("No existen rol de pagos registrados", TipoMensaje::Error);
		return;
	}

	std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp1.txt", std::ios::trunc);

	for (int i = 0; i < rolPagos.totalLS(); i++) {
		encontrado = rolPagos.obtenerNodoLS(i);
		RolDePago rol = encontrado->getValor();
		if (aux == rol.getEmpleado().getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << rol.toString() << std::endl;
		}
	}

	entrada.close();

	remove("RoldePagoLS.txt");
	rename("Temp1.txt", "RoldePagoLS.txt");
}
void ControladorRegistro::eliminarRolDePagoCompletoLS(string aux) {
	auto rolPagos = leerRolDePagoLS();
	NodoSimple<RolDePago>* encontrado;

	if (rolPagos.estaVacioLS()) {
		Utileria::mostrar_mensaje("No existen rol de pagos registrados", TipoMensaje::Error);
		return;
	}

	//std::string aux = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	ofstream entrada;
	entrada.open("Temp1.txt", std::ios::trunc);

	for (int i = 0; i < rolPagos.totalLS(); i++) {
		encontrado = rolPagos.obtenerNodoLS(i);
		RolDePago rol = encontrado->getValor();
		if (aux == rol.getEmpleado().getCedula()) {
			std::cout << "Se ha eliminado el registro" << std::endl;
		}
		else {
			entrada << rol.toString() << std::endl;
		}
	}

	entrada.close();

	remove("RoldePagoLS.txt");
	rename("Temp1.txt", "RoldePagoLS.txt");
}