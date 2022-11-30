#pragma warning(disable : 4996)

#include "ControladorReportes.h"
#include "ControladorRegistro.h"
#include "Utileria.h"
#include "Fecha.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


void ControladorReportes::mostrarClientes() {
	auto empleados = controladorRegistro.leerEmpleadosLC();

	if (empleados.estaVacio()) {
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

void ControladorReportes::mostrarRolDePago() {
	auto clientes = controladorRegistro.leerRolDePagoLC();
	clientes.recorrer([](RolDePago cliente) {
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

void ControladorReportes::buscarRolDePago() {
	auto empleados = controladorRegistro.leerRolDePagoLC();
	std::string cedula;
	NodoCircular<RolDePago>* encontrado;
	Fecha fechaS;

	if (empleados.estaVacio()) {
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