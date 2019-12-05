#include <vector>
#include <set>
using namespace std;




class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ret;
        vector<int> cur;
        help(nums,ret,0, cur);
        
        return vector<vector<int>> (ret.begin(),ret.end());
    }

    void help(vector<int>nums,set<vector<int>>& ret,int curIndex,vector<int> cur){
        if(curIndex >= nums.size()){
            if(cur.size() >= 2){
                ret.insert(cur);
            }
            return;
        }
        if(cur.empty() || nums[curIndex] >= cur[cur.size()-1]){
            cur.push_back(nums[curIndex]);
            help(nums,ret,curIndex+1,cur);
            cur.pop_back();
        }
        help(nums,ret,curIndex+1,cur);

    }

};


int main(int argc, char const *argv[])
{
    /* code */

    vector<int> nums = {4,6,7,7};
    vector<vector<int>> ret = Solution().findSubsequences(nums);

    return 0;
}