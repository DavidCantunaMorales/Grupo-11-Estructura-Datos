/**
 * @file CalculoTablaAmortizacion.cpp
 * @author
 * @brief Programa que simula la creacion de una tabla de amortizacion de prestamos
 * @version 1.0
 * @date 2022-11-6
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <iomanip>
#include <math.h>

#include "Tabla.h"
#include "ValidarDatos.h"

using namespace std;

int main(int argc, char** argv) {

	double saldo, interes;
	int meses, d, m;

	ValidarDatos obj1;
	Tabla t1;


	saldo = obj1.validarDoubles("Ingrese el monto a pedir: ");
	cout << endl;
	interes = (obj1.validarDoubles("Ingrese el interes del prestamo (%): ")) / 100;
	cout << endl;
	meses = obj1.validarEntero("Ingrese en numero de meses: ");
	cout << endl;

	do {
		d = obj1.validarEntero("Ingrese el dia que se realizo el prestamo: ");
		cout << endl;
	} while (!(d > 0 && d <= 31));


	do {
		m = obj1.validarEntero("Ingrese el mes que se realizo el prestamo: ");
		cout << endl;
	} while (!(m > 0 && m <= 12));

	/*
	do {
		a = obj1.validarEntero("Ingrese el anio que se realizo el prestamo: ");
		cout << endl;
	} while (!(a >= 2022));
	*/

	const int a = 2022;

	cout << endl;

	t1.imprimirInformacion(saldo, interes, meses, d, m, a);

	const double pago = t1.calcularPago(saldo, interes, meses);
	cout << endl;
	std::cout << "Tabla de Amortizacion" << std::endl;
	cout << endl;
	std::cout << std::setw(5) << "\nMeses:"
		<< std::setw(28) << "Pago:"
		<< std::setw(28) << "Interes:"
		<< std::setw(28) << "Amortizacion:"
		<< std::setw(20) << "Saldo:"
		<< '\n';

	t1.tablaAmortizacion(saldo, pago, interes, meses, d, m, a);

	return 0;
}