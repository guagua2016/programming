#include <ctime>
#include <cstdio>

int main(int argc, char const *argv[])
{
    clock_t start = clock();


    clock_t end = clock();
    printf("time: %f \n", (end - start) * 1.0 / CLOCKS_PER_SEC * 1000);
    return 0;
}