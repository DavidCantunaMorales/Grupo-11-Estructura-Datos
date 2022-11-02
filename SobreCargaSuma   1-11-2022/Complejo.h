#include <iostream>


class Complejo{
	public:
		Complejo(){
		}
		Complejo(int r, int i);
		int getReal();
		void setReal(int r);
		int getImag();
		void setImag(int i);
		Complejo operator+(Complejo c2);
	private:
		int real, imag;		
};
