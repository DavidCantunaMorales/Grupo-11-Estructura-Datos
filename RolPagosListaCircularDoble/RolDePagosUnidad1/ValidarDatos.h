/**
 * @file ValidarDatos.h
 * @author Cantunia David
 * @brief Clase ValidarDatos
 * @version 1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <string>

class ValidarDatos
{
public:

	/**
	 * @brief validarEntero
	 * @param mensaje
	 */
	virtual int validarEntero(char  const* mensaje);
	/**
	 * @brief validarDoubles
	 * @param mensaje
	 */
	virtual float validarDoubles(char const* mensaje);
	/**
	 * @brief validarLetras
	 * @param mensaje
	 */
	virtual std::string validarLetras(char const* mensaje);
protected:
private:

};