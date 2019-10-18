class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> v1(n,1);
        vector<int> v2(n,1);
        vector<int> v(n,1);

        int a = 1;
        for(int i=0;i<n;i++){
            a = a * nums[i];
            v1[i] = a; 
        }
        a = 1;
        for(int i=n-1;i>=0;i--){
            a = a * nums[i];
            v2[i] = a;
        } 
        
        for(int i=0;i<n;i++){
            if(i==0)  v[i] = v2[1];
            else if(i==n-1) v[i] = v1[n-2];
            else v[i] = v1[i-1]* v2[i+1];
        }

        return v;
    }
};