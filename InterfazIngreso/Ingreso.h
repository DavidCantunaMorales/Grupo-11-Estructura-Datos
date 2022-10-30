#include <iostream>
#include <conio.h>
#include <string>

using namespace std; 

class Ingreso{
	virtual char* ingresoInt(char  const *mensaje) = 0;
	virtual char* ingresoDouble(char  const *mensaje) = 0;
	virtual char* ingresoString(char  const *mensaje) = 0;	
};
