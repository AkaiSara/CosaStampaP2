#include<iostream>
using std::cout; using std::endl; 

class A {
    protected:
        virtual void j(){ cout << "A::j ";}
    public:
        virtual void g() const {cout << "A::g ";} 
        virtual void f() {cout << "A::f "; g(); j();}
        void m() {cout<< "A::m "; g(); j();}
        virtual void k() {cout << "A::k "; j(); m();}
        virtual A* n() {cout << "A::n "; return this;}
};

class B : public A {
    public:
        virtual void g() const override {cout << "B::g ";} 
        virtual void m() {cout<< "B::m "; g(); j();}
        void k() {cout << "B::k "; A::n(); }
        A* n() override {cout << "B::n "; return this;}
};

class C : public A {
    private:
        void j(){ cout << "C::j ";}
    public:
        virtual void g() {cout << "C::g ";} 
        void m() {cout<< "C::m "; g(); j();}
        void k() const {cout << "C::k "; k();} 
};

class D : public B {
    protected:
        void j(){ cout << "D::j ";}
    public:
        B* n() {cout << "D::n "; return this;}
        void m() {cout<< "D::m "; g(); j();}
};

int main(){ 
    A* p1 = new D();
    A* p2 = new B();
    A* p3 = new C();
    B* p4 = new D();
    const A* p5 = new C();

    p1->g(); cout << endl;
    p1->k(); cout << endl;

    p2->f(); cout << endl;
    p2->m(); cout << endl;
    p3->k(); cout << endl;

    p3->f(); cout << endl;
    p4->m();cout << endl;
    p4->k();cout << endl;

    p5->g(); cout << endl;
    (p3->n())->m(); cout << endl;
    ((p3->n())->n())->g(); cout << endl;
    (p4->n())->m(); cout << endl;
    //(p5->n())->g(); cout << endl; //non compila
    
    (dynamic_cast<B*>(p1))->m(); cout << endl;
    //(static_cast<C*>(p2))->k(); cout << endl; //chiamata ricorsiva a C::k
    (static_cast<B*>(p3->n()))->g(); cout << endl;
}