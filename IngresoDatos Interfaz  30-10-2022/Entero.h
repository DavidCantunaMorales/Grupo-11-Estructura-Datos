#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

#include "Ingreso.h"

class Entero : public Ingreso{
	public:
		bool ingresoInt(string linea){
			bool esEntero = true;
			int longitud = linea.size();
			
			if (longitud == 0) {
				esEntero = false;
			} else if (longitud == 1 && !isdigit(linea[0])) {
				esEntero = false;
			} else {
				int indice = 0;
				if (linea[0] == '+' || linea[0] == '-') {
					indice = 1;
				} else {
					indice = 0;
				}
				
				while (indice < longitud) {
					if (!isdigit(linea[indice])) {
						esEntero = false;
						break;
					}
					indice++;
				}
			}
			return esEntero;			
		}
		
		bool ingresoFloat(string cad){
			int longitud = cad.length();
			char dato[longitud];
			int i=0, cont=0;
			strcpy(dato,cad.c_str());
    		for(int j=0;j<cad.length();j++){
        		if(dato[j]=='.'){ 
				cont += 1; 
        		}
    		}
    		if(cont >= 2){
    			return false;
			}
    		return true;
		}
		
		bool ingresoString(string cadena){
			char c;
			for(int i = 0; i < cadena.size(); i++){
				c = cadena[i];
				if(isalpha(c)==0){
					if(isspace(c)==0){
						return false;
					}
				}
			}
			return true;		
		}
};
