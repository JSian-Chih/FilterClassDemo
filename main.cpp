
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "DesignFilter_class.h"
#include "CPFilter.h"

#define _USE_MATH_DEFINES
#include "math.h"


double time = 0.0;
double uoutk = 0.0;
double uink = 0.0;

CPFilter TestF(30.0,0.001);

int main(){

    
    ofstream dataFile;
    dataFile.open("dataFile.txt", ofstream::app);
    fstream file("dataFile.txt", ios::out);

    while(time < 100){
        time += 0.001;
        uink = 1;
        TestF.output(uink);
        dataFile << TestF.dx_out(0) << " " << uink << endl;
    }

    dataFile.close();

    system("pause");
    return 0;

}






