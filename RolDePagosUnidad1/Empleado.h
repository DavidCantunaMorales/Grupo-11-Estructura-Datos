/**
 * @file Empleado.h
 * @author Cantuña David
 * @brief Clase Empleado
 * @version 1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */


#pragma once
#include <iostream>
#include <string>

class Empleado{
private:
	std::string nombre;
	std::string apellido;
	std::string cedula;
	std::string cargo;

public:

	/**
	 * @brief Constructor Empleado
	 * @param nombre
	 * @param apellido
	 * @param cedula
	 * @param cargo
	 */
	Empleado(std::string, std::string, std::string, std::string);

	/**
	 * @brief Constructor por defecto Empleado
	 */
	Empleado();

	/**
	 * @brief getNombre
	 */
	std::string getNombre();

	/**
	 * @brief setNombre
	 */
	void setNombre(std::string newNombre);
	
	/**
	 * @brief getApellido
	 */
	std::string getApellido();

	/**
	 * @brief setApellido
	 */
	void setApellido(std::string newApellido);

	/**
	 * @brief getCedula
	 */
	std::string getCedula();

	/**
	 * @brief setCedula
	 */
	void setCedula(std::string newCedula);

	/**
	 * @brief getCargo
	 */
	std::string getCargo();

	/**
	 * @brief setCargo
	 */
	void setCargo(std::string newCargo);

	/**
	 * @brief imprimirDatos
	 */
	void imprimirDatos();

	/**
	 * @brief toString
	 */
	std::string	toString();
};
