#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <complex>
#include <numeric>
#include "Matrix.h"
#include "MatrixIO.h"

using Numeric_lib::Matrix;

void my_sqrt(){
    bool bo = true;
    while(bo){
        int value;
        std::cin >> value;
        if(!value)
            break;
        else if(value < 0)
            std::cout << "No square root\n";
        else
            std::cout << "Square root("<< value << ") = " << sqrt(value) << '\n';
    }
}

int main(){
    //---------1. feladat----------
    std::cout << "SIZEOF:\n"
              << "\tChar size:\t" << sizeof(char) << '\n'
              << "\tShort size:\t" << sizeof(short) << '\n'
              << "\tInt size:\t" << sizeof(int) << '\n'
              << "\tLong size:\t" << sizeof(long) << '\n'
              << "\tFloat size:\t" << sizeof(float) << '\n'
              << "\tDouble size:\t" << sizeof(double) << '\n'
              << "\tInt* size:\t" << sizeof(int*) << '\n'
              << "\tDouble* size:\t" << sizeof(double*) << '\n';
    
    //---------2. feladat----------
    Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);
    std::cout << "SIZE OF MATRIX:\n"
              << "\tMatrix<int> a(10)\t\t" << sizeof(a) << '\n'
              << "\tMatrix<int> b(100)\t\t" << sizeof(b) << '\n'
              << "\tMatrix<double> c(10)\t\t" << sizeof(c) << '\n'
              << "\tMatrix<int,2> d(10,10)\t\t" << sizeof(d) << '\n'
              << "\tMatrix<int,3> e(10,10,10)\t" << sizeof(e) << '\n';

    //---------3. feladat----------
    std::cout << "NUMBER OF ELEMENTS:\n"
              << "\tMatrix<int> a(10)\t\t" << a.size() << '\n'
              << "\tMatrix<int> b(100)\t\t" << b.size() << '\n'
              << "\tMatrix<double> c(10)\t\t" << c.size() << '\n'
              << "\tMatrix<int,2> d(10,10)\t\t" << d.size() << '\n'
              << "\tMatrix<int,3> e(10,10,10)\t" << e.size() << '\n'; 

    //---------3. feladat----------
    std::cout << "Enter some ints for square-rooting:\n";
    my_sqrt();
 
    return 0;
}
