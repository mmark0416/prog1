#include <iostream>
#include <vector>
using namespace std;

ostream& print_array10(ostream& os, int* a){
    for(int i=0; i<10; ++i)
        os << a[i] << '\n';
    return os;
}

ostream& print_array11(ostream& os, int*a){
    for(int i=0; i<11; ++i){
        os << a[i] << '\n';
    }
    return os;
}

ostream& print_array(ostream& os, int* a, int n){
    for(int i=0; i<n; ++i){
        os << a[i] << '\n';
    }
}

int main(){

    int* array10 = new int[10];

    for(int i=0; i < 10; i++){
        cout << array10[i];
    }
    print_array10(cout, array10);
    delete[] array10;

    int x = 100;
    int* array10a = new int[10];
    for(int i=0; i<10; ++i){
        array10a[i] = x;
        x++;
    }
    print_array10(cout, array10a);

    int y = 100;
    int* array11 = new int[11];
    for(int i=0; i<11; ++i){
        array11[i] = y;
        y++;
    }
    print_array11(cout, array11);

    return 0;
}