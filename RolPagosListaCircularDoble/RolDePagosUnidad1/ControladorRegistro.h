#pragma once
#include "ListaCircularDoble.h"

#include "Empleado.h"
#include "RolDePago.h"

class ControladorRegistro {
public:

	// Funcion para registrar empleados
	void registrarEmpleado();

	// Funcion para registrar rol de pagos
	void registrarRolPago();


	ListaCircularDoble<Empleado> leerEmpleadosLC();
	void guardarEmpleado(Empleado empleadoLC);
	void eliminarEmpleado();

	ListaCircularDoble<RolDePago> leerRolDePagoLC();
	void guardarRolDePago(RolDePago roldepagoLC);
	void eliminarRolDePago();

};
