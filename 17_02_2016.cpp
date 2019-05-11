#include<iostream>
using std::cout; using std::endl; 

class Z {
    public: Z(int x){};
};

class A {
    public:
    void f(int) {cout << "A::f(int) ";}
    virtual void f(bool) {cout << "A::f(bool) ";}
    virtual void f(Z) {cout << "A::f(Z) ";}
};

class B :virtual public A{
    public:
    void f(const int &) {cout << "B::f(int) ";}
    void f(const bool &) {cout << "B::f(bool) ";}
};

class C : virtual public A {
    public:
    virtual void f(Z) {cout << "C::f(Z) ";}
};

class D : public B, public C {
    public: 
    void f(int&) {cout << "D::f(int&) ";}
    virtual void f(int*) {cout << "D::f(int*) ";}
    
};

class E : public D {
    public: void f(Z) {cout << "E::f(Z) ";}
};

int main(){ 
    B* pb = new B();
    C* pc = new C();
    D* pd = new D();
    E* pe = new E();
    A* pa1 = new B();
    A* pa2 = new C();
    A* pa3 = new D();
    A* pa4 = new E();
    C* pc1 = new E();

    (dynamic_cast<B*>(pa1)) ->f(1); cout << endl;
    (dynamic_cast<B*>(pa1)) ->f(true); cout << endl;
    pa1->f(true); cout << endl;
    pa2->f(1); cout << endl;
    (dynamic_cast<C*>(pa2)) ->f(1); cout << endl;
    //(dynamic_cast<E*>(pa2)) ->f(1); 
    cout << endl;
    (dynamic_cast<C*>(pa3)) ->f(0); cout << endl;
    (dynamic_cast<D*>(pa3)) ->f(0); cout << endl;
    pa4->f(1); cout << endl;
    (dynamic_cast<C*>(pa4)) ->f(1); cout << endl;
    pc1->f(1); cout << endl;
    (static_cast<E*>(pc1)) ->f(1); cout << endl;
    (static_cast<A*>(pc1)) ->f(1); cout << endl;
}
