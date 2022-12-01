/**
 * @file Menu.h
 * @author Cantuña David
 * @brief Clase Menu
 * @version 1
 * @date 2022-11-29
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once
#include <iostream>
#include <istream>
#include <string>

#include "Empleado.h"
#include "RolDePago.h"

#include "ListaCircularDoble.h"


#include "ControladorReportes.h"
#include "ControladorRegistro.h"
#include "Login.h"
#include "ValidarDatos.h"

using namespace std;

class Menu {
public:
 
    // MENU LISTAS CIRCULARES
    /**
     * @brief menuPrincipaListaCircular
     */
    void menuPrincipaListaCircular();
    /**
     * @brief menuAdministradorListaCircular
     */
	void menuAdministradorListaCircular();
    /**
     * @brief menuOPAdminRegistroListaCircular
     */
    void menuOPAdminRegistroListaCircular();
    /**
    * @brief menuOPAdminReportesListaCircular
    */
    void menuOPAdminReportesListaCircular();
};

ControladorReportes controladorReporte;
ControladorRegistro controladorRegistro;
Login ingresoSistema;
ValidarDatos val;


void Menu::menuPrincipaListaCircular() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. Ingreso del administrador" << endl;
        cout << "\t  2. Consultar el rode pago" << endl;
        cout << "\t  0. Regresar" << endl;

        cout << endl;
        opcion = val.validarEntero("ingrese una opcion: ");

        switch (opcion) {
        case 1:
            ingresoSistema.ingresar();
            menuAdministradorListaCircular();
            break;

        case 2:
            controladorReporte.buscarRolDePago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
 
}
void Menu::menuAdministradorListaCircular() {
    int opcion;
    bool repetir = true;

    do{
        system("cls");
        cout << "\n\t  1. Regristro" << endl;
        cout << "\t  2. Reportes" << endl;
        cout << "\t  0. Regresar" << endl;

        cout << endl;
        opcion = val.validarEntero("Ingrese una opcion: ");

        switch (opcion) {
        case 1:
            menuOPAdminRegistroListaCircular();
            break;

        case 2:
            menuOPAdminReportesListaCircular();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuOPAdminRegistroListaCircular() {
    int opcion;
    bool repetir = true;

    do{
        system("cls");

        cout << "\n\t  1. Registrar empleado" << endl;
        cout << "\t  2. Registrar rol de pago" << endl;
        cout << "\t  3. Eliminar empleado" << endl;
        cout << "\t  4. Eliminar rol de pago" << endl;
        cout << "\t  0. Regresar" << endl;

        cout << endl;
        opcion = val.validarEntero("Ingrese una opcion: ");

        switch (opcion){
        case 1:
            controladorRegistro.registrarEmpleado();
            system("pause>nul");
            break;

        case 2:
            controladorRegistro.registrarRolPago();
            system("pause>nul");
            break;

        case 3:
            controladorRegistro.eliminarEmpleado();
            system("pause>nul");
            break;

        case 4:
            controladorRegistro.eliminarRolDePago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);

}
void Menu::menuOPAdminReportesListaCircular() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\n\t  1. Ver empleado" << endl;
        cout << "\t  2. Ver rol de pago" << endl;
        cout << "\t  0. Regresar" << endl;

        cout << endl;
        opcion = val.validarEntero("Ingrese una opcion: ");

        switch (opcion) {
        case 1:
            controladorReporte.mostrarClientes();
            system("pause>nul");
            break;

        case 2:
            //controladorReporte.buscarRolDePago();
            controladorReporte.mostrarRolDePago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}