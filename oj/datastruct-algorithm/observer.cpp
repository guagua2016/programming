#include <iostream>



class ConcreteElement1;
class ConcreteElement2;

class Visitor{
public:
    virtual ~Visitor(){};
    virtual void visit(ConcreteElement1&) = 0;
    virtual void visit(ConcreteElement2&) = 0;
};

class ConcreteVisitor : public Visitor{
public:
    virtual ~ConcreteVisitor(){};
    
    void visit(ConcreteElement1& e){
        std::cout << "ConcreteElement1::visit" << std::endl;
    }
    void visit(ConcreteElement2& e){
        std::cout << "ConcreteElement2::visit" << std::endl;
    }
};

class Element{
public:
    virtual ~Element(){};
    virtual void accept(Visitor&) = 0;
};

class ConcreteElement1 : public Element{
public:
    virtual ~ConcreteElement1(){}
    void accept(Visitor& v){
        v.visit(*this);
    }
};
class ConcreteElement2 : public Element{
public:
    virtual ~ConcreteElement2(){};
    void accept(Visitor& v){
        v.visit(*this);
    }

};


int main(){
    ConcreteVisitor visitor;
    ConcreteElement1 emt1 = ConcreteElement1();
    emt1.accept(visitor);
    ConcreteElement2 emt2 = ConcreteElement2();
    emt2.accept(visitor);
    return 0;
}