#include <iostream>

using namespace std;

class S{
    int i;
public:
    S(int ii): i(ii) {}
    const int get() const {return i;}
};

int main(){
    const S szia{5};
    cout << szia.get() << endl; 

    return 0;
}