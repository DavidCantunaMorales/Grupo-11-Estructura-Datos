#include <iostream>
#include <iomanip>

double generarTablaAmortizacion(const double deudaInicial, const double tasaInteres, const int periodosPago, int cnt){
	const double periodoInteres = (deudaInicial * tasaInteres)/periodosPago;
	const double amortizacion = deudaInicial/periodosPago;
	const double pago = periodoInteres + amortizacion;
	const double deudaFinal = (deudaInicial + periodoInteres) - pago;
	
    std::cout << std::fixed
              << std::setprecision(2)
              << std::setw(5)
              << cnt
              << std::setw(18)
              << deudaInicial
              << std::setw(20)
              << periodoInteres 
              << std::setw(20)
              << amortizacion
              << std::setw(20)
              << pago
              << std::setw(25)
              << deudaFinal
              << '\n';
              
	return deudaFinal;
}

int main(){
    std::cout << std::setw(5) << "\nMeses#" 
			  << std::setw(20) << "Deuda Inicial" 
			  << std::setw(20) << "Intereses" 
			  << std::setw(20) << "Amortizacion" 
			  << std::setw(18) << "Pagos"
			  << std::setw(25) << "Deuda Final"
			  << '\n';
    double di = 100;
    const double ti = .24;
    const int pd = 12;


    for(int cnt = 1; cnt <= pd; cnt++) {
        di = generarTablaAmortizacion(di, ti, pd, cnt); 
    }
    
	return 0;
}

