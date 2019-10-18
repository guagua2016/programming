class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ret = 0;
        int cur_max = 0;
        for(int num : nums){
            if(num == 1){
                cur_max++;
            }else{
                ret = max(ret,cur_max);
                cur_max = 0;
            }
        } 
        return max(ret,cur_max);       
    }
};