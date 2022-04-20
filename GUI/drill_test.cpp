#include <iostream>
#include <vector>
#include <string>
#include <list>

int main()
try{
    
    list<int>::iterator p = 

}catch(std::exception& e){
    std::cerr << "exception: " << e.what() << '\n';
    return 1;
}catch(...){
    std::cerr << "Unknow exception\n";        
}