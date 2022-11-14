#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#include "Matriz.h"

using namespace std;

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "Spanish");//para tener la consola en español

	int d;
	cout << "Ingrese el tamaño de las matrices: ";
	cin >> d;

	Matriz<int> m1(d);
	Matriz<int> m2(d);
	Matriz<int> mr(d);

	// Asignando Memoria
	m1.segmentar();
	m2.segmentar();
	mr.segmentar();

	// Encerando las Matrices
	m1.encerar();
	m2.encerar();
	mr.encerar();

	
	// Ingresando los valores Matrices
	m1.ingresar();
	m2.ingresar();

	
	m1.imprimir();
	printf("\n\n");
	m2.imprimir();

	cout << "\nLa multiplicacion de las matrices es: \n";
	mr = m1.multiplicacionMatrices(m2);
	mr.imprimir();
	cout << endl;
	cout << "\nLa suma de las matrices es: \n";
	mr = m1.sumaMatrices(m2);
	mr.imprimir();
	printf("\n\n");
	


	return 0;
}