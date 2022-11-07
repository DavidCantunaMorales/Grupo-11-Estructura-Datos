/***********************************************************************
 * Module:  Tabla.cpp
 * Author:  Intel
 * Modified: domingo, 6 de noviembre de 2022 0:09:18
 * Purpose: Implementation of the class Tabla
 ***********************************************************************/

#include "Tabla.h"

#include <iostream>
#include <iomanip>
#include <math.h>

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::Tabla(double sald, double inter, int mes, int dia, int me, int anio)
// Purpose:    Implementation of Tabla::Tabla()
// Parameters:
// - sald
// - inter
// - mes
// - dia
// - me
// - anio
// Return:     
////////////////////////////////////////////////////////////////////////

/**
* @brief Constructor de Tabla
* @param saldo
* @param interes
* @param mes
* @param d
* @param m
* @param a
*/

Tabla::Tabla(double sald, double inter, int mes, int dia, int me, int anio){
   this->saldo = sald;
   this->interes = inter;
   this->meses = mes;
   this->d = dia;
   this->m = me;
   this->a = anio;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::Tabla()
// Purpose:    Implementation of Tabla::Tabla()
// Return:     
////////////////////////////////////////////////////////////////////////

/**
 * @brief Construct a new Tabla:: Tabla object
 * 
 */
Tabla::Tabla(){
   this->saldo = NULL;
   this->interes = NULL;
   this->meses = NULL;
   this->d = NULL;
   this->m = NULL;
   this->a = NULL;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::~Tabla()
// Purpose:    Implementation of Tabla::~Tabla()
// Return:     
////////////////////////////////////////////////////////////////////////

/**
* @brief Destructor por defecto de Tabla
*/
Tabla::~Tabla(){
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::getSaldo()
// Purpose:    Implementation of Tabla::getSaldo()
// Return:     double
////////////////////////////////////////////////////////////////////////

/**
* @brief Getter del saldo
*/
double Tabla::getSaldo(void){
   return saldo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::setSaldo(double newSaldo)
// Purpose:    Implementation of Tabla::setSaldo()
// Parameters:
// - newSaldo
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
* @brief Setter del saldo
*/
void Tabla::setSaldo(double newSaldo){
   saldo = newSaldo;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::getInteres()
// Purpose:    Implementation of Tabla::getInteres()
// Return:     double
////////////////////////////////////////////////////////////////////////

/**
* @brief Getter del interes
*/
double Tabla::getInteres(void){
   return interes;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::setInteres(double newInteres)
// Purpose:    Implementation of Tabla::setInteres()
// Parameters:
// - newInteres
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
* @brief Setter del interes
*/
void Tabla::setInteres(double newInteres){
   interes = newInteres;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::getMeses()
// Purpose:    Implementation of Tabla::getMeses()
// Return:     int
////////////////////////////////////////////////////////////////////////

/**
* @brief Getter del mes
*/
int Tabla::getMeses(void){
   return meses;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::setMeses(int newMeses)
// Purpose:    Implementation of Tabla::setMeses()
// Parameters:
// - newMeses
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
* @brief Setter del mes
*/
void Tabla::setMeses(int newMeses){
   meses = newMeses;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::getD()
// Purpose:    Implementation of Tabla::getD()
// Return:     int
////////////////////////////////////////////////////////////////////////

/**
* @brief Getter del dia
*/
int Tabla::getD(void){
   return d;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::setD(int newD)
// Purpose:    Implementation of Tabla::setD()
// Parameters:
// - newD
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
* @brief Setter del dia
*/
void Tabla::setD(int newD){
   d = newD;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::getM()
// Purpose:    Implementation of Tabla::getM()
// Return:     int
////////////////////////////////////////////////////////////////////////

/**
* @brief Getter del mesPrestamo
*/
int Tabla::getM(void){
   return m;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::setM(int newM)
// Purpose:    Implementation of Tabla::setM()
// Parameters:
// - newM
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
* @brief Setter del mesPrestamo
*/
void Tabla::setM(int newM){
   m = newM;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::getA()
// Purpose:    Implementation of Tabla::getA()
// Return:     int
////////////////////////////////////////////////////////////////////////


/**
* @brief Getter del anio
*/
int Tabla::getA(void){
   return a;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::setA(int newA)
// Purpose:    Implementation of Tabla::setA()
// Parameters:
// - newA
// Return:     void
////////////////////////////////////////////////////////////////////////

/**
* @brief Setter del anio
*/
void Tabla::setA(int newA){
   a = newA;
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::calcularPago(double saldo, double interes, int mes)
// Purpose:    Implementation of Tabla::calcularPago()
// Parameters:
// - saldo
// - interes
// - mes
// Return:     double
////////////////////////////////////////////////////////////////////////

/**
* @brief Obtiene el valor del pago para la tabla de amortizacion
* @param saldo
* @param interes
* @param mes
* @return Valor calculado
*/

double Tabla::calcularPago(double saldo, double interes, int mes){
    return saldo * ((interes / mes) / (1 - (pow((1 + (interes / mes)), -mes))));
}

////////////////////////////////////////////////////////////////////////
// Name:       Tabla::calcularTablaAmortizacion(double saldo, double pago, double interes, int meses, int cnt, int d, int m, int a)
// Purpose:    Implementation of Tabla::calcularTablaAmortizacion()
// Parameters:
// - saldo
// - pago
// - interes
// - meses
// - cnt
// - d
// - m
// - a
// Return:     double
////////////////////////////////////////////////////////////////////////

/**
* @brief Actualiza el valor del saldo a pagar y muestra la tabla de amortizacion
* @param saldo
* @param pago
* @param interes
* @param meses
* @param d
* @param m
* @param a
* @return Datos de la tabla de amortizacion
*/
void Tabla::tablaAmortizacion(double saldo, double pago, double interes, int meses, int d, int m, int a){

   for (int i = 0; i < meses; i++) {

      double periodosInteres = saldo * (interes / meses);
      double amortizacion = pago - periodosInteres;
      double balance = saldo - amortizacion;

      saldo = balance;

      int contador = 0;

      contador++;

      if (m++ > 11) {
         contador = 1;
         m = contador;
         a++;
      }

      std::cout << std::fixed
            << std::setprecision(2)
            << std::setw(5)
            << d << " - " << m << " -  " << a
            << std::setw(20)
            << pago
            << std::setw(25)
            << periodosInteres
            << std::setw(25)
            << amortizacion
            << std::setw(25)
            << balance
            << '\n';
   }
}
