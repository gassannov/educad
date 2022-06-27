//
// Created by Марат Гасанов on 06.06.2022.
//
#include "iostream"

class A{

};

class B{

};

int main(){
    std::shared_ptr<int> l(new int(4));
    std::shared_ptr<int> b = l;
    std::shared_ptr<int> c = b;
    std::shared_ptr<int> d = c;
}
