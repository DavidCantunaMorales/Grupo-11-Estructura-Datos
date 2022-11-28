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

	Empleado(std::string, std::string, std::string, std::string);

	Empleado();

	std::string getNombre();

	void setNombre(std::string newNombre);
	
	std::string getApellido();

	void setApellido(std::string newApellido);

	std::string getCedula();

	void setCedula(std::string newCedula);

	std::string getCargo();

	void setCargo(std::string newCargo);

	void imprimirDatos();

	std::string	toString();
};
