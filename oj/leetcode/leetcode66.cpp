#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res(n,0);
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            res[i] = (digits[i] + carry)%10;
            carry = (digits[i] + carry)/10;
        }
        if(carry !=0){
            res.insert(res.begin(),carry);
        }
        return res;
    }
};