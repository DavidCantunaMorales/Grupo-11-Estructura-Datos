/***********************************************************************
 * Module:  Tabla.h
 * Author:  Intel
 * Modified: domingo, 6 de noviembre de 2022 0:09:18
 * Purpose: Declaration of the class Tabla
 ***********************************************************************/

/**
* @file Tabla.h
* @version 1.0
* @date 06/11/2022
* @autor DavidCantunia
* @title Clase Tabla Amortizacion
* @brief Clase para el calculo tabla de amortizacion de prestamos
* @code
  int main(){
   const double pago = t1.calcularPago(saldo, interes, meses);
   saldo = t1.calcularTablaAmortizacion(saldo, pago, interes, meses, cnt, d, m, a);
   return 0;
  }
* @endconde
*/


#if !defined(__TablaAmortizacion_Tabla_h)
#define __TablaAmortizacion_Tabla_h

class Tabla{
public:

/**
* @brief Constructor de Tabla
* @param saldo
* @param interes
* @param mes
* @param d
* @param m
* @param a
*/
   Tabla(double saldo, double interes, int meses, int d, int m, int a);

/**
* @brief Constructor por defecto de Tabla
*/
   Tabla();

/**
* @brief Destructor por defecto de Tabla
*/
   ~Tabla();

/**
* @brief Getter del saldo
*/
   double getSaldo(void);

/**
* @brief Setter del saldo
*/
   void setSaldo(double newSaldo);

/**
* @brief Getter del interes
*/
   double getInteres(void);

/**
* @brief Setter del interes
*/
   void setInteres(double newInteres);

/**
* @brief Getter del mes
*/
   int getMeses(void);

/**
* @brief Setter del mes
*/
   void setMeses(int newMeses);

/**
* @brief Getter del dia
*/
   int getD(void);

/**
* @brief Setter del dia
*/
   void setD(int newD);

/**
* @brief Getter del mesPrestamo
*/
   int getM(void);

/**
* @brief Setter del mesPrestamo
*/
   void setM(int newM);

/**
* @brief Getter del anio
*/
   int getA(void);

/**
* @brief Setter del anio
*/
   void setA(int newA);

/**
* @brief Obtiene el valor del pago para la tabla de amortizacion
* @param saldo
* @param interes
* @param mes
* @return Valor calculado
*/
   double calcularPago(double saldo, double interes, int mes);

/**
* @brief Actualiza el valor del saldo a pagar y muestra la tabla de amortizacion
* 
* @param saldo
* @param pago
* @param interes
* @param meses
* @param d
* @param m
* @param a
* @return Los datos de la tabla de amortizacion
*/
   void tablaAmortizacion(double saldo, double pago, double interes, int meses, int d, int m, int a);

   void imprimirInformacion(double saldo, double interes, double meses, int d, int m, int a);

protected:

private:
   double saldo;
   double interes;
   int meses;
   int d;
   int m;
   int a;
};

#endif