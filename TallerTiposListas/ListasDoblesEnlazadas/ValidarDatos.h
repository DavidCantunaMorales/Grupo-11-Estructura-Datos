#pragma once
#include <string>

class ValidarDatos
{
public:
	virtual int validarEntero(char  const* mensaje);
	virtual float validarDoubles(char const* mensaje);
	virtual std::string validarLetras(char const* mensaje);
protected:
private:

};