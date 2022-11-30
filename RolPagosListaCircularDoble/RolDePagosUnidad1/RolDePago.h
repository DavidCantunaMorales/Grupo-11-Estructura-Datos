/**
 * @file RolDePago.h
 * @author Cantunia David
 * @brief Clase RolDePago
 * @version 1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */


#pragma once
#include "Empleado.h"

class RolDePago {
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

	/**
	 * @brief Constructor RolDePago
	 * @param empleado
	 * @param sueldo
	 * @param horasExtras
	 * @param feriados
	 * @param subTotal
	 * @param fondosReserva
	 * @param totalIngresos
	 * @param retencionIess
	 * @param totalRetencion
	 * @param netoRecibir
	 */
	RolDePago(Empleado, float, float, float, float, float, float, float, float, float, float);
	/**
	 * @brief Constructor RolDePago
	 * @param empleado
	 * @param sueldo
	 * @param horasExtras
	 * @param feriados
	 * @param prestamoIess
	 */
	RolDePago(Empleado, float, float, float, float);

	RolDePago() = default;

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

	std::string toString();
};