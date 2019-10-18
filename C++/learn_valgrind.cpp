#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int a[5];
    a[0] = a[1] = a[3] = a[4] = 0;

    int s=0;
    for(int i=0;i<5;i++){
        s+=a[i];
    }
    if(s == 0){
        std::cout << s << std::endl;
    }
    a[5] = 10;
    std::cout << a[5] << std::endl;


    int *invalid_write = new int[10];
    delete [] invalid_write;
    invalid_write[0] = 3;

    int *undelete = new int[10];
    
    return 0;
}