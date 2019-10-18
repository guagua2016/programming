#include <iostream>
#include <mutex>

std::mutex mtx;
class Singleton {
private:
    Singleton() {}
    Singleton(const Singleton& a);
    Singleton& operator=(const Singleton&);
    static Singleton * instance;
public:
    static Singleton* getInstance() {
        if (instance == nullptr) {
            mtx.lock();
            if((instance == nullptr)){
                instance =  new Singleton();
            }
            mtx.unlock();
        }
        return instance;
    }
};
Singleton* Singleton::instance = nullptr;

int main(){
    Singleton* instance1 = Singleton::getInstance();
    Singleton* instance2 = Singleton::getInstance();
    if(instance1 == instance2){
        std::cout << "singleton" << std::endl;
    }
    return 0;
}