#pragma once
#include "Empleado.h"

class RolPagos {
private:
	Empleado empleado;
	float sueldo;
	float horasExtras;
	float feriados;
	float subTotal;
	float fondosReserva;
	float totalIngresos;
	float retencionIess;
	float prestamoIess;
	float totalRetencion;
	float netoRecibir;

public:
	RolPagos(Empleado, float, float, float, float, float, float, float, float, float, float);

	RolPagos(Empleado, float, float, float, float);

	RolPagos();

	Empleado getEmpleado() {
		return empleado;
	}

	float getSueldo();

	void setSueldo(float);

	float getHorasExtras();

	void setHorasExtras(float);

	float getFeriados();

	void setFeriados(float);

	float getSubTotal();

	void setSubTotal(float);

	float getFondosReserva();

	void setFondosReserva(float);

	float getTotalIngresos();

	void setTotalIngresos(float);

	float getRetencionIess();

	void setRetencionIess(float);

	float getPrestamoIess();

	void setPrestamoIess(float);

	float getTotalRetencion();

	void setTotalRetencion(float);

	float getNetoRecibir();

	void setNetoRecibir(float);

	void imprimirDatos();
};