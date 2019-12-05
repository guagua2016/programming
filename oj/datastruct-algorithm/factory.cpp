#include <iostream>

enum CTYPE {PRODUCTA,PRODUCTB};
class Product{
public:
    virtual void func() = 0;
    virtual ~Product(){};
};

class ProductA : public Product{
public:
    void func(){
        std::cout << "create ProductA..." << std::endl;
    }
};

class ProductB : public Product{
public:
    void func(){
        std::cout << "create ProductB..." << std::endl;
    }
};

class Factory{
public:
    static Product* createProduct(enum CTYPE ctype){
        if(ctype == PRODUCTA)
            return new ProductA;
        else if(ctype == PRODUCTB){
            return new ProductB;
        }else
            return nullptr;
    }
};

int main(){
    Product* p = Factory::createProduct(CTYPE::PRODUCTA);
    p->func();
    return 0;
}