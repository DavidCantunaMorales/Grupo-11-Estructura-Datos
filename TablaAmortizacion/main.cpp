#include <iostream>
#include <iomanip>
#include <math.h>

double calcularTabla(const double saldo, 
                     const double pago, 
                     const double interes, 
                     const int    meses, 
                           int    cnt     ) {
	
    double periodosInteres = saldo * (interes/meses);
    double amortizacion = pago - periodosInteres;
    double balance = saldo - amortizacion;

    std::cout << std::fixed
              << std::setprecision(2)
              << std::setw(5)
              << "19 / " << cnt << " /2021"  
              << std::setw(20)
              << pago 
              << std::setw(18)
              << periodosInteres
              << std::setw(20)
              << amortizacion
              << std::setw(25)
              << balance
              << '\n';

    return balance;
}

int main () {

    std::cout << std::setw(5) << "\nMeses#" 
	          << std::setw(18) << "Pago" 
			  << std::setw(20) << "Interes" 
			  << std::setw(20) << "Amortizacion" 
			  << std::setw(20) << "Saldo"
			  << '\n';

    double saldo = 3000000;
    const double interes = 0.015;
    const int meses = 4;
    const double pago = saldo*((interes/meses)/(1-(pow((1+(interes/meses)),-meses))));
    //std::cout << pago;
    
    for(int cnt = 1; saldo > 0; cnt++) {
        saldo = calcularTabla(saldo, pago, interes , meses, cnt);
		if(cnt == 12){
			cnt = 0;
		} 
    }
    
    return 0;
}

