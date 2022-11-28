#pragma once
#include <string.h>
#include <conio.h>
class Nodo{
	private:
		Nodo *siguiente;
		int id{};
		std::string usuario{};
		double salario{};
		float montoHorasSup{};
		float montoHorasExtr{};
		float tasaIngresoIESS{};
		float fondoReserva{};
		float totalIngreso{};
		float iess{};
		float totalEgreso{};
		float recibir{};
	public:
		Nodo(Nodo *sig=nullptr){
			this->siguiente=sig;
		}
		int getID(){
			return this->id;
		}
		std::string getNombre(){
			return this->usuario;
		}
		double getSalario(){
			return this->salario;
		}
		float getMontoHorasSup(){
			return this->montoHorasSup;
		}
		float getMontoHorasExtr(){
			return this->montoHorasExtr;
		}
		float getTasaingresoIESS(){
			return this->tasaIngresoIESS;
		}
		float getFondoDeReserva(){
			return this->fondoReserva;
		}
		float getTotalIngreso(){
			return this->totalIngreso;
		}
		float getIESS(){
			return this->iess;
		}
		float getTotalEgreso(){
			return this->totalEgreso;
		}
		float getRecibir(){
			return this->recibir;
		}
		//********
		void setID(int oid){
			this->id = oid;
		}
		void setNombre(std::string ousuario){
			this->usuario = ousuario;
		}
		void setSalario(float osalario){
			this->salario = osalario;
		}
		void setMontoHorasSup(float omonto){
			this->montoHorasSup = omonto;
		}
		void setMontoHorasExtr(float montoextra){
			this->montoHorasExtr = montoextra;
		}
		void setTasaingresoIESS(float tasaiess){
			this->tasaIngresoIESS = tasaiess;
		}
		void setFondoDeReserva(float reserva){
			this->fondoReserva = reserva;
		}
		void setTotalIngreso(float totalin){
			this->totalIngreso = totalin;
		}
		void setIESS(float ies){
			this->iess = ies;
		}
		void setTotalEgreso(float totale){
			this->totalEgreso = totale;
		}
		void setRecibir(float re){
			this->recibir = re;
		}
	friend class Lista;
};