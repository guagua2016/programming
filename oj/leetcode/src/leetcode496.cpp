#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }

        vector<int> ret;
        for(int i=0;i<nums1.size();i++){
            int j;
            for(j=m[nums1[i]]+1;j<nums2.size();j++){
                if(nums2[j] > nums1[i]){
                    ret.push_back(nums2[j]);
                    break;
                }
            }
            if(j >= nums2.size()){
                ret.push_back(-1);
            }
            std::cout << i << '\t' << nums1[i] << '\t' << nums2[nums1[i]] << std::endl;

        }
        return ret;
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v1 = {4,1,2};
    vector<int> v2 = {1,3,4,2};
    
    vector<int> ret = Solution().nextGreaterElement(v1,v2);
    for(int i=0;i<ret.size();i++){
        std::cout << ret[i] << '\t' << std::endl;
    }

    return 0;
}