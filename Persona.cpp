/***********************************************************************
 * Module:  Persona.cpp
 * Authors:  David Cantuña, Ariel Guevara
 * Modified: miercoles, 26 de octubre de 2022 21:12:26
 * Purpose: Implementation of the class Persona
 * Diseñar un programa basado en tipos de datos abstractos, con datos personales y 
 * calcular su edad
 ***********************************************************************/

#include "Persona.h"
#include <iostream>
#include <conio.h>
#include <ctime>

struct Fecha{
   int dia, mes,anio;
};

Fecha hoy()
{
   time_t t;
   t = time(NULL);
   struct tm *f;
   f = localtime(&t);
   Fecha aux;
   aux.anio = f->tm_year + 1900;
   aux.mes = f->tm_mon + 1;
   aux.dia = f->tm_mday;
   return aux;
}
Persona::Persona()
{
   std::cout<<"Ingrese su Nombre: "; std::cin>>this->nombre;
   std::cout<<"Ingrese su Apellido "; std::cin>>this->apellido;
   std::cout<<"Ingrese su fecha de nacimiento"<<std::endl;
   std::cout<<"Dia: "; std::cin>>this->dia;
   std::cout<<"Mes: "; std::cin>>this->mes;
   std::cout<<"Año: "; std::cin>>this->anio;
   std::cout<<"Direccion: ";
   this->cedulaValidada();
   std::cout<<"Ingrese su numero celular: "; std::cin>>this->celular;

}

Persona::Persona(std::string nombreP, std::string apellidoP, std::string direccionP, int cedulaP, double celularP, int diaP, int mesP, int anioP)
{
   this->nombre = nombreP;
   this->apellido = apellidoP;
   this->direccion = direccionP;
   this->cedula = cedulaP;
   this->celular = celularP;
   this->dia = diaP;
   this->mes = mesP;
   this->anio = anioP;
}


Persona::~Persona()
{
}
/**
 * @brief calcularEdad indica la edad del usuario en base a la informacion ingresada
 * 
 * @param sujeto es un TDA en este caso de clase Persona
 */
void Persona::calcularEdad(Persona sujeto)
{
   int anio=0,mes=0,dia=0;
   Fecha fechar;
   fechar = hoy();
   anio = (fechar.anio - sujeto.getAnio()) -1;
   if(fechar.mes >= sujeto.getMes()){
      if(fechar.dia >= sujeto.getDia()){
         anio +=1;
      }
   }
   std::cout<<"su edad es de "<<anio<<" anios";
}
/**
 * @brief getNombre entrega el atributo de nombre
 * 
 * @return std::string 
 */
std::string Persona::getNombre(void)
{
   return nombre;
}


void Persona::setNombre(std::string newNombre)
{
   nombre = newNombre;
}


std::string Persona::getApellido(void)
{
   return apellido;
}


void Persona::setApellido(std::string newApellido)
{
   apellido = newApellido;
}

std::string Persona::getDireccion(void)
{
   return direccion;
}


void Persona::setDireccion(std::string newDireccion)
{
   direccion = newDireccion;
}


int Persona::getCedula(void)
{
   return cedula;
}

void Persona::setCedula(int newCedula)
{
   cedula = newCedula;
}

double Persona::getCelular(void)
{
   return celular;
}

void Persona::setCelular(double newCelular)
{
   celular = newCelular;
}

int Persona::getDia(void)
{
   return dia;
}


void Persona::setDia(int newDia)
{
   dia = newDia;
}

int Persona::getMes(void)
{
   return mes;
}

void Persona::setMes(int newMes)
{
   mes = newMes;
}

int Persona::getAnio(void)
{
   return anio;
}


void Persona::setAnio(int newAnio)
{
   anio = newAnio;
}
/**
 * @brief cedulaValidad
 * @param no requiere de un parametro ya que todo lo pide dentro de la misma funcion
 * 
 */
void Persona::cedulaValidada()
{
   bool cedulaReal = false;
         //ciclo while que ordena los digitos en un array
   while(cedulaReal == false){
   int digitos,iw=10,i=0,cedula_separada[10],digent,suma_impares=0,suma_pares=0,resultado=0,digver=0,cedulaP=0;
      fflush(stdin);
     std::cout<<"Ingrese su cedula "; std::cin>>cedulaP;
     this->cedula = cedulaP;
     while(iw>0){
        iw--;
        digitos=cedulaP%10;
        cedula_separada[iw]=digitos;
        cedulaP = cedulaP/10;
     }
     digver=cedula_separada[9];
         //ciclo for que toma los digitos en la posicion impar y los multiplica por dos
     for(i=0;i<9;i=i+2){
        cedula_separada[i] = cedula_separada[i]*2;
        //if que comprueba que si es mayor a 10 suma ambos digitos
        if(cedula_separada[i]>9){
            digitos=cedula_separada[i]%10;
            digent=cedula_separada[i]/10;
            cedula_separada[i]=digitos+digent;
        }
        suma_impares=suma_impares+cedula_separada[i];
     }
     for(i=1;i<9;i=i+2){
        suma_pares=suma_pares+cedula_separada[i];
     }
     resultado=suma_impares+suma_pares;
     if((resultado%10)==0){
            resultado=resultado/10;
            if(resultado==digver){
                std::cout<<"su cedula es correcta"<<std::endl;
                cedulaReal = true;
            }else{
                std::cout<<"su cedula es incorrecta"<<std::endl;
                cedulaP = 0;
            }
     }else{
         resultado=(suma_impares+suma_pares)/10;
     resultado=(resultado+1)*10;
     resultado=resultado-(suma_impares+suma_pares);
            if(resultado==digver){
                std::cout<<"su cedula es correcta"<<std::endl;
                cedulaReal = true;
            }else{
                std::cout<<"su cedula es incorrecta"<<std::endl;
                cedulaP = 0;
            }
     }
   }
}