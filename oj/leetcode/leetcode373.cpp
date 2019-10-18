#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct compare{
        bool operator()(const vector<int>& l,const vector<int>& r){
            return l[0] + l[1] < r[0]+r[1];
        }   
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ret;

        priority_queue<vector<int>,vector<vector<int>>,compare> p;

        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(p.size() < k){
                    p.push(vector<int>{nums1[i],nums2[j]});
                }else if(nums1[i] + nums2[j] < p.top()[0] + p.top()[1]){
                    p.pop();
                    p.push(vector<int>{nums1[i],nums2[j]});
                }
            }
        }
        while(!p.empty()){
            ret.push_back(p.top());
            p.pop();
        }
        sort(ret.begin(),ret.end(),compare());
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {1,1,2};
    vector<vector<int>> ret = Solution().kSmallestPairs(nums1,nums2,5);

    for(auto r : ret){
        std::cout << r[0] << '\t' << r[1] << std::endl;
    }


    return 0;
}