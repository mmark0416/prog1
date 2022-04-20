#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <array>
#include <algorithm>


template<typename C>
void print(const C& c, const std::string& s = ""){
    std::cout << s << '\t';
    for(int x: c){
        std::cout << x << " ";
    }
    std::cout << '\n';
}

template<typename C>
void value_increaser(C &c, int in){
    for(auto& v: c){
        v += in;
    }
}

template<typename Iter1, typename Iter2>
Iter2 dr_copy(Iter1 f1, Iter1 e1, Iter2 f2){
    for(Iter1 p=f1; p != e1; p++){
        *f2++ = *p;
    }
    return f2;
}

int main(){

    constexpr int size = 10;

    int array10[10] {0,1,2,3,4,5,6,7,8,9};
    std::vector<int> vec10(10);
    std::copy(array10, array10+size, vec10.begin());

    std::list<int> lis10(10);
    std::copy(array10, array10+size, lis10.begin());

    std::array<int, 10> array10_1;
    std::copy(array10,array10+size,array10_1.begin());
    print(array10_1, "Array:");

    std::vector<int> vec10_1(size);
    std::copy(array10, array10+size, vec10_1.begin());
    print(vec10_1, "Vector:");

    std::list<int> lis10_1(10);
    std::copy(array10, array10+size, lis10_1.begin());
    print(lis10_1, "List:");

    value_increaser(array10_1, 2);
    print(array10_1, "Array increaser:");

    value_increaser(vec10_1, 3);
    print(vec10_1, "Vector increaser:");

    value_increaser(lis10_1, 5);
    print(lis10_1, "List increaser:");

    dr_copy(array10_1.begin(),array10_1.end(),vec10_1.begin());
    dr_copy(lis10_1.begin(), lis10_1.end(),array10_1.begin());
    print(array10_1, "Array dr_copy:");
    print(vec10_1, "Vector dr_copy:");
    print(lis10_1, "List dr_copy:");

    std::vector<int>::iterator vit;
    vit = std::find(vec10_1.begin(), vec10_1.end(), 3);   
    if (vit != vec10_1.end())
        for(int i=0; i<size; i++){
            if(vec10_1[i] == *vit){
                std::cout << "In vector found at: " << i << '\n';
            }
        }
    else
        std::cout << "In vector not found..\n";

    std::list<int>::iterator lis;
    lis = std::find(lis10_1.begin(),lis10_1.end(),12);
    if (lis != lis10_1.end()){
        std::cout << "In list found at: " << std::distance(lis10_1.begin(), lis) << '\n';
    }
    else
        std::cout << "In list not found..\n";
    return 0;
}