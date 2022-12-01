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
		Utileria::mostrar_mensaje("No se encontraron empleados registrados", TipoMensaje::Informativo);
		return;
	}

	empleados.recorrer([](Empleado cliente) {
		std::cout << "cedula    : " << cliente.getCedula() << std::endl;
		std::cout << "nombres   : " << cliente.getNombre() << std::endl;
		std::cout << "apellido  : " << cliente.getApellido() << std::endl;
		std::cout << "cargo     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}

void ControladorReportes::mostrarRolDePago() {
	auto rolPagos = controladorRegistro.leerRolDePagoLC();

	if (rolPagos.estaVacio()) {
		Utileria::mostrar_mensaje("No se encontraron roles de pago registrados", TipoMensaje::Informativo);
		return;
	}

	rolPagos.recorrer([](RolDePago cliente) {
		std::cout << "cedula    : " << cliente.getEmpleado().getCedula() << std::endl;
		std::cout << "nombres   : " << cliente.getEmpleado().getNombre() << std::endl;
		std::cout << "apellido : " << cliente.getEmpleado().getApellido() << std::endl;
		std::cout << "cargo     : " << cliente.getEmpleado().getCargo() << std::endl;
		std::cout << "INFORMACION ROL PAGO:" << std::endl;
		std::cout << "Salario unificado     :  " << cliente.getSueldo() << std::endl;
		std::cout << "Salario horas extras  :  " << cliente.getHorasExtras() << std::endl;
		std::cout << "sub total             :  " << cliente.getSubTotal() << std::endl;
		std::cout << "fondos de reserva     :  " << cliente.getFondosReserva() << std::endl;
		std::cout << "total de ingreses     :  " << cliente.getTotalIngresos() << std::endl;
		std::cout << "retencion iess        :  " << cliente.getRetencionIess() << std::endl;
		std::cout << "prestamo iess         :  " << cliente.getPrestamoIess() << std::endl;
		std::cout << "total retencion       :  " << cliente.getTotalRetencion() << std::endl;
		std::cout << "sueldo neto a recibir :  " << cliente.getNetoRecibir() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}

void ControladorReportes::buscarRolDePago() {
	auto empleados = controladorRegistro.leerRolDePagoLC();
	std::string cedula;
	NodoCircular<RolDePago>* encontrado;
	Fecha fechaS;

	if (empleados.estaVacio()) {
		Utileria::mostrar_mensaje("No se encontraron empleados registrados con un rol de pago", TipoMensaje::Informativo);
		return;
	}

	cedula = Utileria::leerCadena1("Ingrese la cedula: ", "^[0-9]{10}$");

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
	std::cout << "cedula    : " << empleado.getEmpleado().getCedula() << std::endl;
	std::cout << "nombres   : " << empleado.getEmpleado().getNombre() << std::endl;
	std::cout << "apellidos : " << empleado.getEmpleado().getApellido() << std::endl;
	std::cout << "cargo     : " << empleado.getEmpleado().getCargo() << std::endl;
	std::cout << "INFORMACION ROL PAGO:" << std::endl;
	std::cout << "salario unificado     :  " << empleado.getSueldo() << std::endl;
	std::cout << "salario horas extras  :  " << empleado.getHorasExtras() << std::endl;
	std::cout << "sub total             :  " << empleado.getSubTotal() << std::endl;
	std::cout << "fondos de reserva     :  " << empleado.getFondosReserva() << std::endl;
	std::cout << "total de ingresos     :  " << empleado.getTotalIngresos() << std::endl;
	std::cout << "retencion iess        :  " << empleado.getRetencionIess() << std::endl;
	std::cout << "prestamo iess         :  " << empleado.getPrestamoIess() << std::endl;
	std::cout << "total de retencion    :  " << empleado.getTotalRetencion() << std::endl;
	std::cout << "sueldo neto a recibir :  " << empleado.getNetoRecibir() << std::endl;
	std::cout << "---------------------------------------------------------------" << std::endl;
}