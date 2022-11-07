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
	int meses, d, m, a;

	ValidarDatos obj1;
	Tabla t1;


	saldo = obj1.validarDoubles("Ingrese el monto a pedir: ");
	cout << endl;
	interes = obj1.validarDoubles("Ingrese el interes del prestamo: ");
	cout << endl;
	meses = obj1.validarEntero("Ingrese en numero de meses: ");
	cout << endl;
	d = obj1.validarEntero("Ingrese el dia que se realizo el prestamo: ");
	cout << endl;
	m = obj1.validarEntero("Ingrese el mes que se realizo el prestamo: ");
	cout << endl;
	a = obj1.validarEntero("Ingrese el anio que se realizo el prestamo: ");
	cout << endl;


	const double pago = t1.calcularPago(saldo, interes, meses);

	std::cout << std::setw(5) << "\nMeses:"
		<< std::setw(25) << "Pago:"
		<< std::setw(25) << "Interes:"
		<< std::setw(25) << "Amortizacion:"
		<< std::setw(25) << "Saldo:"
		<< '\n';

	t1.tablaAmortizacion(saldo, pago, interes, meses, d, m, a);

	return 0;
}