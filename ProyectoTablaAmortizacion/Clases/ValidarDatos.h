/***********************************************************************
 * Module:  ValidarDatos.h
 * Author:  Intel
 * Modified: domingo, 6 de noviembre de 2022 0:05:42
 * Purpose: Declaration of the class ValidarDatos
 ***********************************************************************/

 /**
 * @file ValidarDatos.h
  * @version 1.0
 * @date 06/11/2022
 * @autor DavidCantunia
 * @title Funciones Ingreso Datos
 * @brief Funciones de utileria
 * @code
   int main(){
    int meses = obj1.validarEntero("Ingrese en numero de meses: ");
    double saldo = obj1.validarDoubles("Ingrese el monto a pedir: ");
    string mensaje = obj1.validarLetras("Ingrese el mensaje: ");
   }
 * @endconde
 */

#if !defined(__TablaAmortizacion_ValidarDatos_h)
#define __TablaAmortizacion_ValidarDatos_h

#pragma once
#include <string>

class ValidarDatos{
public:
/**
* @brief validarEntero restringe el ingreso de enteros
* @param mensaje Mensaje a convertir
* @return Devuelve un numero entero
*/
    int validarEntero(const char* mensaje);

/**
* @brief validarDoubles restringe el ingreso double/float
* @param mensaje Mensaje a convertir
* @return Devuelve un numero float
*/
    float validarDoubles(const char* mensaje);

/**
* @brief validarLetras restringe el uso de solo letras
* @param mensaje Mensaje a convertir
* @return Devuelve un string
*/
    std::string validarLetras(const char* mensaje);
protected:
private:

};

#endif