#include <iostream>

class Base
{
public:
    int a;

    Base() {
        std::cout << "constructor of Base" << std::endl;
    }
    virtual ~Base(){
        std::cout << "destructor of Base" << std::endl;
    }

    void foo(){}
};


class Derived : public Base
{
public:
    int b;
    Derived() {
        std::cout << "constructor of Derived" << std::endl;
    }
    ~Derived(){
        std::cout << "destructor of Derived" << std::endl;
    }
    void foo(){
        std::cout << "foo of Derived" << std::endl;
    }
};

int main(int argc, char const *argv[])
{ 
    Base* p = new Derived();
    p->foo();
    delete p;
    return 0;
}