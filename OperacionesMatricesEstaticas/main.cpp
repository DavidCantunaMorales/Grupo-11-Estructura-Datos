#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#include "ValidarDatos.h"
#include "Matriz.h"

using namespace std;

int main(int argc, char** argv) {
	
    Matriz obj;
    ValidarDatos v1;
    float matriz1[TAM][TAM],matriz2[TAM][TAM];
    int filas1{},columnas1{},filas2{},columnas2{};

    filas1 = v1.validarEntero("\nIngrese el numero de filas que desea que tenga la primera matriz: ");
    columnas1 = v1.validarEntero("\nIngrese el numero de columnas que desea que tenga la primera matriz: ");
    filas2 = v1.validarEntero("\nIngrese el numero de filas que desea que tenga la segunda matriz: ");
    columnas2 = v1.validarEntero("\nIngrese el numero de columnas que desea que tenga la segunda matriz: ");

    matriz1[filas1][columnas1];
    matriz2[filas2][columnas2];

    // obj.llenarMatrizRandom(matriz1,filas1,columnas1);
    // obj.llenarMatrizRandom(matriz2,filas2,columnas2);

    obj.llenarMatriz(matriz1,filas1,columnas1);
    obj.llenarMatriz(matriz2,filas2,columnas2);

    obj.sumaDeMatrices(matriz1,matriz2,filas1,columnas1,filas2,columnas2);
    
    cout << endl;
    
    obj.multiplicacionDeMatrices(matriz1,matriz2,filas1,columnas1,filas2,columnas2);

	return 0;
}
