#include<iostream>
using std::cout; using std::endl; 

class A {
    public:
        virtual ~A() = default;
};

class B : virtual public A{
};

class C : virtual public A {};

class D : public B, public C {
};

class E : public D {
};
class F : public E{};

template<class T>
void Fun( T& ref){
	B* p = &ref;
    try{throw ref;}
    catch(E){cout << "E "; }
    catch(D){cout << "D ";}
    catch(B){cout << "B ";}
    catch(A){cout << "A ";}
    catch(C){cout << "C ";}
    catch(...){cout << "Gen ";}
}

int main(){ 
	A a; B b;
    C c; 
    D d;
    E e; F f;
    A* pa = &b;
    B* pb = dynamic_cast<B*>(pa);
    D* pd = &f;
    E* pe = static_cast<E*>(pd);
	C* pc = dynamic_cast<E*>(pd);
	
	//Fun(a); cout << endl;
    Fun(b); cout << endl;
    
    //Fun(c); cout << endl;
    Fun(d); cout << endl;
    Fun(e); cout << endl;
    Fun(f); cout << endl;
    
    //Fun(*pa); cout << endl;
    Fun(*pb); cout << endl;
    //Fun(*pc); cout << endl;
    Fun(*pd); cout << endl;
    Fun(*pe); cout << endl;
    Fun<B>(*pd); cout << endl;
    Fun<D>(*pd); cout << endl;
    //Fun<E>(*pd); cout << endl;
    
}
