#include <iostream>
#include <vector>

std::ostream& print_array(std::ostream& os, int* a, int n){
    for(int i=0; i<n; i++)
        os << a[i] << ", ";
    os << '\n';
    return os;
}

int main(){
    int i = 7;
    int* p1 = &i;
    std::cout << "pointer: " << p1 << "\n points to: " << *p1 << '\n';

    int* p2 = new int[7];
    int x = 1;
    for(int i=0; i<7; i++){
        p2[i] = x;
        x += x;
    }
    std::cout << "p2 pointer: " << p2 << '\n';
    print_array(std::cout, p2, 7);
    
    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    std::cout << "pointer: " << p1 << " points to: " << *p1 << '\n';
    std::cout << "pointer: " << p2 << " points to: " << *p2 << '\n';
    delete[] p2;

    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p2 = new int[10];
    for(int i=0; i<10; i++){
        p2[i] = p1[i];
    }
    print_array(std::cout, p2, 10);
    delete[] p1;
    delete[] p2;

    std::vector<int> v1 {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    std::vector<int> v2(10);
    v2 = v1;
    for(int v: v2){
        std::cout << v << ", ";
    }
    std::cout << '\n';
    return 0;
}