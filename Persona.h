/***********************************************************************
 * Module:  Persona.h
 * Author:  Intel
 * Modified: mi�rcoles, 26 de octubre de 2022 21:12:26
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Registro_Persona_h)
#define __Registro_Persona_h
#include <iostream>
class Persona
{
public:
   Persona();
   Persona(std::string nombreP, std::string apellidoP, std::string direccionP, int cedulaP, double celularP, int diaP, int mesP, int anioP);
   ~Persona();
   void calcularEdad(Persona anioP);
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   std::string getDireccion(void);
   void setDireccion(std::string newDireccion);
   int getCedula(void);
   void setCedula(int newCedula);
   double getCelular(void);
   void setCelular(double newCelular);
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getAnio(void);
   void setAnio(int newAnio);
   void cedulaValidada();

protected:
private:
   std::string nombre;
   std::string apellido;
   std::string direccion;
   int cedula;
   double celular;
   int dia;
   int mes;
   int anio;


};

#endif