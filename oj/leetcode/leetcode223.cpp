#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int help(int A,int B,int C,int D){
        if(C >=B || A >= D){
            return 0;
        }
        vector<int> v;
        v.push_back(A);
        v.push_back(B);
        v.push_back(C);
        v.push_back(D);
        sort(v.begin(),v.end());
        return v[2] - v[1];
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        long s1 = (C - A)*(D-B);
        long s2 = (G - E)*(H-F);       
        int w = help(A,C,E,G);
        int h = help(B,D,F,H);
        return s1+s2 - w*h;
    }
};

int main(int argc, char const *argv[])
{
    std::cout << Solution().computeArea(-3,0,3,4,0,-1,9,2) << std::endl;
    return 0;
}