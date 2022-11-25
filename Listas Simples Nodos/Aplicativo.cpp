#include <iostream>
#include "Lista.h"
using namespace std;
int main(int argc, char** argv) {
	Lista lst;
	for(int i{0};i<2;++i){
		lst.insertar();
	}
	cout<<"menor es: "<<lst.encontrarMenor()<<endl;
	//lst.agregarInicio;
	// lst.agregarInicio(5);
	// lst.agregarInicio(15);
	// lst.agregarInicio(25);
	// lst.agregarInicio(35);
	// lst.agregarInicio(45);
	// lst.agregarInicio(55);
	// lst.agregarInicio(65);
	// lst.agregarInicio(57);
	// lst.agregarInicio(85);
	// lst.agregarInicio(95);
//cout<<lst.encontrarMenor();
	cout<<"mcd: "<<lst.maximoComunDivisor()<<endl;
	//lst.mostrarLista();
	//cout<<lst.minimoComunMultiplo();
	// cout<<endl;
	// lst.agregarInicio(100);
	// lst.mostrarLista();
	//cout<<"\n"<<lst.encontrarCola();
	return 0;
}