#include <iostream>
#include <math.h>

#include "Area.h"

using namespace std;

void Area::area(int lado){
	cout << "El area del cuadrado es: " << pow(lado, 2) << endl;
}

void Area::area(int base, int altura){
	cout << "El area del rectangulo es: " << (base * altura) << endl;
}

void Area::area(float lado1, float lado2, float lado3){
    float s = (lado1 + lado2 + lado3) / 2;
    float areaT = sqrt(s * (s - lado1) * (s - lado2) * (s - lado3));
    cout << "El area del triangulo es: " << areaT << endl;
}
