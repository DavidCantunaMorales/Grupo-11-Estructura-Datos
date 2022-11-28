#pragma once
#include <iostream>
#include <istream>
#include <string>

#include "Empleado.h"
#include "RolPagos.h"
#include "ListaCircularDoble.h"
#include "ListaDoble.h"
#include "ListaSimple.h"

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

// OBJETOS DE LA LISTA SIMPLE

string nombreS, apellidoS, cedulaS, cargoS;

ListaSimple<Empleado>* listC = new ListaSimple<Empleado>();
ListaSimple<Empleado>* listE = new ListaSimple<Empleado>();

ListaSimple<RolPagos>* listD = new ListaSimple<RolPagos>();
ListaSimple<RolPagos>* listR = new ListaSimple<RolPagos>();

Empleado* emp;
RolPagos* rolp;


//-------------------------------------------------------------


// OBJETOS DE LA LISTA DOBLE

string nombreD, apellidoD, cedulaD, cargoD;

ListaDoble<Empleado>* listA = new ListaDoble<Empleado>();
ListaDoble<Empleado>* listE1 = new ListaDoble<Empleado>();

ListaDoble<RolPagos>* listB = new ListaDoble<RolPagos>();
ListaDoble<RolPagos>* listR1 = new ListaDoble<RolPagos>();

Empleado* emp2;
RolPagos* rolp2;


//-------------------------------------------------------------


// OBJETOS DE LA LISTA CIRCULAR

string nombre, apellido, cedula, cargo;

ListaCircularDoble<Empleado>* list = new ListaCircularDoble<Empleado>();
ListaCircularDoble<Empleado>* listE2 = new ListaCircularDoble<Empleado>();

ListaCircularDoble<RolPagos>* listP = new ListaCircularDoble<RolPagos>();
ListaCircularDoble<RolPagos>* listR2 = new ListaCircularDoble<RolPagos>();

Empleado* emp1;
RolPagos* rolp1;

//-------------------------------------------------------------

