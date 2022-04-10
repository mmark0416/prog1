#include <iostream>
#include <stdexcept>

int ga[10] = {1,2,4,8,16,32,64,128,256,512};

void f(int ar[], int n){

    int la[10] = {};
    for(int i=0; i<n; i++){
        la[i] = ar[i];
        std::cout << la[i] << " ";
    }
    std::cout << '\n';
    
    int* p = new int[n];
    for(int i=0; i<n; i++){
        p[i] = ar[i];
        std::cout << p[i] << " ";
    }
    std::cout << '\n';
    delete[] p;
}

int main(){
    std::cout << "binary array:\n";
    f(ga,10);

    int aa[10];
    int x = 1, y = 1;

    for(int i=0; i<10; i++){
        aa[i] = x;
        y++;
        x = x*(y);
    }
    std::cout << "factorial array:\n";
    f(aa,10);

    return 0;
}