#include <iostream>
#include <cstdlib>
using namespace std;

#define _USE_MATH_DEFINES
#include "math.h"

#include "DesignFilter_class.h"


DesignFilter::DesignFilter(int N, double f, double t){
    this -> flag = N;
    this -> fc1 = f;
    this -> fc2 = f;
    this -> dT = t;
    this -> uoutk = 0.0;
    this -> uoutk_1 = 0.0;
    this -> uoutk_2 = 0.0;
    this -> uink_1 = 0.0;
    this -> uink_2 = 0.0;
}

DesignFilter::DesignFilter(int N, double f1, double f2, double t){
    this -> flag = N;
    this -> fc1 = f1;
    this -> fc2 = f2;
    this -> dT = t;
    this -> uoutk = 0.0;
    this -> uoutk_1 = 0.0;
    this -> uoutk_2 = 0.0;
    this -> uink_1 = 0.0;
    this -> uink_2 = 0.0;
}

double DesignFilter::output(double uink){

    double A0 = 0.0;
    double A1 = 0.0;
    double A2 = 0.0;
    double B0 = 0.0;
    double B1 = 0.0;
    double B2 = 0.0;

    switch (flag){
    case 1: //1stLPF
        B2 = 1.0;
        A1 = 1.0/(2.0*M_PI*fc1);
        A2 = 1.0;
        break;
    case 2: //1stHPF
        B1 = 1.0/(2.0*M_PI*fc1);
        A1 = 1.0/(2.0*M_PI*fc1);
        A2 = 1.0;
        break;
    case 3: //2ndLPF
        B2 = 4.0*pow(M_PI,2.0)*fc1*fc2;
        A0 = 1.0;
        A1 = 2.0*M_PI*(fc1+fc2);
        A2 = B2;
        break;
    case 4: //2ndHPF
        B2 = 1.0;
        A0 = 1.0;
        A1 = 2*M_PI*(fc1+fc2);
        A2 = 4.0*pow(M_PI,2.0)*fc1*fc2;
        break;
    case 5: //APD
        B1 = 1.0;
        A1 = 1.0 / (M_PI*fc1);
        A2 = 1.0;
        break;
    default:
        break;
    }

    double A0D = A0*4.0/pow(dT,2.0)+A1*2.0/dT+A2;
    double A1D = -2.0*A0*4.0/pow(dT,2.0)+2.0*A2;
    double A2D = A0*4.0/pow(dT,2.0)-A1*2.0/dT+A2;
    double B0D = B0*4.0/pow(dT,2.0)+B1*2.0/dT+B2;
    double B1D = -2.0*B0*4.0/pow(dT,2.0)+2.0*B2;
    double B2D = B0*4.0/pow(dT,2.0)-B1*2.0/dT+B2;
    this -> uoutk = 1.0/A0D * (-A1D*uoutk_1 -A2D*uoutk_2 + B0D*uink + B1D*uink_1 +B2D*uink_2);

    this -> uink_2 = uink_1;
    this -> uoutk_2 = uoutk_1;
    this -> uink_1 = uink;
    this -> uoutk_1 = uoutk;

    return uoutk;
}

