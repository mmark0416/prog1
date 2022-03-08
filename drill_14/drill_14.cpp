#include <iostream>
#include <string>
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
//6. feladat--------
class D2 : public D1{
public:
    void pvf() override {}
};
//7. feladat--------
class B2{
public:
    virtual void pvf() {}
};
class D21 : public B2{
public:
    std::string s = "valami";
    void pvf() override {std::cout << s << "\n";}
};
class D22 : public B2{
    int i = 11;
    void pvf() override {std::cout << i << "\n";}
};
void f(B2& b2){
    b2.pvf();
}
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
    //6. feladat--------
    std::cout << "----4 feladat:----\n";
    D2 d2;
    d2.f();
    d2.vf();
    d2.pvf();
    //7. feladat--------
    std::cout << "----7 feladat:----\n";
    D21 d21;
    D22 d22;
    f(d21);
    f(d22);
    return 0;
}