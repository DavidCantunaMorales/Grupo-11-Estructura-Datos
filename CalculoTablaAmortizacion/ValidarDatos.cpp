/***********************************************************************
 * Module:  ValidarDatos.cpp
 * Author:  Intel
 * Modified: domingo, 6 de noviembre de 2022 0:09:18
 * Purpose: Implementation of the class ValidarDatos
 ***********************************************************************/


#include <iostream>
#include <conio.h>
#include <string.h>

#include "ValidarDatos.h"

////////////////////////////////////////////////////////////////////////
// Name:       ValidarDatos::validarEntero(char const* mensaje)
// Purpose:    Implementation of ValidarDatos::validarEntero()
// Parameters:
// - mensaje
// Return:     int
////////////////////////////////////////////////////////////////////////

/**
* @brief validarEntero restringe el ingreso de enteros
* @param mensaje Mensaje a convertir
* @return Devuelve un numero entero
*/

int ValidarDatos::validarEntero(char const* mensaje) {
    std::string dato;
    char c;
    int i = 0, valor = 0;
    std::cout << mensaje << std::endl;
    while ((c = _getch()) != 13) {
        if ((c >= '0' && c <= '9') || c == 8) {
            if (c == 8) {
                dato.erase(i - 1);
                i--;
                std::cout << "\b";
                std::cout << " ";
                std::cout << "\b";
            }
            else {
                std::cout << c;
                dato += c;
                i++;
            }
        }
    }
    valor = stoi(dato);
    return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       ValidarDatos::validarDoubles(char const* mensaje)
// Purpose:    Implementation of ValidarDatos::validarDoubles()
// Parameters:
// - mensaje
// Return:     float
////////////////////////////////////////////////////////////////////////

/**
* @brief validarDoubles restringe el ingreso double/float
* @param mensaje Mensaje a convertir
* @return Devuelve un numero float
*/
float ValidarDatos::validarDoubles(char const* mensaje) {
    std::string dato;
    char c;
    int i = 0, it_punto = 0;
    float valor = 0;
    std::cout << mensaje << std::endl;
    while ((c = _getch()) != 13) {
        if ((c >= '0' && c <= '9') || c == '.' || c == 8) {
            if (c == 8) {
                if (dato[i - 1] == '.') {
                    it_punto = 0;
                }
                dato.erase(i - 1);
                i--;
                std::cout << "\b";
                std::cout << " ";
                std::cout << "\b";
            }
            else if (c != '.') {
                std::cout << c;
                dato += c;
                i++;
            }
            else {
                if (it_punto < 1) {
                    std::cout << c;
                    dato += c;
                    i++;
                    it_punto += 1;
                }
            }
        }
    }
    valor = stof(dato);
    return valor;
}

////////////////////////////////////////////////////////////////////////
// Name:       ValidarDatos::validarLetras(char const* mensaje)
// Purpose:    Implementation of ValidarDatos::validarLetras()
// Parameters:
// - mensaje
// Return:     std::string
////////////////////////////////////////////////////////////////////////

/**
* @brief validarLetras restringe el uso de solo letras
* @param mensaje Mensaje a convertir
* @return Devuelve un string
*/

std::string ValidarDatos::validarLetras(char const* mensaje) {
    std::string dato;
    char c;
    int i = 0;
    std::cout << mensaje << std::endl;
    while ((c = _getch()) != 13) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ' || c == 8) {
            if (c == 8) {
                dato.erase(i - 1);
                i--;
                std::cout << "\b";
                std::cout << " ";
                std::cout << "\b";
            }
            else {
                std::cout << c;
                dato += c;
                i++;
            }
        }
    }
    return dato;
}