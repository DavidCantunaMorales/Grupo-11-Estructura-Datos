#include <iostream>
#include "Persona.cpp"

int main( int argc, char** argv){

   Persona *obj1 = new Persona();
    //Persona *obj3 = new Persona("Pedro", "Perez", "Quito", 104855977, 105545564.f,3,5,1997);
    Persona *obj2 = new Persona("Carlos", "Perez", "Quito", 104855977, 105545564.f,3,5,1997);
    obj1->calcularEdad(*obj2);
}