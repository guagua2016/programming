#include <list>
#include <iostream>
using namespace std;

class Solution {
public:
    //TLE
    int lastRemaining1(int n) {
        list<int> l;
        for(int i=1;i<=n;i++){
            l.push_back(i);
        }

        int direction = 1;
        list<int>::iterator it;

        while(l.size() != 1){
            int n = l.size();
            if(direction == 1){
                it = l.begin();
                for(int i=0;i<n;i+=2){
                    if(i == 0){
                        l.erase(it);
                        it = l.begin();
                    }else{
                        list<int>::iterator tm = it; 
                        l.erase(++it);
                        it = tm;
                        it++;
                    }
                }
                direction = -1;
            }else{
                it = l.end();
                it--;
                for(int i=n-1;i>=0;i-=2){
                    if(i == n-1){
                        list<int>::iterator tm = it;
                        tm--;
                        l.erase(it);
                        it = tm;  
                    }else{
                        list<int>::iterator tm = it;
                        l.erase(--it);
                        it = tm;
                        it--;
                    }
                }
                direction = 1;
            }
        }
        return *l.begin();
    }

    int lastRemaining(int n) {
        return help(n, true);    
    }
    int help(int n, bool left2right) {
        if (n == 1) return 1;
        if (left2right) {
            return 2 * help(n / 2, false);
        } else {
            return 2 * help(n / 2, true) - 1 + n % 2;
        }
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().lastRemaining(9) << std::endl; //6
    std::cout << Solution().lastRemaining(4) << std::endl; //3


    std::cout << Solution().lastRemaining(10) << std::endl;//8
    std::cout << Solution().help(5,false) << std::endl;
    std::cout << Solution().lastRemaining(5) << std::endl; //4

    // list<int> l = {1,2,3};
    // list<int>::iterator it = l.begin();
    // std::cout << *(++it) << std::endl;

    return 0;
}