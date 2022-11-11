/***********************************************************************
 * Module:  Tabla.h
 * Author:  Ariel Guevara, David Cantuña
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
 * @brief getter de az
 * 
 * @return int 
 */
   int getAz();
/**
 * @brief setter de az
 * 
 * @param a 
 */
   void setAz(int a);
/**
 * @brief getter de Yz
 * 
 * @return int 
 */
   int getYz();
   /**
     * @brief setter de Yz
     * 
     * @param y 
     */
   void setYz(int y);
/**
 * @brief getter de mz
 * 
 * @return int 
 */
   int getMz();
/**
 * @brief setter de Mz
 * 
 * @param m 
 */
   void setMz(int m);
/**
 * @brief getter de Dz
 * 
 * @return int 
 */
   int getDz();
   /**
     * @brief setter de Dz
     * 
     * @param d 
     */
   void setDz(int d);
   double getPago();
   void setPago(double pago);
/**
* @brief Obtiene el valor del pago para la tabla de amortizacion
* @param saldo
* @param interes
* @param mes
* @return Valor calculado
*/
   double calcularPago(double saldo, double interes, int mes);

   int encontrarDia(int anio,int mes, int dia);
   void verDia(int valor);
   bool validarAnio(int anio);
   int validarFecha(int dia,int mes,int anio);
   int validarDia(int dia,int mes,int anio);
   int finDeMes(int mes);
   bool validarFeriado(int dia, int mes);

/**
 * @brief Obtiene el valor del pago para la tabla de amortizacion
 * 
 * @param t 
 * @return double 
 */
   double calcularPago(Tabla t);

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
   void tablaAmortizacion(double saldo, double pago, double interes, int mese, int d, int m, int a);

protected:

private:
   double pago{};
   double saldo;
   double interes;
   int meses;
   int d;
   int m;
   int a;
   int az{};
   int yz{};
   int mz{};
   int dz{};
};

#endif
