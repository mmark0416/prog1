#include <iostream>
#include <vector>
#include <string>

template<typename T>
struct S {
    S(T vv = 0): val(vv) {}

    T& get();
    const T& get() const;
    void set(T x) { val = x; };

    S& operator=(const T&);
private:
    T val;
};

template<typename T>
const T& S<T>::get() const
{
    return val;
}

template<typename T>
T& S<T>::get()
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s){
    val = s;
    return *this;
}

template<typename T>
void read_val(T& v){
    std::cin >> v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T>& v){
    os << "{";
    for(int i=0; i<v.size(); i++){
        os << v[i] << (i<v.size()-1 ? ", " : "");
    }
    os << "}\n";
    
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v){
    char ch;
    is >> ch;
    if(ch != '{'){
        is.unget();
        return is;
    }
    for(T val; is>>val;){
        v.push_back(val);
        is >> ch;
        if (ch != ',') break;
    }
    return is;
}

int main(){

    S<int> in {20};
    S<char> ch {'c'};
    S<double> db {5.55};
    S<std::string> st {"szeva"};
    S<std::vector<int>> ve {std::vector<int> {1, 2, 6, 24, 120}};

    std::cout << "S<int>: " << in.get() << '\n'
              << "S<char>: " << ch.get() << '\n'
              << "S<double>: " << db.get() << '\n'
              << "S<string>: " << st.get() << '\n'
              << "S<vector<int>>: ";
    for(int v: ve.get()){
        std::cout << v << " ";
    }
    std::cout << '\n';
    
    ch.set('s');
    std::cout << "S<char>: " << ch.get() << '\n';

    in = 15;
    ch = 'q';
    db = 9.9999;
    st = "csumi";
    std::cout << "S<int>: " << in.get() << '\n'
              << "S<char>: " << ch.get() << '\n'
              << "S<double>: " << db.get() << '\n'
              << "S<string>: " << st.get() << '\n';
    
    std::cout << "Reads:\n";

    std::cout << "Int: ";
    int ii;
    read_val(ii);
    S<int> in2 {ii};

    std::cout << "Char: ";
    char uu;
    read_val(uu);
    S<char> ch2 {uu};

    std::cout << "Double: ";
    double zz;
    read_val(zz);
    S<double> db2 {zz};

    std::cout << "String: ";
    std::string tt;
    read_val(tt);
    S<std::string> st2 {tt};

    std::cout << "S<int>: " << in2.get() << '\n'
              << "S<char>: " << ch2.get() << '\n'
              << "S<double>: " << db2.get() << '\n'
              << "S<string>: " << st2.get() << '\n';

    std::cout << "Read vector<int>: {val1, val2, val3}";
    std::vector<int> vv;
    read_val(vv);
    S<std::vector<int>> ve2 {vv};

    std::cout << "S<vector<int>>: " << ve2.get() << '\n';

    return 0;
}