#include "Complejo.h"


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
