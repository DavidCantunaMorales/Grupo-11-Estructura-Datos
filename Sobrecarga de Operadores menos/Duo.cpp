#include <iostream>
#include<stdlib.h>
#include "Duo.h"
#include <conio.h>
#include <stdio.h>

//Duo() : num1(0), num2(0){}
Duo::Duo(const double num1, const double num2){
        this->num1 = num1;
        this->num2 = num2;
}

Duo::Duo(const Duo &d){
    *this = d;
}
Duo Duo::operator -(Duo &d){
    this->num1 -= d.num1;
    this->num2 -= d.num2;
    return *this;
}

double Duo::getNum1(){
    return this->num1;
}

double Duo::getNum2(){
    return this->num2;
}