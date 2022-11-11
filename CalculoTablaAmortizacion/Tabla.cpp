/***********************************************************************
 * Module:  Tabla.cpp
 * Author:  Ariel Guevara, David cantuña
 * Modified: domingo, 6 de noviembre de 2022 0:09:18
 * Purpose: Implementation of the class Tabla
 ***********************************************************************/

#include "Tabla.h"
#include "ValidarDatos.h"
#include <iostream>
#include <iomanip>
#include <math.h>

ValidarDatos obj1;
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
   this->saldo = 0;
   this->interes = 0;
   this->meses = 0;
   this->d = 0;
   this->m = 0;
   this->a = 0;
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
double Tabla::getPago(){
   return pago;
}
void Tabla::setPago(double pago){
   this->pago = pago;
}
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

/**
 * @brief Obtiene el valor del pago para la tabla de amortizacion
 * 
 * @param t 
 * @return double 
 */
double Tabla::calcularPago(Tabla t){
    return t.getSaldo() * ((t.getInteres() / t.getMeses()) / (1 - (pow((1 + (t.getInteres() / t.getMeses())), -t.getMeses()))));
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
int Tabla::encontrarDia(int anio, int mes, int dia){
   this->az = (14-mes)/12;
   this->yz = anio - az;
   this->mz = mes + (12 * az) - 2;
   this->dz = (dia + yz + yz/4 - yz/100 + yz/400 + (31*mz)/12)%7;
   return dz;
}
/**
 * @brief Devuele en String que dia es
 * 
 * @param valor 
 */
void Tabla::verDia(int valor){
   switch (valor)
   {
   case 0:
      std::cout<<"Es un domingo\n";
      break;
   case 1:
      std::cout<<"Es un lunes";
      break;
   case 2:
      std::cout<<"Es un martes";
      break;
   case 3:
      std::cout<<"Es un miercoles";
      break;
   case 4:
      std::cout<<"Es un jueves";
      break;
   case 5:
      std::cout<<"Es un viernes";
      break;
   case 6:
      std::cout<<"Es un sabado";
      break;
   default:
   std::cout<<"El valor ingresado es erroneo";
      break;
   }
}
/**
 * @brief Valida que la fecha sea correcta dentro de mes y que no sea ni fin de semana ni feriado
 * 
 * @param dia 
 * @param mes 
 * @param anio 
 * @return int 
 */
int Tabla::validarFecha(int dia,int mes,int anio){
      switch (mes)
      {
      case 1:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Enero: ");
         }
         break;
      case 2:
         if(this->validarAnio(anio)){
            while(dia>29 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 29 de Febrero: ");
            }
         }else{
            while(dia>28 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 28 de Febrero: ");
         }}
         break;
      case 3:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Marzo: ");
         }
         break;
      case 4:
         while(dia>30 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 30 de Abril: ");
         }
         break;
      case 5:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Mayo: ");
         }
         break;
      case 6:
         while(dia>30 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 30 de Junio: ");
         }
         break;
      case 7:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Julio: ");
         }
         break;
      case 8:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Agosto: ");
         }
         break;
      case 9:
         while(dia>30 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 30 de Septiembre: ");
         }
         break;
      case 10:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Octubre: ");
         }
         break;
      case 11:
         while(dia>30 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 30 de Noviembre: ");
         }
         break;
      case 12:
         while(dia>31 || dia<1){
            dia= obj1.validarEntero("Ingrese una fecha que no sobrepase a 31 de Diciembre: ");
         }
         break;                              
      default:
      std::cout<<"El mes ingresado es erroneo";
         break;
   }
   this->setD(dia);
   int day = this->encontrarDia(anio,mes,dia);
   if(day == 0){
      dia++;
      if(dia > this->finDeMes(mes)){
         dia = 1;
         mes++;
         if(mes > 12){
            anio++;
            mes = 1;
         }
      }
      if(this->validarFeriado(dia,mes)){
         dia++;
      }
   }else if(day == 6){
      dia--;
      if(dia < 1){
         dia = this->finDeMes(mes-1);
         mes--;
         if(mes < 1){
            anio--;
            mes = 12;
         }
      }
      if(this->validarFeriado(dia,mes)){
         dia--;
      }
   }
   return dia;
}
/**
 * @brief Valida que el dia no sea ni fin de semana ni feriado
 * 
 * @param dia 
 * @param mes 
 * @param anio 
 * @return int 
 */
int Tabla::validarDia(int dia,int mes,int anio){
   int day = this->encontrarDia(anio,mes,dia);
   if(day == 0){
      dia++;
      if(dia > this->finDeMes(mes)){
         dia = 1;
         mes++;
         if(mes > 12){
            anio++;
            mes = 1;
         }
      }
      if(this->validarFeriado(dia,mes)){
         dia++;
      }
   }else if(day == 6){
      dia--;
      if(dia < 1){
         dia = this->finDeMes(mes-1);
         mes--;
         if(mes < 1){
            anio--;
            mes = 12;
         }
      }
      if(this->validarFeriado(dia,mes)){
         dia--;
      }
   }
   return dia;
   }
   /**
    * @brief Comprueba que un dia no sea feriado
    * 
    * @param dia 
    * @param mes 
    * @return true 
    * @return false 
    */
bool Tabla::validarFeriado(int dia, int mes){
   if((dia == 1 && mes == 1)||  //Año nuevo
      (dia == 28 && mes == 2)|| //Carnaval
      (dia == 1 && mes == 3)||  //Carnaval
      (dia == 15 && mes == 4)||  //Viernes Santo
      (dia == 1 && mes == 5)||  //Dia del trabajo
      (dia == 24 && mes == 5)|| //Batalla de Pichincha
      (dia == 10 && mes == 8)|| //Primer Grito de la independencia
      (dia == 9 && mes == 10)||    //Independencia de Guayaquil
      (dia == 2 && mes == 11)|| //Dia de los difunntos
      (dia == 3 && mes == 11)|| //Independencia de Cuenca
      (dia == 6 && mes == 12)|| //Fundacion de Quito
      (dia == 25 && mes == 12))//Navidad
      { 
         return true;
      }else
      return false;
      
}
/**
 * @brief Devuelve un int con la cantidad de dias que tiene un mes
 * 
 * @param mes 
 * @return int 
 */
int Tabla::finDeMes(int mes){
   switch (mes)
   {
   case 1:
   return 31;
      break;
   case 2:
   if(this->validarAnio(this->getA())){
      return 29;
   }else{
      return 28;
   }
      break;
   case 3:
      return 31;
      break;
   case 4:
      return 30;
      break;
   case 5:
      return 31;
      break;
   case 6:
      return 30;
      break;
   case 7:
      return 31;
      break;
   case 8:
      return 31;
      break;
   case 9:
      return 30;
      break;
   case 10:
      return 31;
      break;
   case 11:
      return 30;
      break;
   case 12:
      return 31;
      break;
   default:
      break;
   }
}
/**
 * @brief valida si unn año es biciesto o no
 * 
 * @param anio 
 * @return true 
 * @return false 
 */
bool Tabla::validarAnio(int anio){
   bool validacion{};
   if(anio % 4 != 0 || (anio % 100 == 0 && anio % 400 != 0)){
      validacion = false;
   }else{
      validacion = true;
   }
   return validacion;
}
/**
 * @brief muestra la tabla de amortizacion
 * 
 * @param saldo 
 * @param pago 
 * @param interes 
 * @param meses 
 * @param d 
 * @param m 
 * @param a 
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
      d = this->validarDia(d,m,a);
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