void Menu::menuListas() {
    int opcion;
    bool repetir = true;

    do
    {
        system("cls");

        cout << "\n\n\t\t\tSELECCIONE CON QUE LISTA DESEA INICIAR EL PROGRAMA" << endl;
        cout << "\t\t\t--------------------------------------------------" << endl;
        cout << "\n\t  1. LISTA SIMPLE" << endl;
        cout << "\t  2. LISTA DOBLE" << endl;
        cout << "\t  3. LISTA CIRCULAR" << endl;
        cout << "\t  0. SALIR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
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

        switch (opcion)
        {
        case 1:
            menuAdministradorListaSimple();
            break;

        case 2:

            cout << "Ingrese el numero de cedula" << endl;
            cin >> cedulaS;
            listD->buscarRolPago(cedulaS);
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. REPORTES" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            rewind(stdin);
            cout << "Ingrese los nombres del empleado" << endl;
            rewind(stdin);
            getline(cin, nombreS);
            rewind(stdin);
            cout << "Ingrese los apellidos del empleado" << endl;
            rewind(stdin);
            getline(cin, apellidoS);
            rewind(stdin);
            cout << "Ingrese el numero de cedula del empleado" << endl;
            rewind(stdin);
            cin >> cedulaS;
            rewind(stdin);
            cout << "Ingrese el cargo que ocupa en la empresa" << endl;
            rewind(stdin);
            getline(cin, cargoS);
            rewind(stdin);

            emp = new Empleado(nombreS, apellidoS, cedulaS, cargoS);
            
            listC->insertarEmpleado(emp);
            listE->guardarEmpleado(listC);

            cout << "EMPLEADO REGISTRADO CORRECTAMENTE" << endl;
            system("pause>nul");

            break;

        case 2:

            cout << "Ingrese el numero de cedula del empleado" << endl;
            cin >> cedulaS;
            listD->insertarRolPago(listC, cedulaS);
            listR->guardarRolDePago(listD);

            cout << "Rol de pagos generado" << endl;
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            listC->imprimir();
            system("pause>nul");

            break;

        case 2:

            cout << "Ingrese el numero de cedula" << endl;
            cin >> cedulaD;
            listD->buscarRolPago(cedulaS);
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

        switch (opcion)
        {
        case 1:
            menuAdministradorListaDoble();
            break;

        case 2:

            cout << "Ingrese el numero de cedula" << endl;
            cin >> cedulaD;
            listB->buscarRolPago(cedulaD);
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. REPORTES" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            rewind(stdin);
            cout << "Ingrese los nombres del empleado" << endl;
            rewind(stdin);
            getline(cin, nombreD);
            rewind(stdin);
            cout << "Ingrese los apellidos del empleado" << endl;
            rewind(stdin);
            getline(cin, apellidoD);
            rewind(stdin);
            cout << "Ingrese el numero de cedula del empleado" << endl;
            rewind(stdin);
            cin >> cedulaD;
            rewind(stdin);
            cout << "Ingrese el cargo que ocupa en la empresa" << endl;
            rewind(stdin);
            getline(cin, cargoD);
            rewind(stdin);

            emp2 = new Empleado(nombreD, apellidoD, cedulaD, cargoD);
            
            listA->insertarEmpleado(emp2);
            listE1->guardarEmpleado(listA);

            cout << "EMPLEADO REGISTRADO CORRECTAMENTE" << endl;
            system("pause>nul");

            break;

        case 2:

            cout << "Ingrese el numero de cedula del empleado" << endl;
            cin >> cedulaD;
            
            listB->insertarRolPago(listA, cedulaD);
            listR1->guardarRolDePago(listB);
            
            cout << "Rol de pagos generado" << endl;
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            listA->imprimir();
            system("pause>nul");

            break;

        case 2:

            cout << "Ingrese el numero de cedula" << endl;
            cin >> cedulaD;
            listB->buscarRolPago(cedulaD);
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

        switch (opcion)
        {
        case 1:
            menuAdministradorListaCircular();
            break;

        case 2:
            
            cout << "Ingrese el numero de cedula" << endl;
            cin >> cedula;
            listP->buscarRolPago(cedula);
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRO" << endl;
        cout << "\t  2. REPORTES" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. REGISTRAR EMPLEADO" << endl;
        cout << "\t  2. REGISTRAR ROL DE PAGO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            rewind(stdin);
            cout << "Ingrese los nombres del empleado" << endl;
            rewind(stdin);
            getline(cin, nombre);
            rewind(stdin);
            cout << "Ingrese los apellidos del empleado" << endl;
            rewind(stdin);
            getline(cin, apellido);
            rewind(stdin);
            cout << "Ingrese el numero de cedula del empleado" << endl;
            rewind(stdin);
            cin >> cedula;
            rewind(stdin);
            cout << "Ingrese el cargo que ocupa en la empresa" << endl;
            rewind(stdin);
            getline(cin, cargo);
            rewind(stdin);

            emp1 = new Empleado(nombre, apellido, cedula, cargo);
            list->insertarEmpleado(emp1);
            listE2->guardarEmpleado(list);

            cout << "EMPLEADO REGISTRADO CORRECTAMENTE" << endl;
            system("pause>nul");

            break;

        case 2:

            cout << "Ingrese el numero de cedula del empleado" << endl;
            cin >> cedula;
            
            listP->insertarRolPago(list, cedula);
            listR2->guardarRolDePago(listP);
            
            cout << "Rol de pagos generado" << endl;
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

    do
    {
        system("cls");

        cout << "\n\n\t\t\tMENU ADMINISTRADOR" << endl;
        cout << "\t\t\t--------------" << endl;
        cout << "\n\t  1. VER EMPLEADOS" << endl;
        cout << "\t  2. BUSCAR EMPLEADO" << endl;
        cout << "\t  0. REGRESAR" << endl;

        cout << "\n\tIngrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            list->imprimir();
            system("pause>nul");

            break;

        case 2:

            cout << "Ingrese el numero de cedula" << endl;
            cin >> cedula;
            listP->buscarRolPago(cedula);
            system("pause>nul");

            break;

        case 0:
            repetir = false;
            break;
        }
    } while (repetir);
}