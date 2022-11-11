/***********************************************************************
 * Module:  Templates.h
 * Author:  Ariel Guevara, David Cantuña
 * Modified: domingo, 30 de octubre de 2022 12:39:07
 * Purpose: Declaration of the class Templates
 ***********************************************************************/

#if !defined(__Class_Diagram_2_Templates_h)
#define __Class_Diagram_2_Templates_h

class ValidarDatos
{
public:
virtual int validarEntero(char *const &mensaje);
virtual float validarDoubles(char* const &mensaje);
virtual std::string validarLetras(char* const &mensaje);
protected:
private:

};

#endif
