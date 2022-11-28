#pragma once
#include "Nodo.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#include "ValidarDatos.h"
#define FONDODERESERVA 0.0833
#define IESS 0.0945
using namespace std;
ValidarDatos obj;
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

	//void insertarDatos();
	int encontrarCola(){
		Nodo *tmp = this->primero;
		int datos = 0;
		while(tmp){
			datos++;
			tmp=tmp->siguiente;
		}
		return datos;
	}

void agregarDatosFinal()
{
	Nodo* nuevo = new Nodo();
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
void insertarDatos(){
		Nodo *nuevo = new Nodo();
		if (listaVacia()){
			nuevo->id = obj.validarEntero("\nIngrese su ID: ");
			nuevo->usuario =  obj.validarLetras("\nIngrese su nombre: ");
			nuevo->salario = obj.validarDoubles("\nIngrese su salario: ");
			nuevo->montoHorasSup = obj.validarDoubles("\nIngrese el monto por horas suplementaraias: ");
			nuevo->montoHorasExtr = obj.validarDoubles("\nIngrese el monto por horas extras: ");
			this->primero = nuevo;	
		}
		else{
			nuevo->id = obj.validarEntero("\nIngrese su ID: ");
			nuevo->usuario =  obj.validarLetras("\nIngrese su nombre: ");
			nuevo->salario = obj.validarDoubles("\nIngrese su salario: ");
			nuevo->montoHorasSup = obj.validarDoubles("\nIngrese el monto por horas suplementaraias: ");
			nuevo->montoHorasExtr = obj.validarDoubles("\nIngrese el monto por horas extras: ");
			//se asigna la direccion de memoria del nuevo nodo creado al actual
			//se enva la direccion de nuevo al actual
			this->actual->siguiente=nuevo;
		}
		//se manda el valor de nuevo
		this->actual=nuevo;
}
void mostrarLista(){
		Nodo *tmp=this->primero;
		if (tmp == NULL) // Si la lista doble esta vacia, si tmp apunta a NULL.
		{
		cout << "\nLista vacia." << endl;
		}else{
			cout<<"\nID||"<<setw(20)<<"Usuario||"<<setw(20)<<"Salario||"<<setw(20)<<"Monto por Horas Suplementarias||"
			<<setw(20)<<"Monto por horas extras||"<<setw(20)<<"Tasa ingreso IESS||"<<setw(20)<<"Fondo de Reserva||"
			<<setw(20)<<"Total Ingreso||"<<setw(20)<<"IESS||"<<setw(20)<<"Total egreso||"<<setw(20)<<"Total a Recibir"<<endl;
			while(tmp){
				cout<<tmp->id<<setw(20)<<tmp->usuario<<setw(15)<<tmp->salario
				<<setw(25)<<tmp->montoHorasSup<<setw(20)<<tmp->montoHorasExtr<<
				setw(25)<<tmp->tasaIngresoIESS<<setw(20)<<tmp->fondoReserva<<setw(20)
				<<tmp->totalIngreso<<setw(20)<<tmp->iess<<setw(20)<<tmp->totalEgreso<<
				setw(20)<<tmp->recibir<<endl;
				tmp = tmp->siguiente;
			}
		}
	}
void mostrarNodo(Nodo& tmp){
	
		cout<<"\nID||"<<setw(20)<<"Usuario||"<<setw(20)<<"Salario||"<<setw(20)<<"Monto por Horas Suplementarias||"
		<<setw(20)<<"Monto por horas extras||"<<setw(20)<<"Tasa ingreso IESS||"<<setw(20)<<"Fondo de Reserva||"
		<<setw(20)<<"Total Ingreso||"<<setw(20)<<"IESS||"<<setw(20)<<"Total egreso||"<<setw(20)<<"Total a Recibir"<<endl;
		fflush(stdin);
		cout<<tmp.getID()<<setw(20)<<tmp.getNombre()<<setw(15)<<tmp.getSalario()
		<<setw(25)<<tmp.getMontoHorasSup()<<setw(20)<<tmp.getMontoHorasExtr()<<
		setw(25)<<tmp.getTasaingresoIESS()<<setw(20)<<tmp.getFondoDeReserva()<<setw(20)
		<<tmp.getTotalIngreso()<<setw(20)<<tmp.getIESS()<<setw(20)<<tmp.getTotalEgreso()<<
		setw(20)<<tmp.getRecibir()<<endl;
}
void calcularRolDePagos(){
	Nodo *tmp=this->primero;
		if (tmp == NULL) // Si la lista doble esta vacia, si tmp apunta a NULL.
		{
		cout << "\nLista vacia." << endl;
		}else{
			while(tmp){
			tmp->tasaIngresoIESS = tmp->salario + tmp->montoHorasSup + tmp->montoHorasExtr;
			tmp->fondoReserva = tmp->tasaIngresoIESS * FONDODERESERVA;
			tmp->totalIngreso = tmp->tasaIngresoIESS + tmp->fondoReserva;
			tmp->iess = tmp->tasaIngresoIESS*IESS;
			tmp->totalEgreso = tmp->iess;
			tmp->recibir = tmp->totalIngreso - tmp->totalEgreso;
			almacenarDatos(*tmp);
			tmp = tmp->siguiente;
		}
		}
}
void almacenarDatos(Nodo& nodo){
	ofstream file;

	file.open("Usuarios.txt",ios::app);
	if(file.fail()){
		cout<<"Ocurrio un error\nNo se pudo abrir el archivo"<<endl;
	}else{
		file<<nodo.getID()<<","
		<<nodo.getNombre()<<","
		<<nodo.getSalario()<<","
		<<nodo.getMontoHorasSup()<<","
		<<nodo.getMontoHorasExtr()<<","
		<<nodo.getTasaingresoIESS()<<","
		<<nodo.getFondoDeReserva()<<","
		<<nodo.getTotalIngreso()<<","
		<<nodo.getIESS()<<","
		<<nodo.getTotalEgreso()<<","
		<<nodo.getRecibir()<<endl;
	}
	file.close();
}
void leerDatos(){
	char* token{};
	char aux[500]{};
	int i = 1;
	char matrizaux[12][20];
	std::string linea;
	ifstream file;
	Nodo *nuevo = new Nodo();
	file.open("Usuarios.txt",ios::in);
	if(file.fail()){
		cout<<"Ocurrio un error\nNo se pudo abrir el archivo"<<endl;
	}else{
		while(!file.eof()){
			getline(file,linea);
			fflush(stdin);
			strcpy(aux,linea.c_str());
			//pasamos de un string a un auxiliar char* ya que
			//strtok necesita un char* para hacer los tokens y no vale hacer linea.c_str()
			linea.erase(linea.begin(),linea.end());//borra todo lo que esta en el string linea
			token = strtok(aux,",");
			strcpy(matrizaux[0], token);
			token = strtok(NULL,",");
			while(token != NULL){
				strcpy(matrizaux[i],token);
				i++;
				token = strtok(NULL,",");
            }
			i=1;
			if (listaVacia()){
				nuevo->setID(atoi(matrizaux[0]));
				nuevo->setNombre(matrizaux[1]);
				nuevo->setSalario(atof(matrizaux[2]));
				nuevo->setMontoHorasSup(atof(matrizaux[3]));
				nuevo->setMontoHorasExtr(atof(matrizaux[4]));
				nuevo->setTasaingresoIESS(atof(matrizaux[5]));
				nuevo->setFondoDeReserva(atof(matrizaux[6]));
				nuevo->setTotalIngreso(atof(matrizaux[7]));
				nuevo->setIESS(atof(matrizaux[8]));
				nuevo->setTotalEgreso(atof(matrizaux[9]));
				nuevo->setRecibir(atof(matrizaux[10]));
				this->primero = nuevo;	
				//mostrarNodo(*primero);
			}
			else{
				nuevo->setID(atoi(matrizaux[0]));
				nuevo->setNombre(matrizaux[1]);
				nuevo->setSalario(atof(matrizaux[2]));
				nuevo->setMontoHorasSup(atof(matrizaux[3]));
				nuevo->setMontoHorasExtr(atof(matrizaux[4]));
				nuevo->setTasaingresoIESS(atof(matrizaux[5]));
				nuevo->setFondoDeReserva(atof(matrizaux[6]));
				nuevo->setTotalIngreso(atof(matrizaux[7]));
				nuevo->setIESS(atof(matrizaux[8]));
				nuevo->setTotalEgreso(atof(matrizaux[9]));
				nuevo->setRecibir(atof(matrizaux[10]));
				this->actual->siguiente=nuevo;
				//mostrarNodo(*actual);
			}
			//se manda el valor de nuevo
			this->actual=nuevo;
		}
	}
	file.close();
}
// void agregarInicio(int v)
// {
// 	Nodo* nuevo = new Nodo(v);
// 	if (listaVacia()) {
// 		primero = nuevo;
// 	}
// 	else {
// 		nuevo->siguiente = primero;
// 		primero = nuevo;
// 	}
// }
// void eliminarElemento(void)
// {
// 	int val;
// 	if (primero) {
// 		cout << "Ingrese el ID a eliminar: ";
// 		cin >> val;
// 		cout << "\n";
// 		Nodo* aux = primero;
// 		Nodo* pre = new Nodo(val);
// 		while (aux) {
// 			if (aux->valor == val && primero == aux) {
// 				eliminarInicio();
// 				break;
// 			}
// 			else if (aux->valor == val && aux->siguiente == nullptr) {
// 				eliminarFinal();
// 				break;
// 			}
// 			else if (aux->valor == val && aux->siguiente != nullptr) {
// 				pre->siguiente = aux->siguiente;
// 				aux->siguiente = nullptr;
// 				delete aux;
// 				break;
// 			}
// 			else {
// 				pre = aux;
// 				aux = aux->siguiente;
// 			}
// 		}
// 	}
// 	else {
// 		cout << "\nLista Vacia\n";
// 	}
// 	cout << "\n";
// }

// void eliminarInicio() {
// 	Nodo* aux = primero;
// 	primero = primero->siguiente;
// 	aux->siguiente = nullptr;
// 	delete aux;
// }
// void eliminarFinal() {
// 	if (primero) {
// 		Nodo* aux = primero;
// 		Nodo* pre = nullptr;
// 		while (aux->siguiente) {
// 			pre = aux;
// 			aux = aux->siguiente;
// 		}
// 		if (aux == primero) {
// 			primero = primero->siguiente;
// 			delete aux;
// 		}
// 		else {
// 			pre->siguiente = nullptr;
// 			delete aux;
// 		}
// 	}
// 	else {
// 		cout << "La lista esta vacia. \n";
// 	}

// }
// void buscarLista()
// {
// 	int val;
// 	cout << "Ingrese el valor a Buscar: ";
// 	cin >> val;
// 	int aux1 = 0;
// 	Nodo* num = new Nodo(val, NULL);
// 	Nodo* tmp = this->primero;
// 	while (tmp) {
// 		if (tmp->valor == num->valor) {
// 			aux1++;
// 		}
// 		tmp = tmp->siguiente;
// 	}
// 	if (aux1 == 0) {
// 		cout << "\nEl elemento no existe\n";
// 	}
// 	else {
// 		Nodo* aux = primero;
// 		while (aux != NULL && aux->valor != val) {
// 			aux = aux->siguiente;
// 		}
// 		cout << "Existe el elemeto: " << aux->valor << " \n";
// 		cout << "La direccion del elemento buscado: " << aux << " \n";
// 	}
// }
};