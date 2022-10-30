/***********************************************************************
 * UFA - ESPE
 * ALUMNOS:  David Cantuña, Ariel Guevara
 * FECHA DE CREACION: domingo, 30 de octubre de 2022 
 * FECHA DE MOFICIACION: domingo, 30 de octubre de 2022 
 * ENUNCIADO: Creacion de una clase interfaz para el ingreso y validacion de datos tipo int, float, double, string
 ***********************************************************************/

#include <iostream>
#include <string.h>
#include "Validar.h"

int main(int argc, char** argv) {
	Validar obj1;
    	char dato[10];
    	strcpy(dato,obj1.ingresoInt("Ingrese un dato Entero: "));
    	std::cout<<std::endl;
    	std::cout<<dato<<std::endl;
    	strcpy(dato,obj1.ingresoDouble("Ingrese un dato Flotante o Double: "));
    	std::cout<<std::endl;
    	std::cout<<dato<<std::endl;
    	strcpy(dato,obj1.ingresoString("Ingrese un Texto: "));
    	std::cout<<std::endl;
    	std::cout<<dato<<std::endl;
	return 0;
}
