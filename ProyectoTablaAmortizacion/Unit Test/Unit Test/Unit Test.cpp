
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double calcularPago(double, double, int );
void tablaAmortizacion(double, double , double, int , int , int, int);
void imprimirInformacion(double, double, int, int, int, int);

int main(){

    double saldo = 32000;
    double interes = 0.15;
    int mes = 4;
    int d = 6;
    int m = 11;
    int a = 2022;


    const double pago =  calcularPago(saldo, interes, mes);
    cout << pago << endl;
    cout << endl;

    tablaAmortizacion(saldo, pago, interes, mes, d, m, a);
    cout << endl;

    imprimirInformacion(saldo, interes, mes, d, m, a);

    
    
}


double calcularPago(double saldo, double interes, int mes){
    return saldo * ((interes / mes) / (1 - (pow((1 + (interes / mes)), -mes))));
}

void tablaAmortizacion(double saldo, double pago, double interes, int meses, int d, int m, int a) {

    std::cout << "Tabla de Amortizacion" << std::endl;
    cout << endl;
    std::cout << std::setw(5) << "\nMeses:"
        << std::setw(28) << "Pago:"
        << std::setw(28) << "Interes:"
        << std::setw(28) << "Amortizacion:"
        << std::setw(20) << "Saldo:"
        << '\n';

    for (int i = 0; i < meses; i++) {

        double periodosInteres = saldo * (interes / meses);
        double amortizacion = pago - periodosInteres;
        double balance = saldo - amortizacion;

        saldo = balance;

        int contador = 0;

        contador++;

        if (m++ > 11) {
            contador = 1;
            m = contador;
            a++;
        }

        std::cout << std::fixed
            << std::setprecision(2)
            << std::setw(5)
            << d << " - " << m << " - " << a
            << std::setw(20)
            << pago
            << std::setw(25)
            << periodosInteres
            << std::setw(25)
            << amortizacion
            << std::setw(25)
            << balance
            << '\n';
    }
}


void imprimirInformacion(double saldo, double interes, int meses, int d, int m, int a) {
    std::cout << "Informacion Ingresada: " << std::endl;
    std::cout << std::endl;
    std::cout << "El prestamo es de: " << saldo << std::endl;
    std::cout << "El interes es de: " << (interes * 100) << " % " << std::endl;
    std::cout << "En un tiempo de : " << meses << " meses." << std::endl;
    std::cout << "Realizado el: " << d << " / " << m << " / " << a << std::endl;
}