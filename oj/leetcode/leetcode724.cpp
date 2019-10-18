class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        int curSum = 0;
        for(int i=0;i<nums.size();i++){
            if(curSum*2 == (sum - num)){
                return i;
            }else{
                curSum = curSum + nums[i];
            }
        }
        return -1;
    }
};