#include <iostream>
#include <string>

#include "Empleado.h"
#include "RolPagos.h"
#include "ListaCircularDoble.h"
#include "Menu.h"

using namespace std;

int main(){
    Menu menu;
    menu.menuListas();
}


/*
string nombre = "Jose";
string apellido = "Morales";
string cedula = "175302";
string cargo = "cajera";

string nombre1 = "sdadDavid";
string apellido1 = "Cantunia";
string cedula1 = "1753020393";
string cargo1 = "cajero";


Empleado* emp1 = new Empleado(nombre, apellido, cedula, cargo);
Empleado* emp2 = new Empleado(nombre1, apellido1, cedula1, cargo1);

//RolPagos* rolp1 = new RolPagos(*emp1, 430.00, 408.50, 86.00, 86.86);
//RolPagos* rolp2 = new RolPagos(*emp2, 430.00, 408.50, 86.00, 86.86);

RolPagos::RolPagos(Empleado empleado, float sueldo, float horasExtras, float feriados,
float totalIngresos, float prestamoIess)


ListaCircularDoble<Empleado>* list = new ListaCircularDoble<Empleado>();
ListaCircularDoble<Empleado>* listA = new ListaCircularDoble<Empleado>();

ListaCircularDoble<RolPagos>* listP = new ListaCircularDoble<RolPagos>();
ListaCircularDoble<RolPagos>* listD = new ListaCircularDoble<RolPagos>();
ListaCircularDoble<RolPagos>* listE = new ListaCircularDoble<RolPagos>();

list->insertarEmpleado(emp2);
list->insertarEmpleado(emp1);
list->imprimir();

//listP->insertarEmpleado(rolp1);
//listP->insertarEmpleado(rolp2);

//listP->buscarRolPago("175302");
//list->buscarEmpleado("17532302");

listA->guardarEmpleado(list);

//listD = listP->insertarRolDePago(list, "1753020393");
//listD = listP->insertarRolDePago(list, "175302");

listP->insertarRolPago(list, "1753020393");
listP->insertarRolPago(list, "175302");

listP->imprimir();

listD->guardarRolDePago(listP);

std::cout << "El rol de pago buscado" << endl;
listP->buscarRolPago("175302");


//listP->imprimir();

//list->bucarEmpleado("1753020393");

// list->imprimir();



     MENU:
         INGRESO ADMINISTRADOR
             REGISTRAR EMPLEADOS
             BUSCAR EMPLEADO
             MODIFICAR EMPLEADO
             ELIMINAR EMPLEADO
             GENERAR ROL DE PAGO
             INFORME CON LOS EMPLEADOS
             INFORME CON LOS ROLES DE PAGO
         INGRESO EMPLEADO
             VER ROL DE PAGO
             INFORME DE SU ROL DE PAGO
 */