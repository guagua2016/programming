class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int left = 0;
        int right = nums.back() - nums[0];
        while(left < right){
            int mid = (left + right)/2;
            int cnt = 0;
            int start = 0;
            for(int i=0;i<n;i++){
                while(start < n && nums[i] - nums[start] > mid) ++start;
                cnt += i - start;
            }

            //===================================
            if(cnt < k) left = mid + 1;
            else right = mid;
        }
        return right;
        
    }
};


