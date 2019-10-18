#include <vector>
#include <set>
#include <iostream>
using namespace std;



class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int n = A.size();
        int longest = 0;
        set<int> s(A.begin(),A.end());

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int a = A[i];
                int b = A[j];
                int length = 2;
                while(s.count(a+b)){
                    int t = b;
                    b = b + a;
                    a = t;
                    length++;
                }
                //std::cout << i << ',' << j << ',' << length << std::endl;
                longest = max(longest,length);
            }
        }
        return longest == 2 ? 0 : longest;        
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,3,4,5};
    Solution so;
    std::cout << so.lenLongestFibSubseq(v) << std::endl;

    return 0;
}