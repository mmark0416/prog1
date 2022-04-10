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
    return os;
}
ostream& print_vector(ostream& os, vector<int> v){
    for(int i=0; i< v.size(); i++)
        os << v[i] << '\n';
    return os;
}
int main(){
    cout << "array10:\n";
    int* array10 = new int[10];
    for(int i=0; i < 10; i++){
        cout << array10[i];
    }
    print_array10(cout, array10);
    delete[] array10;

    cout << "array10_1:\n";
    int x = 100;
    int* array10a = new int[10];
    for(int i=0; i<10; ++i){
        array10a[i] = x;
        x++;
    }
    print_array10(cout, array10a);
    delete[] array10;

    cout << "array11:\n";
    x = 100;
    int* array11 = new int[11];
    for(int i=0; i<11; ++i){
        array11[i] = x;
        x++;
    }
    print_array11(cout, array11);
    delete[] array11;

    cout << "array20:\n";
    int* array20 = new int[20];
    x = 100;
    for(int i=0; i<20; ++i)
    {
        array20[i] = x;
        x++;
    }
    print_array(cout, array20, 20);
    delete[] array20;

    cout << "vector10:\n";
    vector<int> v10(10);
    x = 100;
    for(int& v : v10){
        v = x;
        x++;
    }
    print_vector(cout, v10);

    cout << "vector11:\n";
    vector<int> v11(11);
     x = 100;
    for(int& v : v11){
        v = x;
        x++;
    }
    print_vector(cout, v11);

    cout << "vector20:\n";
    vector<int> v20(20);
     x = 100;
    for(int& v : v20){
        v = x;
        x++;
    }
    print_vector(cout, v20);

    return 0;
}