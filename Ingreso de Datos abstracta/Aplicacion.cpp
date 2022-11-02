/***********************************************************************
 * UFA - ESPE
 * ALUMNOS:  David Cantuña, Ariel Guevara
 * FECHA DE CREACION: domingo, 30 de octubre de 2022 
 * FECHA DE MOFICIACION: domingo, 30 de octubre de 2022 
 * ENUNCIADO: Creacion de una clases abtractas para el ingreso y validacion de datos tipo int, float, double, string
 ***********************************************************************/

#include <iostream>
#include "ValidarDatos1.cpp"
#include <string.h>

int main(int argc, char** argv){

    int valInt=0;
    float valFloat=0;

     ValidarDatos obj1;
    std::string dato;
    valInt = obj1.validarEntero("Ingrese su date");
    std::cout<<"\n"<<valInt;
    std::cout<<"\n";
    valFloat = obj1.validarDoubles("Ingrese su dato");
    std::cout<<"\n"<<valFloat;
    std::cout<<"\n";
    dato = obj1.validarLetras("\n\nIngrese su texto");
    std::cout<<"\n"<<dato;
    return 0;
}
