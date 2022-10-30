#include <iostream>
#include "ValidarDatos1.cpp"
#include <string.h>

int main(int argc, char** argv){

    ValidarDatos1 obj1;
    char dato[10];
    strcpy(dato,obj1.validarDoubles("Ingrese su dato"));
    std::cout<<"\n"<<dato;
    strcpy(dato,obj1.validarEntero("Ingrese su dato"));
    std::cout<<"\n"<<dato;
    strcpy(dato,obj1.validarLetras("Ingrese su texto"));
    std::cout<<"\n"<<dato;
    return 0;
}
