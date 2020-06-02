class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        sort(nums.begin(),nums.end());
        int ret = 0;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                for(int k=j+1;k<nums.size()-1;k++){
                    if(nums[i]+nums[j] > nums[k]){
                        ret++;
                    }
                }   
            }
        }
        return ret;
    }  
};

