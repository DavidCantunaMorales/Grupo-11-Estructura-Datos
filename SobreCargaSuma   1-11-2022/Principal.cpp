#include <iostream>

#include "Complejo.h"

using namespace std;


int main(int argc, char** argv) {
	Complejo compA(8,5), compB(5,2), compC;
	compC = compA + compB;
	cout << compC.getImag() << endl;
	
	return 0;
}
