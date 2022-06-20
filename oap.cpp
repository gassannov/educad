//
// Created by Марат Гасанов on 06.06.2022.
//
#include "iostream"

class A;
class B;
class C{
    A* a;
    void foo(){
        a->out();
    }
};

class A{
    int a;
    C* c;
public:
    void out(){
        std::cout << "SOME\n";
    }
};

class B:A{
    int b;
};

int main(){

}
