#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Matriz.h"
#include "ValidarDatos.h"

using namespace std;

int main(int argc, char** argv) {

	ValidarDatos val;
	
	int f = val.validarEntero("Ingrese el tamanio de la matriz: "); 
	int c = f;
	
	cout << endl;

	Matriz<int> m1(f, c);
	Matriz<int> m2(f, c);
	Matriz<int> m3(f, c);
	Matriz<int> m4(f, c);
	Matriz<int> mr(f, c);
	Matriz<int> mr2(f, c);


	// Asignando Memoria
	m1.asignarMemoria();
	m2.asignarMemoria();
	m3.asignarMemoria();
	m4.asignarMemoria();
	mr2.asignarMemoria();
	mr.asignarMemoria();

	
	// Ingresando los valores Matrices
	m1.ingresar();
	cout << endl;
	m1.imprimir();

	cout << endl;

	m2.ingresar();
	cout << endl;
	m2.imprimir();

	cout << endl;
	cout << "Suma" << endl;
	mr = m3.sumaRecursiva(m1, m2, m3, f - 1, c - 1);
	mr.imprimir();

	cout << endl;
	cout << "Multiplicacion" << endl;
	mr2 = m3.multiplicacionRecursiva(m1, m2, m4, f, c);
	mr2.imprimir();
	
	return 0;
}
