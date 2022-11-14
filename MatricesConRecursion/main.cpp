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

	Matriz m1(f, c);
	Matriz m2(f, c);
	Matriz m3(f, c);
	Matriz m4(f, c);
	Matriz mr2(f, c);
	Matriz mr(f, c);

	
	m1.asignarMemoria();
	m2.asignarMemoria();
	m3.asignarMemoria();
	m4.asignarMemoria();
	mr2.asignarMemoria();
	mr.asignarMemoria();

	
	m1.ingresar();
	cout << endl;
	m1.imprimir();

	cout << endl;

	m2.ingresar();
	cout << endl;
	m2.imprimir();

	//mr = m1.multiplicacion(m2, f, c);
	
	//mr2 = m1.suma(m2, f, c);

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
