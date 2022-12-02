#pragma once
#include "ListaCircularDoble.h"
#include "ListaDoble.h"
#include "ListaSimple.h"

#include "Empleado.h"
#include "RolDePago.h"

class ControladorRegistro {
public:

	// FUNCIONES DE REGISTRO EMPLEADO Y ROL PAGO
	void registrarEmpleado();
	void registrarRolPago();

	// LISTAS CIRCULARES 
	ListaCircularDoble<Empleado> leerEmpleadoLC();
	void guardarEmpleadoLC(Empleado empleadoLC);
	void eliminarEmpleadoLC();


	ListaCircularDoble<RolDePago> leerRolDePagoLC();
	void guardarRolDePagoLC(RolDePago roldepagoLC);
	void eliminarRolDePagoLC();
	void eliminarRolDePagoCompletoLC(std::string cedula);

	// LISTAS DOBLES
	ListaDoble<Empleado> leerEmpleadoLD();
	void guardarEmpleadoLD(Empleado empleadoLD);
	void eliminarEmpleadoLD();

	ListaDoble<RolDePago> leerRolDePagoLD();
	void guardarRolDePagoLD(RolDePago roldepagoLD);
	void eliminarRolDePagoLD();
	void eliminarRolDePagoCompletoLD(std::string cedula);

	// LISTAS SIMPLES
	ListaSimple<Empleado> leerEmpleadoLS();
	void guardarEmpleadoLS(Empleado empleadoLD);
	void eliminarEmpleadoLS();

	ListaSimple<RolDePago> leerRolDePagoLS();
	void guardarRolDePagoLS(RolDePago roldepagoLD);
	void eliminarRolDePagoLS();
	void eliminarRolDePagoCompletoLS(std::string cedula);
};
