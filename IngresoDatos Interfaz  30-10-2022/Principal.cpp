#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

#include "Entero.h"

using namespace std;


int main(int argc, char** argv) {
	
	Entero* ent = new Entero();
    int opcion;
    bool repetir = true;
    
    string linea, cadena;
	int numero;
	bool repite = true;
    
    do {
        system("cls");
        cout << "\n\nMenu de Opciones" << endl;
        cout << "1. Ingreso Numeros Enteros" << endl;
        cout << "2. Ingreso Numeros Decimales" << endl;
        cout << "3. Ingreso Tipo Texto" << endl;
        cout << "0. SALIR" << endl;
        
        cout << "\nIngrese una opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                do {
                	fflush(stdin);
					cout << "\nIngrese un valor entero: ";
					getline(cin, linea);
					if (ent->ingresoInt(linea)) {
						repite = false;
					} else {
						cout << "No has ingresado un valor entero. Intentalo nuevamente" << endl;
					}
				} while (repite); 
				
				numero = atoi(linea.c_str());              
                cout << "El numero ingresado fue: " << numero << endl;
                
                system("pause>nul"); // Pausa
                break;
                
            case 2:
                do {
                	fflush(stdin);
					cout << "\nIngrese un valor decimal: ";
					getline(cin, linea);
					if (ent->ingresoFloat(linea)) {
						repite = false;
					} else {
						cout << "No has ingresado un valor decimal. Intentalo nuevamente" << endl;
					}
				} while (repite); 
				
				numero = atof(linea.c_str());              
                cout << "El numero ingresado fue: " << numero << endl;             
                
                system("pause>nul"); // Pausa
                break;
                
            case 3:
                do {
                	fflush(stdin);
					cout << "\nIngrese un texto: ";
					getline(cin, linea);
					if (ent->ingresoString(linea)) {
						repite = false;
					} else {
						cout << "No has ingresado solo letras. Intentalo nuevamente" << endl;
					}
				} while (repite); 
				
				cadena = linea.c_str();              
                cout << "El texto ingresado fue: " << cadena << endl;               
                
                system("pause>nul"); // Pausa            
                break;
                           
            case 0:
            	repetir = false;
            	break;
        }        
    } while (repetir);

	return 0;
}

