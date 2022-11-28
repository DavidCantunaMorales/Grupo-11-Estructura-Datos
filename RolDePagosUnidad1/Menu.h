#pragma once
#include <iostream>
#include <istream>
#include <string>

#include "Empleado.h"
#include "RolDePago.h"

#include "ListaCircularDoble.h"
#include "ListaDoble.h"
#include "ListaSimple.h"

#include "ControladorReportes.h"
#include "ControladorRegistro.h"

using namespace std;

class Menu {
public:
    void menuListas();

    
    // MENU LISTAS SIMPLES
    void menuPrincipaListaSimple();
    void menuAdministradorListaSimple();
    void menuOPAdminRegistroListaSimple();
    void menuOPAdminReportesListaSimple();
    

    // MENU LISTAS DOBLES
    void menuPrincipaListaDoble();
    void menuAdministradorListaDoble();
    void menuOPAdminRegistroListaDoble();
    void menuOPAdminReportesListaDoble();
    

    // MENU LISTAS CIRCULARES
	void menuPrincipaListaCircular();
	void menuAdministradorListaCircular();
	void menuOPAdminRegistroListaCircular();
    void menuOPAdminReportesListaCircular();
};

ControladorReportes controladorReporte;
ControladorRegistro controladorRegistro;


void Menu::menuListas() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\n\n\t\t\tSELECCIONE CON QUE LISTA DESEA INICIAR EL PROGRAMA" << endl;
        cout << "\t\t\t--------------------------------------------------" << endl;
        cout << "\n\t  1. LISTA SIMPLE" << endl;
        cout << "\t  2. LISTA DOBLE" << endl;
        cout << "\t  3. LISTA CIRCULAR" << endl;
        cout << "\t  0. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuPrincipaListaSimple();
            break;

        case 2:
            menuPrincipaListaDoble();
            break;

        case 3:
            menuPrincipaListaCircular();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}


void Menu::menuPrincipaListaSimple() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\n\t\t\tROL DE PAGOS" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. INGRESO ADMINISTRADOR" << endl;
        cout << "\t  2. CONSULTAR ROL DE PAGOS" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuAdministradorListaSimple();
            break;

        case 2:
            controladorReporte.buscarRolDePagoLS();
            system("pause>nul");

            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuAdministradorListaSimple() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. REPORTES" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menuOPAdminRegistroListaSimple();
            break;

        case 2:
            menuOPAdminReportesListaSimple();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuOPAdminRegistroListaSimple() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            controladorRegistro.registrarEmpleado();
            system("pause>nul");
            break;

        case 2:
            controladorRegistro.registrarRolPago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuOPAdminReportesListaSimple() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            controladorReporte.mostrarClientesLS();
            system("pause>nul");
            break;

        case 2:
            controladorReporte.buscarRolDePagoLS();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}


void Menu::menuPrincipaListaDoble() {
    int opcion;
    bool repetir = true;
    do {
        system("cls");

        cout << "\n\n\t\t\tROL DE PAGOS" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. INGRESO ADMINISTRADOR" << endl;
        cout << "\t  2. CONSULTAR ROL DE PAGOS" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            menuAdministradorListaDoble();
            break;

        case 2:
            controladorReporte.buscarRolDePagoLD();
            system("pause>nul");

            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuAdministradorListaDoble() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");
        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. REPORTES" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)        {
        case 1:
            menuOPAdminRegistroListaDoble();
            break;

        case 2:
            menuOPAdminReportesListaDoble();
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuOPAdminRegistroListaDoble() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            controladorRegistro.registrarEmpleado();
            system("pause>nul");
            break;

        case 2:
            controladorRegistro.registrarRolPago();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}
void Menu::menuOPAdminReportesListaDoble() {
    int opcion;
    bool repetir = true;

    do {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            controladorReporte.mostrarClientesLD();
            system("pause>nul");
            break;

        case 2:
            controladorReporte.buscarRolDePagoLD();
            system("pause>nul");
            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}


void Menu::menuPrincipaListaCircular() {
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");
        cout << "\n\n\t\t\tROL DE PAGOS" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. INGRESO ADMINISTRADOR" << endl;
        cout << "\t  2. CONSULTAR ROL DE PAGOS" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
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

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

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
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion){
        case 1:
            controladorRegistro.registrarEmpleado();
            system("pause>nul");
            break;

        case 2:
            controladorRegistro.registrarRolPago();
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
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            controladorReporte.mostrarClientes();
            system("pause>nul");
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