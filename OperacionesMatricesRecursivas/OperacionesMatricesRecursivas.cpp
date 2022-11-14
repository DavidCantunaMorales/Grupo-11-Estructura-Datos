#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "Matriz.h"
#include "MatrizRecursiva.h"
#include "ValidarDatos.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "Spanish");//para tener la consola en español
	ValidarDatos objv;
	int d{};
	d = objv.validarEntero("Ingrese el tamaño de las matrices: ");
	cout<<"\nd "<<d;

	float** resultante;

	MatrizRecursiva obj;
	float** mt1{};
	float** mt2{};

	// Matriz<int> m1(d);
	// Matriz<int> m2(d);
	// Matriz<int> mr(d);
	for (int j = 0; j < d; j++) {
		*(mt1 + j) = (float*)malloc(3 * sizeof(float*));
		*(mt2 + j) = (float*)malloc(3 * sizeof(float*));
	}

	// Asignando Memoria
	// m1.segmentar();
	// m2.segmentar();
	// mr.segmentar();
	// obj.segmentar(mt1,d);
	// obj.segmentar(mt2,d);
	// Encerando las Matrices
	// m1.encerar();
	// m2.encerar();
	// mr.encerar();

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mt1 + i) + j) = (int)((rand() % 5));
			*(*(mt2 + i) + j) = (int)((rand() % 5));
		}
	}

obj.imprimir(mt1,d);
	// Ingresando los valores Matrices
	// m1.ingresar();
	// m2.ingresar();
	// obj.ingresar(mt1,d);
	// obj.ingresar(mt2,d);
	//Generar random
	//m1.llenarMatrizRandom(mt1,2,2);
	
	// m1.imprimir();
	// printf("\n\n");
	// m2.imprimir();

	// cout << "\nLa multiplicacion de las matrices es: \n";
	// mr = m1.multiplicacionMatrices(m2);
	// mr.imprimir();
	// cout << endl;
	// cout << "\nLa suma de las matrices es: \n";
	// mr = m1.sumaMatrices(m2);
	// mr.imprimir();
	// printf("\n\n");
	


	return 0;
}