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
#include "Zeller.h"
#include "ValidarDatos.h"

using namespace std;

int main(int argc, char** argv) {

	ValidarDatos obj1;
	Tabla t1;


	t1.setSaldo(obj1.validarDoubles("Ingrese el monto a pedir: "));
	cout << endl;
	t1.setInteres(obj1.validarDoubles("Ingrese el interes del prestamo: "));
	cout << endl;
	t1.setMeses(obj1.validarEntero("Ingrese en numero de meses: "));
	cout << endl;
	t1.setA(obj1.validarEntero("Ingrese el anio que se realizo el prestamo: "));
	cout << endl;
	t1.setM(obj1.validarEntero("Ingrese el mes que se realizo el prestamo: "));
	cout << endl;
	t1.setD(t1.validarFecha(obj1.validarEntero("Ingrese el dia que se realizo el prestamo: "),t1.getM(),t1.getA()));
	cout << endl;
	
	
	t1.setPago(t1.calcularPago(t1.getSaldo(), t1.getInteres(), t1.getMeses()));

	std::cout << std::setw(5) << "\nMeses:"
		<< std::setw(25) << "Pago:"
		<< std::setw(25) << "Interes:"
		<< std::setw(25) << "Amortizacion:"
		<< std::setw(25) << "Saldo:"
		<< '\n';

	t1.tablaAmortizacion(t1.getSaldo(), t1.getPago(), t1.getInteres(), 
						t1.getMeses(), t1.getD(), t1.getM(), t1.getA());

	return 0;

}
