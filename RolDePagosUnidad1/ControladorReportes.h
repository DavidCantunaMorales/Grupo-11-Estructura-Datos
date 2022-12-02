#pragma once
#include "ControladorRegistro.h"

class ControladorReportes {
private:
	ControladorRegistro controladorRegistro;

public:
	void mostrarClientesLC();
	void mostrarRolDePagoLC();
	void buscarRolDePagoLC();

	void mostrarClientesLD();
	void mostrarRolDePagoLD();
	void buscarRolDePagoLD();

	void mostrarClientesLS();
	void mostrarRolDePagoLS();
	void buscarRolDePagoLS();

};
