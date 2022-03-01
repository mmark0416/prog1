#include <iostream>
#include <vector>
//1. feladat-------
class B1{
public:
    virtual void vf(){std::cout << "B1::vf()\n";}
    void f(){std::cout << "B1::vf()\n";}
    //5. feladat-------
    virtual void pvf() {}
};
//2. feladat-----------
class D1 : public B1{
public:
    void vf() override {std::cout << "D1::vf()\n";}
    void f() {} //Ha ezt ide írjuk felülírja a B1-től örökölt f függvényt
};
//4. feladat--------

int main(){
    
    //1.feladat--------
    std::cout << "----1 feladat:----\n";
    B1 b;
    b.vf();
    b.f();
    //2. feladat--------
    std::cout << "----2 feladat:----\n";
    D1 d;
    d.vf();
    d.f();
    //3. feladat--------
    std::cout << "----3 feladat:----\n";
    B1& b1_ref {d};
    b1_ref.vf();
    b1_ref.f();
    return 0;
}