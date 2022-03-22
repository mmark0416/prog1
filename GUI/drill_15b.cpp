#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

void error(string s)
{
    throw runtime_error(s);
}

void error(string s1, string s2)
{
    throw runtime_error(s1 + s2);
}

struct Person {
    Person() { }
    Person(string ff, string ll, int aa);
    Person(string ff, int aa):first(ff), age(aa) {};
    Person(string ff): first(ff) {};

    string first_name() const { return first; }
    string last_name() const { return last; }
    int get_age() const { return age; }

private:
    string first;
    string last;
    int age;
};

Person::Person(string ff, string ll, int aa)
    : first{ff}, last{ll}, age{aa}
{
    if (aa < 0 || 150 < aa) error("Person(): invalid age");
    
    string nn = ff + ll;       
    for (char c : nn) {
        switch(c) {
            case ';': case ':': case '"': case '[': case ']': case '*':
            case '&': case '^': case '%': case '$': case '#': case '@':
            case '!':
                error("Person(): bad char in names");
                break;
            default:
                break;
        }
    }
}

ostream& operator<<(ostream& os, const Person& p)
{
    return os << p.first_name() << ' '
              << p.last_name() << '\t'
              << p.get_age();
}

istream& operator>>(istream& is, Person& p)
{
    string f;
    string l="";
    int a=0;

    is >> f;
    if(f=="end")
        p = Person(f);
    else
    is >> l >> a;
    if (!is) error("Unable to read into Person");
    p = Person(f, l, a);

    return is;
}

int main()
try{
    Person pers{"Goofy", 63};
    cout << pers << endl;

    vector<Person> vp;

    cout << "Enter some names and ages. Terminate with name 'end'\n";

    for (Person p; cin >> p; ) {
        if (p.first_name() == "end") break;
        vp.push_back(p);
    }

    for (Person p : vp)
        cout << p << '\n';
}
catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch (...) {
    std::cerr << "Unknown error!\n";
    return 2;
}