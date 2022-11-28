#pragma once

#include "NodoDoble.h"
#include "RolPagos.h"
#include "Empleado.h"

#include <iostream>
#include <fstream>

using namespace std;

template<typename T>
class ListaDoble {
private:
    NodoDoble<T>* primero;
    NodoDoble<T>* ultimo;

public:

    bool listaVacia() {
        return (primero == NULL);
    };

    NodoDoble<T>* getPrimero() {
        return primero;
    }

    void setPrimero(NodoDoble<T>* pri) {
        primero = pri;
    }

    NodoDoble<T>* getUltimo() {
        return ultimo;
    }

    void setUltimo(NodoDoble<T>* ult) {
        ultimo = ult;
    }

    ListaDoble();

    bool ListaVacia();

    int tamanioLista();

    NodoDoble<T>* obtenerNodo(int indice);

    // Funciones Para Empleados
    void insertarEmpleado(T*);
    void guardarEmpleado(ListaDoble<Empleado>* empleado);
    void buscarEmpleado(std::string);

    // Funciones Para Rol De Pago
    ListaDoble<RolPagos>* insertarRolDePago(ListaDoble<Empleado>* empleado, std::string cedula);
    void insertarRolPago(ListaDoble<Empleado>* empleado, std::string cedula);
    void guardarRolDePago(ListaDoble<RolPagos>* roldepago);
    void buscarRolPago(std::string);

    // Funcion Principal Imprimir
    void imprimir();

    ////////////////////////////////////////////////////

    void eliminar(int indice);
};

template<typename T>
ListaDoble<T>::ListaDoble() {
    this->primero = NULL;
    this->ultimo = NULL;
}

template<typename T>
bool ListaDoble<T>::ListaVacia() {
    return (this->primero == NULL);
}

template <typename T>
int ListaDoble<T>::tamanioLista() {
    int dimList = 0;
    NodoDoble<T>* actual = primero;
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
NodoDoble<T>* ListaDoble<T>::obtenerNodo(int indice) {
    
    NodoCircular<T>* tmp = primero;
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
void ListaDoble<T>::insertarEmpleado(T* valor) {
    NodoDoble<T>* nuevo = new NodoDoble<T>(valor);
    if (listaVacia()) {
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
void ListaDoble<T>::buscarEmpleado(std::string cedula) {
    NodoDoble<T>* actual = primero;
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
void ListaDoble<T>::guardarEmpleado(ListaDoble<Empleado>* listC) {
    //NodoCircular<Empleado>* actual = empleado1->getPrimero();
    NodoDoble<T>* actual = listC->primero;
    std::ofstream registro;
    remove("ReporteClientesLD.txt");
    //listC->actual = listC->primero;
    if (listC->primero != NULL) {
        registro.open("ReporteClientesLD.txt", std::ios::out | std::ios::app);
        if (registro.is_open()) {
            do {
                registro << "NOMBRE: " << actual->getValor()->getNombre() << std::endl;
                registro << "APELLIDO: " << actual->getValor()->getApellido() << std::endl;
                registro << "CEDULA: " << actual->getValor()->getCedula() << std::endl;
                registro << "CARGO: " << actual->getValor()->getCargo() << std::endl;
                registro << "\n";
                actual = actual->getSiguiente();
            } while (actual != listC->primero);
        }
        std::cout << "\n\n\nRegistro de usuarios generado con exito...\n";
        registro.close();
    }
    else {
        printf("\n\n\n\n La Lista de usuarios se encuentra vacia\n\n");
    }

}

template<typename T>
ListaDoble<RolPagos>* ListaDoble<T>::insertarRolDePago(ListaDoble<Empleado>* listC, std::string cedula) {

    ListaDoble<RolPagos>* listR = new  ListaDoble<RolPagos>();

    NodoDoble<Empleado>* act = listC->getPrimero();

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
void ListaDoble<T>::insertarRolPago(ListaDoble<Empleado>* listC, std::string cedula) {

    NodoDoble<Empleado>* act = listC->getPrimero();

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
void ListaDoble<T>::guardarRolDePago(ListaDoble<RolPagos>* rolDePago) {
    std::ofstream registro;
    remove("ReporteRolPagosLD.txt");
    NodoDoble<T>* actual = rolDePago->primero;
    //rolDePago->actual = rolDePago->primero;
    if (rolDePago->primero != NULL) {
        registro.open("ReporteRolPagosLD.txt", std::ios::out | std::ios::app);
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
void ListaDoble<T>::buscarRolPago(std::string cedula) {
    NodoDoble<T>* actual = primero;
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
void ListaDoble<T>::imprimir() {
    NodoDoble<T>* actual = primero;
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