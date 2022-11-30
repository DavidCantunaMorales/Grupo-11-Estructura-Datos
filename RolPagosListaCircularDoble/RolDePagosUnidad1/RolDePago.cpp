#include "RolDePago.h"

#include <iostream>

#define porcentajeIes 0.0945
#define fondosRe 0.0833

RolDePago::RolDePago(Empleado empleado, float sueldo, float horasExtras, float feriados , float subTotal, float fondosReserva,
	               float totalIngresos, float retencionIess, float prestamoIess, float totalRetencion, float netoRecibir){

	this->empleado = empleado;
	this->sueldo = sueldo;
	this->horasExtras = horasExtras;
	this->feriados = feriados;
	this->subTotal = subTotal;
	this->fondosReserva = fondosReserva;
	this->totalIngresos = totalIngresos;
	this->retencionIess = retencionIess;
	this->prestamoIess = prestamoIess;
	this->totalRetencion = totalRetencion;
	this->netoRecibir = netoRecibir;
}

RolDePago::RolDePago(Empleado empleado, float sueldo, float horasExtras, float feriados, float prestamoIess) {
	this->empleado = empleado;
	this->sueldo = sueldo;
	this->horasExtras = horasExtras;
	this->feriados = feriados;
	this->subTotal = sueldo + horasExtras + feriados;
	this->fondosReserva = subTotal * fondosRe;
	this->totalIngresos = subTotal + fondosReserva;
	this->retencionIess = subTotal * porcentajeIes;
	this->prestamoIess = prestamoIess;
	this->totalRetencion = retencionIess + prestamoIess;
	this->netoRecibir = totalIngresos - totalRetencion;
}

float RolDePago::getSueldo(){
	return sueldo;
}

void RolDePago::setSueldo(float sueldo1){
	sueldo = sueldo1;
}

float RolDePago::getHorasExtras(){
	return horasExtras;
}

float RolDePago::getFeriados() {
	return feriados;
}

void RolDePago::setFeriados(float feriado) {
	feriados = feriado;
}

void RolDePago::setHorasExtras(float horasE){
	horasExtras = horasE;
}

float RolDePago::getSubTotal(){
	return subTotal;
}

void RolDePago::setSubTotal(float subT){
	subTotal = subT;
}

float RolDePago::getFondosReserva(){
	return fondosReserva;
}

void RolDePago::setFondosReserva(float fondosR){
	fondosReserva = fondosR;
}

float RolDePago::getTotalIngresos(){
	return totalIngresos;
}

void RolDePago::setTotalIngresos(float totalI){
	totalIngresos = totalI;
}

float RolDePago::getRetencionIess(){
	return retencionIess;
}

void RolDePago::setRetencionIess(float retencionesI){
	retencionIess = retencionesI;
}

float RolDePago::getPrestamoIess(){
	return prestamoIess;
}

void RolDePago::setPrestamoIess(float prestamoI){
	prestamoIess = prestamoI;
}

float RolDePago::getTotalRetencion(){
	return totalRetencion;
}

void RolDePago::setTotalRetencion(float totalR){
	totalRetencion = totalR;
}

float RolDePago::getNetoRecibir(){
	return netoRecibir;
}

void RolDePago::setNetoRecibir(float netoR){
	netoRecibir = netoR;
}

void RolDePago::imprimirDatos(){
	std::cout << "INFORMACION EMPLEADO" << std::endl;
	std::cout << "NUM CEDULA: " << empleado.getCedula() << std::endl;
	std::cout << "NOMBRE: " << empleado.getNombre() << std::endl;
	std::cout << "APELLIDO: " << empleado.getApellido() << std::endl;
	std::cout << "CARGO: " << empleado.getCargo() << std::endl;
	std::cout << "   INFORMACION ROL DE PAGO" << std::endl;
	std::cout << "       SUELDO " << sueldo << std::endl;
	std::cout << "       HORAS EXTRAS " << horasExtras << std::endl;
	std::cout << "       FERIADOS " << feriados << std::endl;
	std::cout << "       SUB TOTAL " << subTotal << std::endl;
	std::cout << "       FONDOS RESERVA " << fondosReserva << std::endl;
	std::cout << "       TOTAL INGRESOS " << totalIngresos << std::endl;
	std::cout << "       RETENCION IESS " << retencionIess << std::endl;
	std::cout << "       PRESTAMO IESS " << prestamoIess << std::endl;
	std::cout << "       TOTAL RETENCION " << totalRetencion << std::endl;
	std::cout << "       SUELDO NETO A RECIBIR " << netoRecibir << std::endl;
	std::cout << "\n";
}

std::string RolDePago::toString(){
	return empleado.getCedula() + "," +
		std::to_string(sueldo) + "," +
		std::to_string(horasExtras) + "," +
		std::to_string(feriados) + "," +
		std::to_string(subTotal) + "," +
		std::to_string(fondosReserva) + "," +
		std::to_string(totalIngresos) + "," +
		std::to_string(retencionIess) + "," +
		std::to_string(prestamoIess) + "," +
		std::to_string(totalRetencion) + "," +
		std::to_string(netoRecibir);
}


