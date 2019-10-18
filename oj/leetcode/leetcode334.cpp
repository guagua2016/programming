//BF
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                if(nums[j] > nums[i]){
                    for(int k=j+1;k<n;k++){
                        if(nums[k] > nums[j]){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

//O(n) & O(1)
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;

        for(int a : nums){
            if(m1 >= a) m1 = a;
            else if(m2 >= a) m2 = a;
            else{
                return true;
            }
        }
        return false;
    }
};


