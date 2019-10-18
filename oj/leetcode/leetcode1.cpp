class Solution {
public:
  vector<int> twoSum(vector<int>& nums,int target){
        vector<int> res;
        unordered_map<int,int> mapping;
        for(size_t i=0;i<nums.size();i++){
            mapping[nums[i]] = i;
        }
        for(size_t i=0;i<nums.size();i++){
            const int key = target - nums[i];
            if(mapping.find(key) != mapping.end()){
                if(i != mapping[key]){
                    res.push_back(i);
                    res.push_back(mapping[key]);
                    break;
                }
            }
        }
        return res;
    }
};