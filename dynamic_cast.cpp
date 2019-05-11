#include<iostream>
using std::cout; using std::endl; 

class A {
    public:
    virtual void m() {};
};

class B : public A {
    public:
    virtual void m() {};
};

class D : public A {
    public: virtual void m(){};
};

class E : public D{
    public: virtual void m(){};
};

template<typename T1, typename T2, typename T3>
void fun(){
    T1* p = new T2(); 
    if(dynamic_cast<T3*>(p)) cout<< 'y';
    else cout <<'0';
	cout << endl;
}

/*
Gerarchia dei tipi
    A
B       D
    E    
    */

int main(){ 
    //se A è una classe astratta -> ER, se A è una classe concreta -> 0
    fun<A,A,D>();

    fun<A,D,D>();  //stampa in entrambi i casi y perchè D <= D (tipo dinamico)
    fun<A,E,D>(); // in entrambi i casi stampa y perchè E <= D (è un sottotipo)
    fun<D,E,D>(); // stampa y perchè sia il tipo dinamico che statico sono sottitipi di D
    fun<E,E,D>();// stampa y perchè sia il tipo dinamico che statico sono sottitipi di D
    fun<A,B,D>(); //stampa 0 perchè B non è un sottotipo di D, ma compila perchè B è sottotipo di A
}
