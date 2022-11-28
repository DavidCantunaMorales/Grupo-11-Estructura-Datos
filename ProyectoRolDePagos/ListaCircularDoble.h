#pragma once
#include "NodoCircular.h"
#include "RolPagos.h"
#include "Empleado.h"

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class ListaCircularDoble {
private:
    NodoCircular<T>* primero;
    NodoCircular<T>* actual;
    NodoCircular<T>* ultimo;

public:

    ListaCircularDoble();

    bool ListaVacia();
    
    int tamanioLista();

    NodoCircular<T>* obtenerNodo(int indice);

    // Funciones Para el ingreso de Empleados
    void insertarEmpleado(T*);
    void guardarEmpleado(ListaCircularDoble<Empleado>* empleado);
    void buscarEmpleado(std::string);

    
    // Funciones Para el Rol De Pago
    ListaCircularDoble<RolPagos>* insertarRolDePago(ListaCircularDoble<Empleado>* empleado, std::string cedula);
    void insertarRolPago(ListaCircularDoble<Empleado>* empleado, std::string cedula);
    void guardarRolDePago(ListaCircularDoble<RolPagos>* roldepago);
    void buscarRolPago(std::string);
    
    void imprimir();

    NodoCircular<T>* getPrimero() {
        return primero;
    }

};


template<typename T>
ListaCircularDoble<T>::ListaCircularDoble() {
    this->primero = NULL;
    this->actual = NULL;
    this->ultimo = NULL;
}

template<typename T>
bool ListaCircularDoble<T>::ListaVacia() {
    return (this->primero == NULL);
}

template <typename T>
int ListaCircularDoble<T>::tamanioLista() {
    int dim = 0;
    actual = primero;
    if (primero != NULL) {
        do {
            dim++;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        return 0;
    }
    return dim;
}

template<typename T>
NodoCircular<T>* ListaCircularDoble<T>::obtenerNodo(int indice){
    int i = 0;
    NodoCircular<T>* tmp = primero;

    if (indice < 0 || indice >= tamanioLista) {
        return nullptr;
    }

    if (tmp == nullptr)
        return nullptr;
    do {
        if (i == indice) {
            return tmp;
        }
        tmp = tmp->getSiguiente();
        i++;
    } while (tmp != primero);

    return NULL;
}

template<typename T>
void ListaCircularDoble<T>::insertarEmpleado(T* valor) {
    NodoCircular<T>* nuevo = new NodoCircular<T>(valor);
    if (ListaVacia()) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = primero;
        primero->setAnterior(ultimo);
    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        nuevo->setAnterior(ultimo);
        ultimo = nuevo;
        primero->setAnterior(ultimo);
    }
}

template<typename T>
void ListaCircularDoble<T>::buscarEmpleado(std::string cedula) {
    actual = primero;
    bool encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getValor()->getCedula() == cedula) {
                encontrado = true;
                actual->getValor()->imprimirDatos();
            }
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            std::cout << "El numero de cedula no se encuentra registrado" << std::endl;
        }
    }
    else {
        std::cout << "La lista esta vacia" << std::endl;
    }
}

template<typename T>
void ListaCircularDoble<T>::guardarEmpleado(ListaCircularDoble<Empleado>* listC) {
    //NodoCircular<Empleado>* actual = empleado1->getPrimero();
    std::ofstream registro;
    remove("ReporteClientes.txt");
    listC->actual = listC->primero;
    if (listC->primero != NULL) {
        registro.open("ReporteClientes.txt", std::ios::out | std::ios::app);
        if (registro.is_open()) {
            do {
                registro << "NOMBRE: " << listC->actual->getValor()->getNombre() << std::endl;
                registro << "APELLIDO: " << listC->actual->getValor()->getApellido() << std::endl;
                registro << "CEDULA: " << listC->actual->getValor()->getCedula() << std::endl;
                registro << "CARGO: " << listC->actual->getValor()->getCargo() << std::endl;
                registro << "\n";
                listC->actual = listC->actual->getSiguiente();
            } while (listC->actual != listC->primero);
        }
        std::cout << "\n\n\nRegistro de usuarios generado con exito...\n";
        registro.close();
    }
    else {
        printf("\n\n\n\n La Lista de usuarios se encuentra vacia\n\n");
    }
    
}

template<typename T>
ListaCircularDoble<RolPagos>* ListaCircularDoble<T>::insertarRolDePago(ListaCircularDoble<Empleado>* listC, std::string cedula) {

    ListaCircularDoble<RolPagos>* listR = new  ListaCircularDoble<RolPagos>();
   
    NodoCircular<Empleado>* act = listC->getPrimero();
    
    bool encontrado = false;
   
    string nombre, apellido, ced, cargo;
 
    if (listC->ListaVacia()) {
        std::cout << "No existen empleados registrados" << endl;
        return 0;
    }
    else {
        if (listC->getPrimero() != NULL) {
            do {
                if (act->getValor()->getCedula() == cedula) {
                    nombre = act->getValor()->getNombre();
                    apellido = act->getValor()->getApellido();
                    ced = act->getValor()->getCedula();
                    cargo = act->getValor()->getCargo();

                    Empleado* emp1 = new Empleado(nombre, apellido, ced, cargo);
                    RolPagos* rolp2 = new RolPagos(*emp1, 430.00, 408.50, 86.00, 86.86);

                    listR->insertarEmpleado(rolp2);
                    encontrado = true;
                }
                act = act->getSiguiente();
            } while (act != listC->getPrimero() && encontrado != true);
            if (!encontrado) {
                std::cout << "El numero de cedula no se encuentra registrado" << std::endl;
            }
        }
        return listR;
    }
}

