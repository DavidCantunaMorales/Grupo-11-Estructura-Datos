#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
class Lista{
	private:
		Nodo *primero; //cabeza 
		Nodo *actual; //cola
		bool listaVacia(){
			return (this->primero==NULL);
		}
	public:
		Lista(){
			this->primero=NULL;
			this->actual=NULL;
		}

	void insertar(int val){
		Nodo *nuevo = new Nodo(val);
		if (listaVacia()){
			this->primero=nuevo;
			cout<<"Primero: "<<primero->valor<<endl;
		}
		else{
			//se asigna la direccion de memoria del nuevo nodo creado al actual
			//cout<<"Nuevo: "<<nuevo->valor<<endl;
			//se enva la direccion de nuevo al actual
			this->actual->siguiente=nuevo;
			//cout<<"Actual: "<<actual->valor<<endl;
		}
		//se manda el valor de nuevo
		//cout<<"new: "<<nuevo->valor<<endl;
		this->actual=nuevo;
		//cout<<"Actual2: "<<actual->valor<<endl;
	}
	void mostrarLista(){
		Nodo *tmp=this->primero;
		while(tmp){
			cout<<tmp->valor<<"-->";
			tmp=tmp->siguiente;
		}
		cout<<"NULL";
	}
	int encontrarCola(){
		Nodo *tmp = this->primero;
		int datos = 0;
		while(tmp){
			datos++;
			tmp=tmp->siguiente;
		}
		return datos;
	}
void agregarFinal(int v)
{
	Nodo* nuevo = new Nodo(v);
	if (listaVacia()) {
		primero = nuevo;
	}
	else {
		Nodo* aux = primero;
		while (aux->siguiente != NULL)
			aux = aux->siguiente;
		aux->siguiente = nuevo;
	}
}
void agregarInicio(int v)
{
	Nodo* nuevo = new Nodo(v);
	if (listaVacia()) {
		primero = nuevo;
	}
	else {
		nuevo->siguiente = primero;
		primero = nuevo;
	}
}
void eliminarElemento(void)
{
	int val;
	if (primero) {
		cout << "Ingrese el valor a eliminar: ";
		cin >> val;
		cout << "\n";
		Nodo* aux = primero;
		Nodo* pre = new Nodo(val);
		while (aux) {
			if (aux->valor == val && primero == aux) {
				eliminarInicio();
				break;
			}
			else if (aux->valor == val && aux->siguiente == nullptr) {
				eliminarFinal();
				break;
			}
			else if (aux->valor == val && aux->siguiente != nullptr) {
				pre->siguiente = aux->siguiente;
				aux->siguiente = nullptr;
				delete aux;
				break;
			}
			else {
				pre = aux;
				aux = aux->siguiente;
			}
		}
	}
	else {
		cout << "\nLista Vacia\n";
	}
	cout << "\n";
}

void eliminarInicio() {
	Nodo* aux = primero;
	primero = primero->siguiente;
	aux->siguiente = nullptr;
	delete aux;
}
void eliminarFinal() {
	if (primero) {
		Nodo* aux = primero;
		Nodo* pre = nullptr;
		while (aux->siguiente) {
			pre = aux;
			aux = aux->siguiente;
		}
		if (aux == primero) {
			primero = primero->siguiente;
			delete aux;
		}
		else {
			pre->siguiente = nullptr;
			delete aux;
		}
	}
	else {
		cout << "La lista esta vacia. \n";
	}

}
void buscarLista()
{
	int val;
	cout << "Ingrese el valor a Buscar: ";
	cin >> val;
	int aux1 = 0;
	Nodo* num = new Nodo(val, NULL);
	Nodo* tmp = this->primero;
	while (tmp) {
		if (tmp->valor == num->valor) {
			aux1++;
		}
		tmp = tmp->siguiente;
	}
	if (aux1 == 0) {
		cout << "\nEl elemento no existe\n";
	}
	else {
		Nodo* aux = primero;
		while (aux != NULL && aux->valor != val) {
			aux = aux->siguiente;
		}
		cout << "Existe el elemeto: " << aux->valor << " \n";
		cout << "La direccion del elemento buscado: " << aux << " \n";
	}
}
};