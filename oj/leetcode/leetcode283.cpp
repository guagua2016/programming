class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return;
        int index_0 = -1;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                if(index_0 == -1){
                    index_0 = i;
                }
            }else{
                if(index_0 != -1){
                    nums[index_0++] = nums[i];
                    nums[i] = 0;
                }
            }
        }
    }
};