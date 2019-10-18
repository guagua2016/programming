#include <vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> sta;
        int inIndex = 0;
        int outIndex = 0;
        while(inIndex < pushV.size()){
            while(pushV[inIndex] == popV[outIndex]){
                inIndex++;
                outIndex++;
            }
           
            if(inIndex < pushV.size()){
                sta.push(pushV[inIndex]);
                inIndex++;
            }

             while(!sta.empty() && sta.top() == popV[outIndex]){
                sta.pop();
                outIndex++;
            }
        }
        return sta.empty();
    }
};