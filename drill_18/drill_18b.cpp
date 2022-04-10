#include <iostream>
#include <vector>

std::vector<int> gv = {1,2,4,8,16,32,64,128,256,512};

void f(std::vector<int> v){
    std::vector<int> lv(gv.size());
    lv = v;
    for(int v: lv){
        std::cout << v << ' ';
    }
    std::cout << '\n';

    std::vector<int> lv2 = v;
    for(auto a: lv2){
        std::cout << a << ' ';
    }
    std::cout << '\n';
}

int fact(int n){
    return n > 1 ? n * fact(n-1) : 1;
}

int main(){

    f(gv);
    
    std::vector<int> vv(10);
    for(int i=0; i<vv.size(); i++){
        vv[i] = fact(i+1);
    }
    
    f(vv);

    return 0;
}