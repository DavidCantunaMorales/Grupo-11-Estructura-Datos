/***********************************************************************
 * Module:  Templates.h
 * Author:  Ariel
 * Modified: domingo, 30 de octubre de 2022 12:39:07
 * Purpose: Declaration of the class Templates
 ***********************************************************************/

#if !defined(__Class_Diagram_2_Templates_h)
#define __Class_Diagram_2_Templates_h

class ValidarDatos
{
public:
virtual char* validarEntero(char  const *mensaje)=0;
virtual char* validarDoubles(char const *mensaje)=0;
virtual char* validarLetras(char const *mensaje)=0;
protected:
private:

};

#endif