#include <string>
#include <iostream>
#include <cstdlib>
#include "Complejo.h"

using namespace std;

Complejo::Complejo(int r, int i){
	this->real = r;
	this->imag = i;
}

Complejo::getReal(){
	return this->real;
}

Complejo::getImag(){
	return this->imag;
}

Complejo Complejo::operator+(Complejo c2){
	int realN = real + c2.getReal();
	int imagN = imag + c2.getImag();
	Complejo nuevo(realN, imagN);
	return nuevo;
}

Complejo Complejo::operator+(int num1){
	int realN = real + num1;
	int imagN = imag;
	Complejo nuevo(realN, imagN);
	return nuevo;
}

Complejo Complejo::operator+(double num2){
	int realN = real;
	int imagN = imag + num2;
	Complejo nuevo(realN, imagN);
	return nuevo;
}

Complejo Complejo::operator+(char* num3){
	int numero = atoi(num3);
	int realN = real + numero;
	int imagN = imag + numero;
	Complejo nuevo(realN, imagN);
	return nuevo;
}
