/***********************************************************************
 * UFA - ESPE
 * ALUMNOS:  David Cantuña, Ariel Guevara
 * FECHA DE CREACION: domingo, 30 de octubre de 2022 
 * FECHA DE MOFICIACION: domingo, 30 de octubre de 2022 
 * ENUNCIADO: Creacion de una clase interfaz para el ingreso y validacion de datos tipo int, float, double, string
 ***********************************************************************/

#include <iostream>
#include "ValidarDatos1.cpp"
#include <string.h>

int main(int argc, char** argv){

    ValidarDatos1 obj1;
    char dato[10];
    strcpy(dato,obj1.validarDoubles("Ingrese su dato"));
    std::cout<<"\n"<<dato;
    strcpy(dato,obj1.validarEntero("Ingrese su dato"));
    std::cout<<"\n"<<dato;
    strcpy(dato,obj1.validarLetras("Ingrese su texto"));
    std::cout<<"\n"<<dato;
    return 0;
}
