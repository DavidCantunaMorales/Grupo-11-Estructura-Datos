/**
 * @file ControladorRegistro.h
 * @author Cantuña David
 * @brief Clase ControladorRegistro
 * @version 1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include "ListaCircularDoble.h"

#include "Empleado.h"
#include "RolDePago.h"

class ControladorRegistro {
public:

	// Funcion para registrar empleados
	
	/**
	 * @brief registrarEmpleado
	 */
	void registrarEmpleado();

	/**
	 * @brief registrarRolPago
	 */
	void registrarRolPago();

	/**
	 * @brief leerEmpleadosLC
	 * @return ListaCircularDoble<Empleado>
	 */
	ListaCircularDoble<Empleado> leerEmpleadosLC();

	/**
	 * @brief guardarEmpleado
	 * @param Empleado 
	 */
	void guardarEmpleado(Empleado empleadoLC);

	/**
	 * @brief eliminarEmpleado
	 */
	void eliminarEmpleado();

	/**
	 * @brief leerRolDePagoLC
	 * @return ListaCircularDoble<RolDePago>
	 */
	ListaCircularDoble<RolDePago> leerRolDePagoLC();

	/**
	 * @brief guardarRolDePago
	 * @param RolDePago
	 */
	void guardarRolDePago(RolDePago roldepagoLC);

	/**
	 * @brief eliminarRolDePago
	 */
	void eliminarRolDePago();

	/**
	 * @brief eliminarRolDePagoCompleto
	 * @param string cedula
	 */
	void eliminarRolDePagoCompleto(std::string);

};
