#include "RolPagos.h"
#define porcentajeIes 0.0945;
#include <iostream>

RolPagos::RolPagos(Empleado empleado, float sueldo, float horasExtras, float feriados , float subTotal, float fondosReserva, 
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

RolPagos::RolPagos(Empleado empleado, float sueldo, float horasExtras, float feriados, float prestamoIess) {
	this->empleado = empleado;
	this->sueldo = sueldo;
	this->horasExtras = horasExtras;
	this->feriados = feriados;
	this->subTotal = sueldo + horasExtras + feriados;
	this->fondosReserva = subTotal / 12;
	this->totalIngresos = subTotal + fondosReserva;
	this->retencionIess = subTotal * porcentajeIes;
	this->prestamoIess = prestamoIess;
	this->totalRetencion = retencionIess + prestamoIess;
	this->netoRecibir = totalIngresos - totalRetencion;
}

float RolPagos::getSueldo(){
	return sueldo;
}

void RolPagos::setSueldo(float sueldo1){
	sueldo = sueldo1;
}

float RolPagos::getHorasExtras(){
	return horasExtras;
}

float RolPagos::getFeriados() {
	return feriados;
}

void RolPagos::setFeriados(float feriado) {
	feriados = feriado;
}

void RolPagos::setHorasExtras(float horasE){
	horasExtras = horasE;
}

float RolPagos::getSubTotal(){
	return subTotal;
}

void RolPagos::setSubTotal(float subT){
	subTotal = subT;
}

float RolPagos::getFondosReserva(){
	return fondosReserva;
}

void RolPagos::setFondosReserva(float fondosR){
	fondosReserva = fondosR;
}

float RolPagos::getTotalIngresos(){
	return totalIngresos;
}

void RolPagos::setTotalIngresos(float totalI){
	totalIngresos = totalI;
}

float RolPagos::getRetencionIess(){
	return retencionIess;
}

void RolPagos::setRetencionIess(float retencionesI){
	retencionIess = retencionesI;
}

float RolPagos::getPrestamoIess(){
	return prestamoIess;
}

void RolPagos::setPrestamoIess(float prestamoI){
	prestamoIess = prestamoI;
}

float RolPagos::getTotalRetencion(){
	return totalRetencion;
}

void RolPagos::setTotalRetencion(float totalR){
	totalRetencion = totalR;
}

float RolPagos::getNetoRecibir(){
	return netoRecibir;
}

void RolPagos::setNetoRecibir(float netoR){
	netoRecibir = netoR;
}

void RolPagos::imprimirDatos(){
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


