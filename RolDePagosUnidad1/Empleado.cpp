#include "Empleado.h"
#include <iostream>

Empleado::Empleado(std::string nombre, std::string apellido, std::string cedula, std::string cargo){
	this->nombre = nombre;
	this->apellido = apellido;
	this->cedula = cedula;
	this->cargo = cargo;
}

Empleado::Empleado() {
	nombre = "";
	apellido = "";
	cedula = "";
	cargo = "";
}

std::string Empleado::getNombre(){
	return nombre;
}

void Empleado::setNombre(std::string newNombre){
	nombre = newNombre;
}

std::string Empleado::getApellido(){
	return apellido;
}

void Empleado::setApellido(std::string newApellido){
	apellido = newApellido;
}

std::string Empleado::getCedula(){
	return cedula;
}

void Empleado::setCedula(std::string newCedula){
	cedula = newCedula;
}

std::string Empleado::getCargo(){
	return this->cargo;
}

void Empleado::setCargo(std::string newCargo){
	cargo = newCargo;
}

void Empleado::imprimirDatos(){
	std::cout << "Nombres Completos: " << this->nombre << "\n";
	std::cout << "Apellidos Completos: " << this->apellido << "\n";
	std::cout << "Numero de cedula: " << this->cedula << "\n";
	std::cout << "Cargo en la empresa: " << this->cargo << "\n";
	std::cout << "\n";
}

std::string Empleado::toString(){
	return cedula + "," + nombre + "," + apellido + "," + cargo;
}
