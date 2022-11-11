#include<iostream>
#include <cstdlib>
#include <iomanip>
#include "Matriz.h"
#include "ValidarDatos.h"

using namespace std;

ValidarDatos obj;

int Matriz::generar_aleatorio(int linf, int lsup){
    int numero=0;
    numero=linf + rand()% (lsup-linf);
    return numero;
}
bool Matriz::validarMatrices(int f1, int c1, int f2, int c2){
    if((f1 == f2) && (c1 == c2)){
        return true;
    }else return false;
}
void Matriz::llenarMatrizRandom(float matriz[TAM][TAM], int filas, int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j] = this->generar_aleatorio(0,9);
        }
    }
    std::cout<<"\nMatriz generada aleatoriamente: \n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            std::cout<<"\t"<<matriz[i][j];
        }
        std::cout<<"\n";
    }
}
void Matriz::llenarMatriz(float matriz[TAM][TAM], int filas, int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            matriz[i][j] = obj.validarDoubles("\nIngrese el valor para la matriz: ");
        }
    }
    std::cout<<"\n Matriz que ingreso: \n";
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            std::cout<<"\t"<<matriz[i][j];
        }
        std::cout<<"\n";
    }
}
void Matriz::sumaDeMatrices(float matriz1[TAM][TAM],float matriz2[TAM][TAM],
                            int f1, int c1, int f2, int c2){
float matrizR[TAM][TAM];
if(this->validarMatrices(f1,c1,f2,c2)){
    for(int i=0;i<f1;i++){
        for(int j=0;j<c1;j++){
            matrizR[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    std::cout<<"\n\nLa matriz resultante es: \n";
    for(int i=0;i<f1;i++){
        for(int j=0;j<c1;j++){
            std::cout<<"\t"<<matrizR[i][j];
    }
    std::cout<<"\n";
    }
}else{
    std::cout<<"Las matrices no tienen las mismas dimensiones";
}
    
}

void Matriz::multiplicacionDeMatrices(float matriz1[TAM][TAM],float matriz2[TAM][TAM],
                            int f1, int c1, int f2, int c2){
    float matrizC[TAM][TAM];                        	
    if(c1 == f2){ //Condicion para que se realize la multiplicacion de matrices
		// Multiplicacion de la matriz
		cout << "Multiplicacion de Matrices" << endl;
		for(int i = 0; i < f1; i++){
			for(int j = 0; j < c2; j++){
				matrizC[i][j] = 0;
				for(int k = 0; k < c1; k++){
					matrizC[i][j] += matriz1[i][k] * matriz2[k][j];
				}
			}
		}
		
		// Imprimir la multiplicacion
		for(int i = 0; i < f1; i++){
        	for(int j = 0; j < c2; j++){
                cout << setw(6) << matrizC[i][j] << " ";
        	}
        	cout << endl;
    	}
	}else{
		cout << "La multiplicacion no se puede realizar" << endl;
	}

                            	
}
