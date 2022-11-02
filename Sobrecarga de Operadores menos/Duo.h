/***********************************************************************
 * Module:  Duo.h
 * Author:  Ariel Guevara, David cantuña
 * Modified: miércoles, 2 de noviembre de 2022 0:15:13
 * Purpose: Programa permite sobrecargar el operardor -
 ***********************************************************************/
#include <iostream>

#if !defined(__SobrecargadeOperadores2_Duo_h)
#define __SobrecargadeOperadores2_Duo_h

class Duo
{
public:
    Duo()  : num1(0),num2(0){}
    Duo(const double num1, const double  num2);   
    Duo(const Duo&);
    Duo operator -(Duo &d);
    double getNum1();
    double getNum2();
protected:
private:
    double num1;
    double num2;


};

#endif