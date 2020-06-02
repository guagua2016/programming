#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;

        if(numRows < 1) return res;
        vector<int> v = {1};
        res.push_back(v);
        if(numRows == 1){   
            return res;
        } 

        int count = 1;
        while(count < numRows){
            vector<int> v = res[count-1];
            vector<int> v2;
            v2.push_back(1);
            for(int i=0;i<v.size()-1;i++){
                v2.push_back(v[i]+v[i+1]);
            }
            v2.push_back(1);
            res.push_back(v2);
            count++;
        }       
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution so;
    vector<vector<int>> res = so.generate(5);
    return 0;
}