#include <utility>
#include <iostream>
class Myclass
{
public:
    int x;
    int y;
public:
    Myclass() = default;
    // Myclass(){}
    explicit Myclass(int a,int b):x(a),y(b){}  //自定义带参数构造函数
    Myclass(const Myclass& other){    //禁止编译器生成默认的拷贝构造函数
    
    }
    ~Myclass(){}

    Myclass& operator=(const Myclass& m){ 
        std::cout << "assign operator" << std::endl;    
        return *this;
    }
    Myclass* operator&(){
        std::cout << "operator &" << std::endl;
        return this;
    }
    const Myclass* operator&()const{
        std::cout << "const operator &" << std::endl;
        return this;
    }

    //C++11
    Myclass(Myclass&& m){} //C++11 move con
    //C++11 move assign
    Myclass& operator=(Myclass&& m){
        std::cout << "move assign" << std::endl;    
        return *this;
    }
};


class EmptyClasss
{
public:
    EmptyClasss(){}
    ~EmptyClasss(){}
    
};

struct TestStruct
{
    bool isEmpty;
    int a;
    int b;
    
};

Myclass global_m;

int main(int argc, char const *argv[])
{
    Myclass m1;
    Myclass m2(m1);

    return 0;
}