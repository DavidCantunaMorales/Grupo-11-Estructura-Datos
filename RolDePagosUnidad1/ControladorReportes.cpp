
#include "ControladorReportes.h"
#include "ControladorRegistro.h"
#include "Utileria.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

void ControladorReportes::mostrarClientes() {
	auto clientes = controladorRegistro.leerClientes();

	clientes.recorrer([](Empleado cliente) {
		std::cout << "CEDULA    : " << cliente.getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::mostrarRolDePago() {
	auto clientes = controladorRegistro.leerRolDePago();
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
	auto clientes = controladorRegistro.leerRolDePago();
	std::string cedula;
	NodoCircular<RolDePago>* encontrado;

	if (clientes.estaVacio()) {
		Utileria::mostrar_mensaje("No se encontraron clientes registrados", TipoMensaje::Error);
		return;
	}

	do {
		cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utileria::cedula_valida(cedula)) {
			Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		encontrado = clientes.buscar([cedula](RolDePago c) {
			return c.getEmpleado().getCedula() == cedula;
			});

		if (!encontrado) {
			Utileria::mostrar_mensaje("Cedula no registrada", TipoMensaje::Error);
			continue;
		}

		break;
	} while (true);

	RolDePago cliente = encontrado->getValor();

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
}




void ControladorReportes::mostrarClientesLD() {
	auto clientes = controladorRegistro.leerEmpleadoLD();

	clientes.recorrerLD([](Empleado cliente) {
		std::cout << "CEDULA    : " << cliente.getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::mostrarRolDePagoLD() {
	auto clientes = controladorRegistro.leerRolDePagoLD();
	clientes.recorrerLD([](RolDePago cliente) {
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
	auto clientes = controladorRegistro.leerRolDePagoLD();
	std::string cedula;
	NodoDoble<RolDePago>* encontrado;

	if (clientes.estaVacioLD()) {
		Utileria::mostrar_mensaje("No se encontraron clientes registrados", TipoMensaje::Error);
		return;
	}

	do {
		cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utileria::cedula_valida(cedula)) {
			Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		encontrado = clientes.buscarLD([cedula](RolDePago c) {
			return c.getEmpleado().getCedula() == cedula;
			});

		if (!encontrado) {
			Utileria::mostrar_mensaje("Cedula no registrada", TipoMensaje::Error);
			continue;
		}

		break;
	} while (true);

	RolDePago cliente = encontrado->getValor();

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
}



void ControladorReportes::mostrarClientesLS() {
	auto clientes = controladorRegistro.leerEmpleadoLS();

	clientes.recorrerLS([](Empleado cliente) {
		std::cout << "CEDULA    : " << cliente.getCedula() << std::endl;
		std::cout << "NOMBRES   : " << cliente.getNombre() << std::endl;
		std::cout << "APELLIDOS : " << cliente.getApellido() << std::endl;
		std::cout << "CARGO     : " << cliente.getCargo() << std::endl;
		std::cout << "---------------------------------------------------------------" << std::endl;
		});
}
void ControladorReportes::mostrarRolDePagoLS() {
	auto clientes = controladorRegistro.leerRolDePagoLS();
	clientes.recorrerLS([](RolDePago cliente) {
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
	auto clientes = controladorRegistro.leerRolDePagoLS();
	std::string cedula;
	NodoSimple<RolDePago>* encontrado;

	if (clientes.estaVacioLS()) {
		Utileria::mostrar_mensaje("No se encontraron clientes registrados", TipoMensaje::Error);
		return;
	}

	do {
		cedula = Utileria::leer_cadena_regex("Ingrese la cedula: ", "^[0-9]{10}$");

		if (!Utileria::cedula_valida(cedula)) {
			Utileria::mostrar_mensaje("Cedula invalida", TipoMensaje::Error);
			continue;
		}

		encontrado = clientes.buscarLS([cedula](RolDePago c) {
			return c.getEmpleado().getCedula() == cedula;
			});

		if (!encontrado) {
			Utileria::mostrar_mensaje("Cedula no registrada", TipoMensaje::Error);
			continue;
		}

		break;
	} while (true);

	RolDePago cliente = encontrado->getValor();

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
}

