#include "Matriz.h"
#include "ValidarDatos.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

ValidarDatos val;

template <typename T>
Matriz<T>::Matriz(T f, T c){
	this->c = c;
	this->f = f;
}
template <typename T>
Matriz<T>::Matriz(){
}

template <typename T>
T** Matriz<T>::getPtr(){
	return this->ptr;
}

template <typename T>
void Matriz<T>::asignarMemoria(){
	ptr = (T**)malloc(f * sizeof(T*));
	for (int j = 0; j < f; j++) {
		*(ptr + j) = (T*)malloc(c * sizeof(T));
	}

	// encerando
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			*(*(ptr + i) + j) = 0;
		}
	}
}

template <typename T>
void Matriz<T>::ingresar(){
	T dato;
	for (int i = 0; i < f; i++){
		for (int j = 0; j < c; j++) {
			cout << "Ingrese el numero de [" << i + 1 << "][" << j + 1 << "]: ";
			cin >> dato;
			*(*(ptr + i) + j) = dato;
		}
	}
}

template <typename T>
void Matriz<T>::imprimir(){
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			cout << *(*(ptr + i) + j);
			printf("%*s", j + 5, " ");
		}
		printf("\n");
	}
}

template<typename T>
Matriz<T> Matriz<T>::multiplicacion(Matriz<T> mat2, T f, T c){
	Matriz<T> mr(f, c);
	mr.asignarMemoria();
	T** res = mr.getPtr();
	T** mtemp = mat2.getPtr();
	for (int i = 0; i < f; i++) {
		for (int j = 0; j < c; j++) {
			for (int h = 0; h < c; h++) {
				*(*(res + i) + j) = *(*(res + i) + j) + (*(*(ptr + i) + h)) * (*(*(mtemp + h) + j));
				// *(*(res + i) + j) matriz donde se va a guardar en este caso mr (matriz resultado)
				// (*(*(mat + i) + h)) * (*(*(mtemp + h) + j)) aqui es donde se estan multiplicando
				// *(*(res + i) + j) y esto es para la posicion supongo no estoy seguro
				// y tampoco cacho para que necesita 3 bucles for
			}
		}
	}
	return mr;
}

template<typename T>
Matriz<T> Matriz<T>::suma(Matriz<T> mat2, T f, T c){
	Matriz<T> mr(f, c);
	mr.asignarMemoria();
	T** res = mr.getPtr();
	T** mtemp = mat2.getPtr();
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

template<typename T>
Matriz<T> Matriz<T>::sumaRecursiva(Matriz<T> mat1, Matriz<T> mat2, Matriz<T> matR, T f, T c){
	if ((f >= 0) && (c >= 0)) {
		*(*(matR.getPtr() + f) + c) = *(*(mat1.getPtr() + f) + c) + *(*(mat2.getPtr() + f) + c);
		sumaRecursiva(mat1, mat2, matR, f - 1, c);
		sumaRecursiva(mat1, mat2, matR, f, c - 1);
	}
	return matR;
}

template<typename T>
Matriz<T> Matriz<T>::multiplicacionRecursiva(Matriz<T> mat1, Matriz<T> mat2, Matriz<T> matR, T f, T c){
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

// para que acepte 3 tipos de datos
template class Matriz<int>;

