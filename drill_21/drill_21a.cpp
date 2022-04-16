#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

struct Item{
    std::string name;
    int iid;
    double value;
};

std::istream& operator>>(std::istream& is, Item& iii){
    std::string ss;
    int iin;
    double doub;
    is >> ss >> iin >> doub;
    Item iit {ss, iin, doub};
    iii = iit;
    return is;

}

struct Cmp_by_dec_val {
    bool operator()(const Item& a, const Item& b)
    {
        return a.value > b.value;
    }
};
template<typename C>
void print(C& vecit, std::string s =' '){
    std::cout << s << '\n';
    for(auto& v: vecit){
        std::cout << v.name << "\t" << v.iid << "\t" << v.value << "\n";
    }
    std::cout << '\n';
}

class Smaller_than{
    double val;
public:
    Smaller_than(double vv): val{vv} {}
    bool operator()(const Item& x) const {return x.value < val;}
};

class Cmp_by_name{
    std::string name;
public:
    Cmp_by_name(const std::string& nn): name{nn}{}
    bool operator()(const Item& x) const{return x.name == name;}
};

class Cmp_by_iid{
    int iid;
public:
    Cmp_by_iid(int id): iid(id) {}
    bool operator()(const Item& x) const {return x.iid == iid;}
};

int main()
try{
    //-----------1. feladat-----------
    std::string iname {"drill_21a_text.txt"};

    std::ifstream ifs {iname};
    if(!ifs) throw std::runtime_error("Could not open file " + iname);

    std::vector<Item> vi;
    for(Item ii; ifs >> ii;){
        vi.push_back(ii);
    }
    print(vi, "1. Vector:");


    //-----------8. feladat-----------
    std::list<Item> li (vi.size());
    std::copy(vi.begin(),vi.end(),li.begin());

    //-----------2. feladat-----------
    std::sort(vi.begin(), vi.end(), 
            [](const Item& a, const Item& b) {return a.name < b.name; });
    print(vi, "2. Vector sort name:");

    //-----------3. feladat-----------
    std::sort(vi.begin(), vi.end(),
            [](const Item& a, const Item& b) { return a.iid < b.iid; });
    print(vi, "3. Vector sort iid:");
    
    //-----------4. feladat-----------
    std::sort(vi.begin(), vi.end(), Cmp_by_dec_val());
    print(vi, "4. Vector sort value:");

    //-----------5. feladat-----------
    //vi.push_back(Item{"horse shoe", 99, 1.34});
    Item tmp {"horse shoe", 99, 1.34};
    vi.insert(std::find_if(vi.begin(),vi.end(), Smaller_than(tmp.value)), tmp);
    tmp = {"Canon S400", 9988,499.95};
    vi.insert(std::find_if(vi.begin(),vi.end(), Smaller_than(tmp.value)), tmp);
    print(vi, "5. Vector insert:");

    //-----------6. feladat-----------
    vi.erase(std::find_if(vi.begin(),vi.end(),Cmp_by_name("water")));
    vi.erase(std::find_if(vi.begin(),vi.end(),Cmp_by_name("chair")));
    print(vi, "6. Vector erase by name:");

    //-----------7. feladat-----------
    vi.erase(std::find_if(vi.begin(),vi.end(),Cmp_by_iid(17)));
    vi.erase(std::find_if(vi.begin(),vi.end(),Cmp_by_iid(83)));
    print(vi, "7. Vector erase by iid:");

    //-----------8.1. feladat-----------
    print(li, "8.1. List:");

    //-----------8.2 feladat-----------
    li.sort([](const Item& a, const Item& b) {return a.name < b.name;});
    print(li, "8.2. List sort by name:");

    //-----------8.3 feladat-----------
    li.sort([](const Item& a, const Item& b) {return a.iid < b.iid;});
    print(li, "8.3. List sort by iid:");

    //-----------8.4 feladat-----------
    li.sort([](const Item& a, const Item& b) {return a.value > b.value;});
    print(li, "8.4. List sort by value:");

    //-----------8.5 feladat-----------
    tmp = {"horse shoe", 99, 1.34};
    li.insert(std::find_if(li.begin(), li.end(), Smaller_than(tmp.value)), tmp);
    tmp = {"Canon S400", 9988,499.95};
    li.insert(std::find_if(li.begin(), li.end(), Smaller_than(tmp.value)), tmp);
    print(li, "8.5. List insert:");

    //-----------8.6 feladat-----------
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_name("water")));
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_name("chair")));
    print(li, "8.6. List erase by name:");

    //-----------8.7 feladat-----------
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(17)));
    li.erase(std::find_if(li.begin(), li.end(), Cmp_by_iid(83)));
    print(li, "8.7. List sort by iid:");

    return 0;
}catch(std::exception& e){
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}catch(...){
    std::cerr << "Unknown exception\n";
    return 2;
}