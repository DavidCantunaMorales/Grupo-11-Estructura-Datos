#include <iostream>
#include "Tabla.h"

int main(int argc, char** argv) {

    Tabla obj1 = Tabla();

    std::cout<<obj1.calcularPago(10000,0.025,5);
    return 0;
}