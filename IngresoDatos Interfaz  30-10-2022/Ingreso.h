#include <iostream>
#include <string>

using namespace std; 

class Ingreso{
	virtual bool ingresoInt(string numero) = 0;
	virtual bool ingresoFloat(string numero) = 0;
	virtual bool ingresoString(string numero) = 0;	
};
