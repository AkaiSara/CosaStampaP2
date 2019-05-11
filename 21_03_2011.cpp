#include<iostream>
using namespace std;

class A{public: virtual void f(int x=0) {cout << "a:f->" << x << endl;}};
class B: public A {public: virtual void f(int x=1) {cout << "b:f->" << x << endl;}};

int main(){
    A*p= new A; p-> f();
    p= new B; p-> f();
    B*q= new B; q-> f();
}