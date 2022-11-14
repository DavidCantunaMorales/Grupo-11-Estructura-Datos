#include "Matriz.h"
#include "ValidarDatos.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

ValidarDatos val;

Matriz::Matriz(int f, int c) {
	this->c = c;
	this->f = f;
}

Matriz::Matriz() {
}

int** Matriz::getPtr() {
	return this->ptr;
}

void Matriz::asignarMemoria(){
	ptr = (int**)malloc(f * sizeof(int*));
	for (int j = 0; j < f; j++) {
		*(ptr + j) = (int*)malloc(c * sizeof(int));
	}

	// encerando
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			*(*(ptr + i) + j) = 0;
		}
	}
}

void Matriz::ingresar() {
	//int dato;
	for (int i = 0; i < f; i++)
		for (int j = 0; j < c; j++) {
			cout << "Ingrese el numero de [" << i + 1 << "][" << j + 1 << "]: ";
			//cin >> dato;
			int dato = val.validarEntero(""); 
			*(*(ptr + i) + j) = dato;
			cout << endl;
		}

}

void Matriz::imprimir(){
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(*(ptr + i) + j);
			printf("%*s", j + 5, " ");
		}
		printf("\n");
	}
}

Matriz Matriz::multiplicacion(Matriz mat2, int f, int c){
	Matriz mr(f , c);
	mr.asignarMemoria();
	int** res = mr.getPtr();
	int** mtemp = mat2.getPtr();
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			for (int h = 0; h < c; h++) {
				*(*(res + i) + j) = *(*(res + i) + j) + (*(*(ptr + i) + h)) * (*(*(mtemp + h) + j));
			}
		}
	}
	return mr;
}

Matriz Matriz::suma(Matriz mat2, int f, int c){
	Matriz mr(f, c);
	mr.asignarMemoria();
	int** res = mr.getPtr();
	int** mtemp = mat2.getPtr();
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			//*(*(res + i) + j) = *(*(res + i) + j) + *(*(mtemp + i) + j) + *(*(mtemp + i) + j); duplica la segunda matriz
			*(*(res + i) + j) = *(*(ptr + i) + j) + *(*(mtemp + i) + j);
			// *(*(mat + i) + j) es la primera matriz a sumar
			// *(*(mtemp + i) + j) es la matriz que se envia por paramtero la matrizTmp
			// *(*(res + i) + j) matriz donde se va a guardar en este caso mr (matriz resultado)
		}
	}
	return mr;

}

Matriz Matriz::sumaRecursiva(Matriz mat1, Matriz mat2, Matriz matR, int f, int c){
	if ((f >= 0) && (c >= 0)) {
		*(*(matR.getPtr() + f) + c) = *(*(mat1.getPtr() + f) + c) + *(*(mat2.getPtr() + f) + c);
		sumaRecursiva(mat1, mat2, matR, f - 1, c);
		sumaRecursiva(mat1, mat2, matR, f, c - 1);
	}
	return matR;
}

Matriz Matriz::multiplicacionRecursiva(Matriz mat1, Matriz mat2, Matriz matR, int f, int c){

	static int i = 0, j = 0, k = 0;

	if (i < f) {
		if (j < c) {
			if (k < c) {
				*(*(matR.getPtr() + i) + j) += *(*(mat1.getPtr() + i) + k) * *(*(mat2.getPtr() + k) + j);
				k++;
				multiplicacionRecursiva(mat1, mat2, matR, f, c);
			}
			k = 0;
			j++;
			multiplicacionRecursiva(mat1, mat2, matR, f, c);
		}
		j = 0;
		i++;
		multiplicacionRecursiva(mat1, mat2, matR, f, c);
	}

	return matR;
}

