#include <iostream>
#include <iomanip> //setw-hez
#include <complex>
#include <numeric> //accumulate
#include "Matrix.h"
#include "MatrixIO.h"

using Numeric_lib::Matrix;

void my_sqrt(){
    for(int i=0; i<3; i++){
        int value;
        std::cin >> value;
        if(value < 0)
            std::cout << "No square root\n";
        else
            std::cout << "\t" << "Square root("<< value << ") = " << sqrt(value) << '\n';
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

    //---------4. feladat----------
    std::cout << "Enter some ints for square-rooting:\n";
    my_sqrt();

    //---------5. feladat----------
    std::cout << "Enter 10 floats for the Matrix:\n\t";
    const int entries = 10;
    Matrix<double> mx(entries);
    for(int i=0; i<entries; i++)
        std::cin >> mx[i];
    std::cout << mx << '\n';

    //---------6. feladat----------
    std::cout << "Enter the dimensions for the Matrix:\n\t";
    int m, n;
    std::cin >> m >> n;
    std::cout << '\n';

    Matrix<double,2> mult_m(m,n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mult_m(i,j) = i == 0 || j == 0 ? i + j : i * j;

    //std::cout << mult_m << '\n';
    for (int i = 0; i < mult_m.dim1(); ++i) {
        for (int j = 0; j < mult_m.dim2(); ++j)
            std::cout << std::setw(5) << mult_m(i,j);
        std::cout << '\n';
    }

    //---------7. feladat----------
    std::cout << "Enter 10 complex numbers:\n\t";
    Matrix<std::complex<double>> mxc (10);
    for(int i=0; i<mxc.size();i++){
        std::cin >> mxc[i];
    }

    std::cout << "Total: "
              << std::accumulate(mxc.data(),mxc.data() + mxc.size(),
                            std::complex<double>{})
              << '\n';

    //---------7. feladat----------
    std::cout << "Enter 6 ints for 2*3 Matrix:\n\t";    
    Matrix<int,2> mm(2,3);
    for(int i=0; i<mm.dim1(); i++)
        for(int j=0; j< mm.dim2(); j++)
            std::cin >> mm[i][j];
    for(int i=0; i<mm.dim1(); i++){
        for(int j=0; j< mm.dim2(); j++)
            std::cout << std::setw(5) << mm[i][j];
        std::cout << '\n';
    }
    return 0;
}
