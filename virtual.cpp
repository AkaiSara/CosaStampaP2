#include<iostream>
using namespace std;

class A{
private: void h(){cout << "A::h";} //non è virtuale, è statica
public: virtual void g(){cout << "A::g";}
    virtual void f(){cout << "A::f"; g(); h();}
    void m(){cout << "A::m"; g(); h();}
    virtual void k(){cout << "A::k"; g(); h(); m();} //chiamata polimorfa su g()
    A* n(){cout << "A::n"; return this;}
};

class B: public A{
private: void h(){cout << "B::h";}
public: virtual void g(){cout << "B::g";} //override
    void m(){cout << "B::m"; g(); h();}
    void k(){cout << "B::k"; g(); h(); m();} //override
    B* n(){cout << "B::n"; return this;}
};

int main(){
    B*b = new B();
    A*a = new B();
    b->f();
}