template<typename T>
void ListaCircularDoble<T>::insertarRolPago(ListaCircularDoble<Empleado>* listC, std::string cedula) {
    
    NodoCircular<Empleado>* act = listC->getPrimero();

    bool encontrado = false;

    string nombre, apellido, ced, cargo;

    if (listC->ListaVacia()) {
        std::cout << "No existen empleados registrados" << endl;
    }
    else {
        if (listC->getPrimero() != NULL) {
            do {
                if (act->getValor()->getCedula() == cedula) {
                    nombre = act->getValor()->getNombre();
                    apellido = act->getValor()->getApellido();
                    ced = act->getValor()->getCedula();
                    cargo = act->getValor()->getCargo();

                    Empleado* emp1 = new Empleado(nombre, apellido, ced, cargo);
                    RolPagos* rolp2 = new RolPagos(*emp1, 430.00, 408.50, 86.00, 86.86);

                    insertarEmpleado(rolp2);
                    encontrado = true;
                }
                act = act->getSiguiente();
            } while (act != listC->getPrimero() && encontrado != true);
            if (!encontrado) {
                std::cout << "El numero de cedula no se encuentra registrado" << std::endl;
            }
        }
    }
}

template<typename T>
void ListaCircularDoble<T>::guardarRolDePago(ListaCircularDoble<RolPagos>* rolDePago){
    std::ofstream registro;
    remove("ReporteRolPagos.txt");
    rolDePago->actual = rolDePago->primero;
    if (rolDePago->primero != NULL) {
        registro.open("ReporteRolPagos.txt", std::ios::out | std::ios::app);
        if (registro.is_open()) {
            do {
                registro << "NOMBRE:   " << rolDePago->actual->getValor()->getEmpleado().getNombre() << std::endl;
                registro << "APELLIDO: " << rolDePago->actual->getValor()->getEmpleado().getApellido() << std::endl;
                registro << "CEDULA:   " << rolDePago->actual->getValor()->getEmpleado().getCedula() << std::endl;
                registro << "CARGO:    " << rolDePago->actual->getValor()->getEmpleado().getCargo() << std::endl;
                registro << "INFORMACION ROL DE PAGO: " << std::endl;
                registro << "  SUELDO:          " << rolDePago->actual->getValor()->getSueldo() << std::endl;
                registro << "  HORAS EXTAS:     " << rolDePago->actual->getValor()->getHorasExtras() << std::endl;
                registro << "  FERIADOS:        " << rolDePago->actual->getValor()->getFeriados() << std::endl;
                registro << "  SUB TOTAL:       " << rolDePago->actual->getValor()->getSubTotal() << std::endl;
                registro << "  FONDOS RESERVA:  " << rolDePago->actual->getValor()->getFondosReserva() << std::endl;
                registro << "  TOTAL INGRESOS:  " << rolDePago->actual->getValor()->getTotalIngresos() << std::endl;
                registro << "  RETENCION IESS:  " << rolDePago->actual->getValor()->getRetencionIess() << std::endl;
                registro << "  PRESTAMO IESS:   " << rolDePago->actual->getValor()->getPrestamoIess() << std::endl;
                registro << "  RETENCION TOTAL: " << rolDePago->actual->getValor()->getTotalRetencion() << std::endl;
                registro << "  SUELDO NETO:     " << rolDePago->actual->getValor()->getNetoRecibir() << std::endl;
                registro << "---------------------------------------------------------------------------------------------" << std::endl;
                registro << "\n";
                rolDePago->actual = rolDePago->actual->getSiguiente();
            } while (rolDePago->actual != rolDePago->primero);
        }
        std::cout << "\n\n\nRegistro de usuarios generado con exito...\n";
        registro.close();
    }
    else {
        printf("\n\n\n\n La Lista de usuarios se encuentra vacia\n\n");
    }
}

template<typename T>
void ListaCircularDoble<T>::buscarRolPago(std::string cedula) {
    actual = primero;
    int nodoBuscado = 0, encontrado = false;
    if (primero != NULL) {
        do {
            if (actual->getValor()->getEmpleado().getCedula() == cedula) {
                encontrado = true;
                actual->getValor()->imprimirDatos();
            }
            actual = actual->getSiguiente();
        } while (actual != primero && encontrado != true);
        if (!encontrado) {
            std::cout << "El numero de cedula no se encuentra registrado" << std::endl;
        }
    }
    else {
        std::cout << "La lista esta vacia" << std::endl;
    }
}

template <typename T>
void ListaCircularDoble<T>::imprimir() {
    actual = primero;
    if (primero != NULL) {
        do {
            actual->getValor()->imprimirDatos();
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        printf("\n\n\n La Lista se encuentra vacia\n\n");
    }
}

