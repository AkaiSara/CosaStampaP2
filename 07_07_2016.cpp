#include<iostream>
using std::cout; using std::endl; 

class A {
    public: A() {cout << "A ";}
};

class B :virtual public A {
    public: B() {cout << "B ";}
};

class C : virtual public A {
    public: C() : A() {cout << "C ";}
};

class D : virtual public B, virtual public C {
    public: D() : C(),B() {cout << "D ";}
};

class E : public B {
    public: E() {cout<< "E ";}
};
class F : public E, virtual public C {
    public: F() {cout<< "F ";}
};

int main(){ 
    F f;
}