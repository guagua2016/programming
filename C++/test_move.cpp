#include <iostream>

int main(int argc, char const *argv[])
{
    int a = 1;
    int&& ra = std::move(a);
    ra = 10;
    std::cout << a << '\t' << ra << std::endl;
    return 0;
}