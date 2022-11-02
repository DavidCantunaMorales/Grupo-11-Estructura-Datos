#include <iostream>
#include "Duo.h"
using namespace std;
int main(int argc, char** argv){

    Duo A(3,4),B(6,9),C;
    cout<<"A = ("<< A.getNum1() <<","<<A.getNum2()<<")\n";
    cout<<"B = ("<< B.getNum1() <<","<<B.getNum2()<<")\n";
    std::cout<<"<<<<<<<<<<<<<<<>>>>>>>>>>>>\n";
    C = A - B;
    cout<<"A = ("<< A.getNum1() <<","<<A.getNum2()<<")\n";
    cout<<"B = ("<< B.getNum1() <<","<<B.getNum2()<<")\n";
    cout<<"C = ("<< C.getNum1() <<","<<C.getNum2()<<")\n";
    return 0;
}