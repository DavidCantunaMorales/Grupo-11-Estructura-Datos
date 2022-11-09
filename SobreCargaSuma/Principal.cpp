/*
UFA - ESPE
ALUMNOS: David Cantuña, Ariel Guevara
FECHA DE CREACION: 8/11/2022
FECHA DE MODIFICACION: 8/11/2022
ENUNCIADO: Sobrecarga de operador +
NRC: 7999
*/

#include <iostream>
#include "Complejo.h"

using namespace std;


int main(int argc, char** argv) {
	Complejo compA(8,5), compB(5,2), compC, compD, compE, compF;
	compC = compA + compB;
	cout << "SobreCarga 1" << endl;
	cout << compC.getReal() << " , " << compC.getImag() << endl;
	
	cout << "SobreCarga 2" << endl;
	compD = compB + 8;
	cout << compD.getReal() << " , " << compD.getImag() << endl;
	
	cout << "SobreCarga 3" << endl;
	compE = compB + 9.123456;
	cout << compE.getReal() << " , " << compE.getImag() << endl;
	
	cout << "SobreCarga 4" << endl;
	compF = compA + "5";
	cout << compF.getReal() << " , " << compF.getImag() << endl;
	
	 
	
	return 0;
}
