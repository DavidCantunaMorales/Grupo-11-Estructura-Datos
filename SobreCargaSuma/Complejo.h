#include <iostream>
#include <string.h>
using namespace std;
class Complejo{
	public:
		Complejo(){};
		Complejo(int r, int i);
		int getReal();
		void setReal(int r);
		int getImag();
		void setImag(int i);
		Complejo operator+(Complejo c2);
		Complejo operator+(int num1);
		Complejo operator+(double num2);
		Complejo operator+(char* num3);

	private:
		int real, imag;		
};
