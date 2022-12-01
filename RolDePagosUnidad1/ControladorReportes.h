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
#include "ControladorRegistro.h"

class ControladorReportes {
private:
	ControladorRegistro controladorRegistro;

public:

	/**
	 * @brief mostrarClientes
	 */
	void mostrarClientes();
	/**
	 * @brief mostrarRolDePago
	 */
	void mostrarRolDePago();
	/**
	 * @brief buscarRolDePago
	 */
	void buscarRolDePago();

};
