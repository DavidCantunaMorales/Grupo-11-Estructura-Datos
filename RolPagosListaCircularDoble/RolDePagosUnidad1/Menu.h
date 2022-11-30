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
    void menuPrincipaListaCircular();
	void menuAdministradorListaCircular();
	void menuOPAdminRegistroListaCircular();
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
        cout << "\n\n\t\t\tROL DE PAGOS" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. INGRESO ADMINISTRADOR" << endl;
        cout << "\t  2. CONSULTAR ROL DE PAGOS" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << endl;
        opcion = val.validarEntero("INGRESE UNA OPCION: ");

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
        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. REPORTES" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << endl;
        opcion = val.validarEntero("INGRESE UNA OPCION: ");

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

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  3. ELIMINAR EMPLEADD" << endl;
        cout << "\t  4. ELIMINAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << endl;
        opcion = val.validarEntero("INGRESE UNA OPCION: ");

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
        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. VER ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << endl;
        opcion = val.validarEntero("INGRESE UNA OPCION: ");

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