#pragma warning(disable : 4996)

#include "ControladorReportes.h"
#include "ControladorRegistro.h"
#include "Utileria.h"
#include "Fecha.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


Fecha fechaS;


void ControladorReportes::mostrarClientesLC() {
	auto empleados = controladorRegistro.leerEmpleadoLC();

	if (empleados.listaVacia()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Error);
		return;
	}

	empleados.recorrer([](Empleado cliente) {
		std::cout << "CEDULA    : " << cliente.getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::mostrarRolDePagoLC() {
	auto empleados = controladorRegistro.leerRolDePagoLC();

	if (empleados.listaVacia()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Error);
		return;
	}

	empleados.recorrer([](RolDePago cliente) {
		std::cout << "CEDULA    : " << cliente.getEmpleado().getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getEmpleado().getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getEmpleado().getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getEmpleado().getCargo() << std::endl;
		std::cout << "INFORMACION ROL PAGO:" << std::endl;
		std::cout << "    SALARIO UNIFICADO     :  " << cliente.getSueldo() << std::endl;
		std::cout << "    SALARIO HORAS EXTRAS  :  " << cliente.getHorasExtras() << std::endl;
		std::cout << "    SALARIO FERIADOS      :  " << cliente.getFeriados() << std::endl;
		std::cout << "    SUB TOTAL             :  " << cliente.getSubTotal() << std::endl;
		std::cout << "    FONDOS DE RESERVA     :  " << cliente.getFondosReserva() << std::endl;
		std::cout << "    TOTAL DE INGRESOS     :  " << cliente.getTotalIngresos() << std::endl;
		std::cout << "    RETENCION IESS        :  " << cliente.getRetencionIess() << std::endl;
		std::cout << "    PRESTAMO IESS         :  " << cliente.getPrestamoIess() << std::endl;
		std::cout << "    TOTAL DE RETENCION    :  " << cliente.getTotalRetencion() << std::endl;
		std::cout << "    SUELDO NETO A RECIBIR :  " << cliente.getNetoRecibir() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::buscarRolDePagoLC() {
	auto empleados = controladorRegistro.leerRolDePagoLC();
	std::string cedula;
	NodoCircular<RolDePago>* encontrado;

	if (empleados.listaVacia()) {
		Utileria::mostrar_mensaje("No se encontraron clientes registrados", TipoMensaje::Error);
		return;
	}

	if (empleados.listaVacia()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados con un rol de pago", TipoMensaje::Error);
		return;
	}

	cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

	if (!Utileria::cedula_valida(cedula)) {
		Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
		return;
	}

	encontrado = empleados.buscar([cedula](RolDePago c) {
		return c.getEmpleado().getCedula() == cedula;
		});

	if (!encontrado) {
		Utileria::mostrar_mensaje("No existe un rol de pagos con esa cedula", TipoMensaje::Error);
		return;
	}

	RolDePago empleado = encontrado->getValor();


	std::cout << "ROL DE PAGO INDIVIDUAL" << std::endl;
	fechaS.obtenerFechaSistema();
	std::cout << "CEDULA    : " << empleado.getEmpleado().getCedula() << std::endl;
	std::cout << "NOMBRES   : " << empleado.getEmpleado().getNombre() << std::endl;
	std::cout << "APELLIDOS : " << empleado.getEmpleado().getApellido() << std::endl;
	std::cout << "CARGO     : " << empleado.getEmpleado().getCargo() << std::endl;
	std::cout << "INFORMACION ROL PAGO:" << std::endl;
	std::cout << "    SALARIO UNIFICADO     :  " << empleado.getSueldo() << std::endl;
	std::cout << "    SALARIO HORAS EXTRAS  :  " << empleado.getHorasExtras() << std::endl;
	std::cout << "    SALARIO FERIADOS      :  " << empleado.getFeriados() << std::endl;
	std::cout << "    SUB TOTAL             :  " << empleado.getSubTotal() << std::endl;
	std::cout << "    FONDOS DE RESERVA     :  " << empleado.getFondosReserva() << std::endl;
	std::cout << "    TOTAL DE INGRESOS     :  " << empleado.getTotalIngresos() << std::endl;
	std::cout << "    RETENCION IESS        :  " << empleado.getRetencionIess() << std::endl;
	std::cout << "    PRESTAMO IESS         :  " << empleado.getPrestamoIess() << std::endl;
	std::cout << "    TOTAL DE RETENCION    :  " << empleado.getTotalRetencion() << std::endl;
	std::cout << "    SUELDO NETO A RECIBIR :  " << empleado.getNetoRecibir() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}




void ControladorReportes::mostrarClientesLD() {
	auto empleados = controladorRegistro.leerEmpleadoLD();

	if (empleados.estaVacioLD()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Error);
		return;
	}

	empleados.recorrerLD([](Empleado cliente) {
		std::cout << "CEDULA    : " << cliente.getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::mostrarRolDePagoLD() {
	auto empleados = controladorRegistro.leerRolDePagoLD();

	if (empleados.estaVacioLD()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Error);
		return;
	}

	empleados.recorrerLD([](RolDePago cliente) {
		std::cout << "CEDULA    : " << cliente.getEmpleado().getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getEmpleado().getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getEmpleado().getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getEmpleado().getCargo() << std::endl;
		std::cout << "INFORMACION ROL PAGO:" << std::endl;
		std::cout << "    SALARIO UNIFICADO     :  " << cliente.getSueldo() << std::endl;
		std::cout << "    SALARIO HORAS EXTRAS  :  " << cliente.getHorasExtras() << std::endl;
		std::cout << "    SALARIO FERIADOS      :  " << cliente.getFeriados() << std::endl;
		std::cout << "    SUB TOTAL             :  " << cliente.getSubTotal() << std::endl;
		std::cout << "    FONDOS DE RESERVA     :  " << cliente.getFondosReserva() << std::endl;
		std::cout << "    TOTAL DE INGRESOS     :  " << cliente.getTotalIngresos() << std::endl;
		std::cout << "    RETENCION IESS        :  " << cliente.getRetencionIess() << std::endl;
		std::cout << "    PRESTAMO IESS         :  " << cliente.getPrestamoIess() << std::endl;
		std::cout << "    TOTAL DE RETENCION    :  " << cliente.getTotalRetencion() << std::endl;
		std::cout << "    SUELDO NETO A RECIBIR :  " << cliente.getNetoRecibir() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::buscarRolDePagoLD() {
	auto empleados = controladorRegistro.leerRolDePagoLD();
	std::string cedula;
	NodoDoble<RolDePago>* encontrado;

	if (empleados.estaVacioLD()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados con un rol de pago", TipoMensaje::Error);
		return;
	}

	cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");
	
	if (!Utileria::cedula_valida(cedula)) {
		Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
		return;
	}

	encontrado = empleados.buscarLD([cedula](RolDePago c) {
		return c.getEmpleado().getCedula() == cedula;
	});

	if (!encontrado) {
		Utileria::mostrar_mensaje("No existe un rol de pagos con esa cedula", TipoMensaje::Error);
		return;
	}

	
	RolDePago empleado = encontrado->getValor();

	std::cout << "ROL DE PAGO INDIVIDUAL" << std::endl;
	fechaS.obtenerFechaSistema();
	std::cout << "CEDULA    : " << empleado.getEmpleado().getCedula() << std::endl;
	std::cout << "NOMBRES   : " << empleado.getEmpleado().getNombre() << std::endl;
	std::cout << "APELLIDOS : " << empleado.getEmpleado().getApellido() << std::endl;
	std::cout << "CARGO     : " << empleado.getEmpleado().getCargo() << std::endl;
	std::cout << "INFORMACION ROL PAGO:" << std::endl;
	std::cout << "    SALARIO UNIFICADO     :  " << empleado.getSueldo() << std::endl;
	std::cout << "    SALARIO HORAS EXTRAS  :  " << empleado.getHorasExtras() << std::endl;
	std::cout << "    SALARIO FERIADOS      :  " << empleado.getFeriados() << std::endl;
	std::cout << "    SUB TOTAL             :  " << empleado.getSubTotal() << std::endl;
	std::cout << "    FONDOS DE RESERVA     :  " << empleado.getFondosReserva() << std::endl;
	std::cout << "    TOTAL DE INGRESOS     :  " << empleado.getTotalIngresos() << std::endl;
	std::cout << "    RETENCION IESS        :  " << empleado.getRetencionIess() << std::endl;
	std::cout << "    PRESTAMO IESS         :  " << empleado.getPrestamoIess() << std::endl;
	std::cout << "    TOTAL DE RETENCION    :  " << empleado.getTotalRetencion() << std::endl;
	std::cout << "    SUELDO NETO A RECIBIR :  " << empleado.getNetoRecibir() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}



void ControladorReportes::mostrarClientesLS() {
	auto empleados = controladorRegistro.leerEmpleadoLS();

	if (empleados.estaVacioLS()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Error);
		return;
	}

	empleados.recorrerLS([](Empleado cliente) {
		std::cout << "CEDULA    : " << cliente.getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::mostrarRolDePagoLS() {
	auto empleados = controladorRegistro.leerRolDePagoLS();

	if (empleados.estaVacioLS()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Error);
		return;
	}

	empleados.recorrerLS([](RolDePago cliente) {
		std::cout << "CEDULA    : " << cliente.getEmpleado().getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getEmpleado().getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getEmpleado().getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getEmpleado().getCargo() << std::endl;
		std::cout << "INFORMACION ROL PAGO:" << std::endl;
		std::cout << "    SALARIO UNIFICADO     :  " << cliente.getSueldo() << std::endl;
		std::cout << "    SALARIO HORAS EXTRAS  :  " << cliente.getHorasExtras() << std::endl;
		std::cout << "    SALARIO FERIADOS      :  " << cliente.getFeriados() << std::endl;
		std::cout << "    SUB TOTAL             :  " << cliente.getSubTotal() << std::endl;
		std::cout << "    FONDOS DE RESERVA     :  " << cliente.getFondosReserva() << std::endl;
		std::cout << "    TOTAL DE INGRESOS     :  " << cliente.getTotalIngresos() << std::endl;
		std::cout << "    RETENCION IESS        :  " << cliente.getRetencionIess() << std::endl;
		std::cout << "    PRESTAMO IESS         :  " << cliente.getPrestamoIess() << std::endl;
		std::cout << "    TOTAL DE RETENCION    :  " << cliente.getTotalRetencion() << std::endl;
		std::cout << "    SUELDO NETO A RECIBIR :  " << cliente.getNetoRecibir() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::buscarRolDePagoLS() {
	auto empleados = controladorRegistro.leerRolDePagoLS();
	std::string cedula;
	NodoSimple<RolDePago>* encontrado;

	if (empleados.estaVacioLS()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados con un rol de pago", TipoMensaje::Error);
		return;
	}

	cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");
	
	if (!Utileria::cedula_valida(cedula)) {
		Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
		return;
	}

	encontrado = empleados.buscarLS([cedula](RolDePago c) {
		return c.getEmpleado().getCedula() == cedula;
	});

	if (!encontrado) {
		Utileria::mostrar_mensaje("No existe un rol de pagos con esa cedula", TipoMensaje::Error);
		return;
	}

	RolDePago empleado = encontrado->getValor();

	std::cout << "ROL DE PAGO INDIVIDUAL" << std::endl;
	fechaS.obtenerFechaSistema();
	std::cout << "CEDULA    : " << empleado.getEmpleado().getCedula() << std::endl;
	std::cout << "NOMBRES   : " << empleado.getEmpleado().getNombre() << std::endl;
	std::cout << "APELLIDOS : " << empleado.getEmpleado().getApellido() << std::endl;
	std::cout << "CARGO     : " << empleado.getEmpleado().getCargo() << std::endl;
	std::cout << "INFORMACION ROL PAGO:" << std::endl;
	std::cout << "    SALARIO UNIFICADO     :  " << empleado.getSueldo() << std::endl;
	std::cout << "    SALARIO HORAS EXTRAS  :  " << empleado.getHorasExtras() << std::endl;
	std::cout << "    SALARIO FERIADOS      :  " << empleado.getFeriados() << std::endl;
	std::cout << "    SUB TOTAL             :  " << empleado.getSubTotal() << std::endl;
	std::cout << "    FONDOS DE RESERVA     :  " << empleado.getFondosReserva() << std::endl;
	std::cout << "    TOTAL DE INGRESOS     :  " << empleado.getTotalIngresos() << std::endl;
	std::cout << "    RETENCION IESS        :  " << empleado.getRetencionIess() << std::endl;
	std::cout << "    PRESTAMO IESS         :  " << empleado.getPrestamoIess() << std::endl;
	std::cout << "    TOTAL DE RETENCION    :  " << empleado.getTotalRetencion() << std::endl;
	std::cout << "    SUELDO NETO A RECIBIR :  " << empleado.getNetoRecibir() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}


