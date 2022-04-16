#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>
#include <map>
#include <numeric>

template<typename C, typename D>
void print(const std::map<C,D>& ms, std::string s){
    std::cout << s << '\n';
    if(ms.size() == 0) std::cout << "\tEmpty\n";
    else
        for(auto& m: ms){
            std::cout << '\t' << m.first << " => " << m.second << '\n';
        }
    std::cout << '\n';
}
//----------5. feladat-----------
void read_to_msi(std::map<std::string,int>& ms){
    int a;
    std::string b;
    while(ms.size()<10){
        std::cout << '\t';
        std::cin >> b >> a;
        ms.insert(std::make_pair(b,a));
    }
}
int main()
try{
    //----------1-2. feladat-----------
    std::map<std::string,int> msi;
    msi["Bac_Ilus"] = 33;
    msi["Dill_Emma"] = 11;
    msi["Feles_Elek"] = 5;
    msi["Major_Anna"] = 66;
    msi["Virra_Dora"] = 41;
    msi["Pofa_Zoltan"] = 29;
    msi["Tank_Aranka"] = 23;
    msi["Rabsz_Olga"] = 14;
    msi["Hu_Zora"] = 52;
    msi["Hugyo_Zoltan"] = 32;

    //----------3. feladat-----------
    print(msi, "3. Insert 10 pairs into msi:");

    //----------4. feladat-----------
    msi.erase(msi.begin(),msi.end());
    print(msi, "3. Erase the pairs from msi:");

    //----------6. feladat-----------
    std::cout << "Read 10 string int pairs:\n"; 
    read_to_msi(msi);

    //----------7. feladat-----------
    print(msi,"7. Msi from cin:");

    //----------8. feladat-----------
    int total = std::accumulate(msi.begin(),msi.end(),0,
                [](int sum, const std::pair<std::string, int>& p)
                {return sum += p.second;});
/*     total = 0;
    for(const auto& v: msi){
        total += v.second;
    }
*/
    std::cout << "8. Msi int value sum:\n" << total << '\n';

    //----------9-10. feladat-----------
    std::map<int,std::string> mis;
    for(auto& m: msi){
        mis[m.second] = m.first;
    }

    //----------11. feladat-----------
    print(mis, "11. Print mis:");

    return 0;
}catch(std::exception& e){
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}catch(...){
    std::cerr << "Unknown exception\n";
    return 2;
}