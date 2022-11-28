#pragma once
#include <iostream>
#include "NodoSimple.h"
#include "RolPagos.h"
#include "Empleado.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

template <typename T>
class ListaSimple {
private:
    NodoSimple<T>* primero;
    NodoSimple<T>* ultimo;

public:

    bool listaVacia() {
        return (primero == NULL);
    };

    NodoSimple<T>* getPrimero() {
        return primero;
    }

    void setPrimero(NodoSimple<T>* pri) {
        primero = pri;
    }

    NodoSimple<T>* getUltimo() {
        return ultimo;
    }

    void setUltimo(NodoSimple<T>* ult) {
        ultimo = ult;
    }

    ListaSimple();

    int tamanioLista();

    bool ListaVacia();

    NodoSimple<T>* obtenerNodo(int indice);


    // Funciones Para Empleados
    void insertarEmpleado(T*);
    void guardarEmpleado(ListaSimple<Empleado>* empleado);
    void buscarEmpleado(std::string);

    // Funciones Para Rol De Pago
    ListaSimple<RolPagos>* insertarRolDePago(ListaSimple<Empleado>* empleado, std::string cedula);
    void insertarRolPago(ListaSimple<Empleado>* empleado, std::string cedula);
    void guardarRolDePago(ListaSimple<RolPagos>* roldepago);
    void buscarRolPago(std::string);

    // Funcion Principal Imprimir
    void imprimir();

    //////////////////////////////////////////////////////////////////////////////////

    void insertarEn(int indice, int val);

    void eliminar(int indice);
};

template<typename T>
ListaSimple<T>::ListaSimple() {
    this->primero = NULL;
    this->ultimo = NULL;
}

template<typename T>
bool ListaSimple<T>::ListaVacia() {
    return (this->primero == NULL);
}

template <typename T>
int ListaSimple<T>::tamanioLista() {
    int dimList = 0;
    ListaSimple<T>* actual = primero;
    if (primero != NULL) {
        do {
            dimList++;
            actual = actual->getSiguiente();
        } while (actual != primero);
    }
    else {
        return 0;
    }
    return dimList;
}

template<typename T>
NodoSimple<T>* ListaSimple<T>::obtenerNodo(int indice) {

    NodoSimple<T>* tmp = primero;
    int i = 0;

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
void ListaSimple<T>::insertarEmpleado(T* valor) {
    NodoSimple<T>* nuevo = new NodoSimple<T>(valor);;
    if (listaVacia()) {
        primero = nuevo;
        primero->setSiguiente(primero);
        ultimo = nuevo;

    }
    else {
        ultimo->setSiguiente(nuevo);
        nuevo->setSiguiente(primero);
        ultimo = nuevo;
    }
}

template<typename T>
void ListaSimple<T>::buscarEmpleado(std::string cedula) {
    NodoSimple<T>* actual = primero;
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
void ListaSimple<T>::guardarEmpleado(ListaSimple<Empleado>* listC) {
    //NodoCircular<Empleado>* actual = empleado1->getPrimero();
    NodoSimple<T>* actual = listC->getPrimero();
    std::ofstream registro;
    remove("ReporteClientesLS.txt");
    //listC->actual = listC->primero;
    if (listC->getPrimero() != NULL) {
        registro.open("ReporteClientesLS.txt", std::ios::out | std::ios::app);
        if (registro.is_open()) {
            do {
                registro << "NOMBRE: " << actual->getValor()->getNombre() << std::endl;
                registro << "APELLIDO: " << actual->getValor()->getApellido() << std::endl;
                registro << "CEDULA: " << actual->getValor()->getCedula() << std::endl;
                registro << "CARGO: " << actual->getValor()->getCargo() << std::endl;
                registro << "\n";
                actual = actual->getSiguiente();
            } while (actual != listC->getPrimero());
        }
        std::cout << "\n\n\nRegistro de usuarios generado con exito...\n";
        registro.close();
    }
    else {
        printf("\n\n\n\n La Lista de usuarios se encuentra vacia\n\n");
    }

}

template<typename T>
ListaSimple<RolPagos>* ListaSimple<T>::insertarRolDePago(ListaSimple<Empleado>* listC, std::string cedula) {

    ListaSimple<RolPagos>* listR = new  ListaSimple<RolPagos>();

    NodoSimple<Empleado>* act = listC->getPrimero();

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
void ListaSimple<T>::insertarRolPago(ListaSimple<Empleado>* listC, std::string cedula) {

    NodoSimple<Empleado>* act = listC->getPrimero();

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
void ListaSimple<T>::guardarRolDePago(ListaSimple<RolPagos>* rolDePago) {
    std::ofstream registro;
    remove("ReporteRolPagosLS.txt");
    NodoSimple<T>* actual = rolDePago->primero;
    //rolDePago->actual = rolDePago->primero;
    if (rolDePago->primero != NULL) {
        registro.open("ReporteRolPagosLS.txt", std::ios::out | std::ios::app);
        if (registro.is_open()) {
            do {
                registro << "NOMBRE:   " << actual->getValor()->getEmpleado().getNombre() << std::endl;
                registro << "APELLIDO: " << actual->getValor()->getEmpleado().getApellido() << std::endl;
                registro << "CEDULA:   " << actual->getValor()->getEmpleado().getCedula() << std::endl;
                registro << "CARGO:    " << actual->getValor()->getEmpleado().getCargo() << std::endl;
                registro << "INFORMACION ROL DE PAGO: " << std::endl;
                registro << "  SUELDO:          " << actual->getValor()->getSueldo() << std::endl;
                registro << "  HORAS EXTAS:     " << actual->getValor()->getHorasExtras() << std::endl;
                registro << "  FERIADOS:        " << actual->getValor()->getFeriados() << std::endl;
                registro << "  SUB TOTAL:       " << actual->getValor()->getSubTotal() << std::endl;
                registro << "  FONDOS RESERVA:  " << actual->getValor()->getFondosReserva() << std::endl;
                registro << "  TOTAL INGRESOS:  " << actual->getValor()->getTotalIngresos() << std::endl;
                registro << "  RETENCION IESS:  " << actual->getValor()->getRetencionIess() << std::endl;
                registro << "  PRESTAMO IESS:   " << actual->getValor()->getPrestamoIess() << std::endl;
                registro << "  RETENCION TOTAL: " << actual->getValor()->getTotalRetencion() << std::endl;
                registro << "  SUELDO NETO:     " << actual->getValor()->getNetoRecibir() << std::endl;
                registro << "---------------------------------------------------------------------------------------------" << std::endl;
                registro << "\n";
                actual = actual->getSiguiente();
            } while (actual != rolDePago->primero);
        }
        std::cout << "\n\n\nRegistro de usuarios generado con exito...\n";
        registro.close();
    }
    else {
        printf("\n\n\n\n La Lista de usuarios se encuentra vacia\n\n");
    }
}

template<typename T>
void ListaSimple<T>::buscarRolPago(std::string cedula) {
    NodoSimple<T>* actual = primero;
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
void ListaSimple<T>::imprimir() {
    NodoSimple<T>* actual = primero;
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