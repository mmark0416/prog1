#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <algorithm>

void print(std::vector<double> ve){
    for(auto& v: ve){
        std::cout << '\t' << v << '\n';
    } 
}

int main()
try{
    //-----------1. feladat------------
    std::vector<double> vd;
    const std::string iname {"drill_21c_text.txt"}; 
    std::ifstream ifs {iname};
    if(!ifs) throw std::runtime_error("Could not read from file " + iname);

    for(double d; ifs >> d;){
        vd.push_back(d);
    }

    //-----------2. feladat------------
    std::cout << "dv value:\n";
    print(vd);
 
    //-----------3. feladat------------
    std::vector<int> vi(vd.size());
    std::copy(vd.begin(),vd.end(),vi.begin());

    //-----------4. feladat------------
    std::cout << "dv and iv value:\n";
    for(int i=0; i<vi.size();i++){
        std::cout << "\t" << vd[i] << ", " << vi[i] << '\n';
    }

    //-----------5. feladat------------
    double sumd = std::accumulate(vd.begin(),vd.end(),0.0);
    std::cout << "Sum of dv:\n\t" << sumd << '\n';
/*    sumd = 0;
    sumi = 0;
    for(int i=0; i<vd.size(); i++){
        sumd += vd[i];
        sumi += vi[i];
    }
*/

    //-----------6. feladat------------
    double diff_sum =
        std::inner_product(vd.begin(), vd.end(),
                vi.begin(),
                0.0,
                std::plus<double>(),
                std::minus<double>());
    std::cout << "Different between dv and di:\n\t" << diff_sum << '\n';

    //-----------7. feladat------------
    std::reverse(vd.begin(),vd.end());
    std::cout << "dv reverse:\n";
    print(vd);
    return 0;
}catch(std::exception& e){
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;   
}