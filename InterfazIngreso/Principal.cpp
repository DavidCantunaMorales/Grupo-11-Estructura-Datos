#include <iostream>
#include <string.h>
#include "Validar.h"

int main(int argc, char** argv) {
	Validar obj1;
    char dato[10];
    strcpy(dato,obj1.ingresoInt("Ingrese un dato Entero: "));
    std::cout<<std::endl;
    std::cout<<dato<<std::endl;
    strcpy(dato,obj1.ingresoDouble("Ingrese un dato Flotante o Double: "));
    std::cout<<std::endl;
    std::cout<<dato<<std::endl;
    strcpy(dato,obj1.ingresoString("Ingrese un Texto: "));
    std::cout<<std::endl;
    std::cout<<dato<<std::endl;
	return 0;
}
