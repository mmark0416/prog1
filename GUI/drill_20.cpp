#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>

int main(){
    int size = 10;
    int array10[10] {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vec10 {0,1,2,3,4,5,6,7,8,9};
    std::list<int> lis10 {0,1,2,3,4,5,6,7,8,9};

    for(auto& l: lis10)
        std::cout << l << ", ";
    std::cout << '\n';

    /*for(int i=0; i<size; i++){
        array10[i] = i;
        vec10[i] = i;
       // lis10[i] = i;
    }

    std::array<int, 10> array10_1;
    std::copy(array10,array10+10,array10_1.begin());
    std::vector<int> vec10_1;
    std::copy(array10, array10+10,vec10_1.begin());
    std::list<int> lis10_1;
    std::copy(array10, array10+10,lis10_1.begin());
    
    for (auto const &i: vec10) {
        std::cout << i << std::endl;
    }
*/}