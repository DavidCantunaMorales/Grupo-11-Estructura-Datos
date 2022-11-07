#include <iostream>
#include "Tabla.h"

int main(int argc, char** argv) {

    Tabla  obj1 = Tabla(10000.f,0.025,3,16,4,2022);
    Tabla obj2;

    obj1.calcularPago(obj1);
    return 0;
}
