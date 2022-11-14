#include <iostream>

#include "ValidarDatos.h"
#include "MatrizRecursiva.h"
#define TAM 10

ValidarDatos obj1;

MatrizRecursiva::MatrizRecursiva(){

}
MatrizRecursiva::MatrizRecursiva(int d){
    this->d = d;
}
float MatrizRecursiva::getDimension(){
	return d;
}

float** MatrizRecursiva::getMatriz(){
	return mat;
}

void MatrizRecursiva::encerar(float** mat){
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
	return;
}

void MatrizRecursiva::setDimension(float _dimension)
{
	this->d = _dimension;
} 

void MatrizRecursiva::setMatriz(float** matri){
	this->mat = matri;
}

void MatrizRecursiva::ingresar(float**mat,int d){
	//float dato;
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++) {
			std::cout<<"\ni: "<<i;
			std::cout << "\nIngrese el numero de [" << i + 1 << "][" << j + 1 << "]: ";
			//fflush(stdin);
			*(*(mat + i) + j) = (float)obj1.validarDoubles(" ");
		}

}

void MatrizRecursiva::imprimir(float** mat,int d){
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++)
		{
			std::cout << *(*(mat + i) + j);
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}

int MatrizRecursiva::generar_aleatorio(int linf, int lsup){
    int numero=0;
    numero=linf + rand()% (lsup-linf);
    return numero;
}

void MatrizRecursiva::segmentar(float**mat,int d){
	mat = (float**)malloc((d+1) * sizeof(float*));
	for (int j = 0; j < d; j++)
		*(mat + j) = (float*)malloc(d * sizeof(float));
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
} 
void multiplicacionRecursivaMatrices(float* mat1, float** mat2, float** matR, int f, int c) {

	static int i = 0, j = 0, k = 0;

	if (i < f) {
		if (j < c) {
			if (k < c) {
				*(*(matR + i) + j) += (*(mat1 + i) + k) * (*(*(mat2 + k) + j));
				k++;
				multiplicacionRecursivaMatrices(mat1, mat2, matR, f, c);
			}
			k = 0;
			j++;
			multiplicacionRecursivaMatrices(mat1, mat2, matR, f, c);
		}
		j = 0;
		i++;
		multiplicacionRecursivaMatrices(mat1, mat2, matR, f, c);
    }
}

void MatrizRecursiva::llenarMatrizRandom(float** matriz, int filas, int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j] = this->generar_aleatorio(0,9);
        }
    }
}