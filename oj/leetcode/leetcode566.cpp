class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        if(nums.empty()) return nums;
        int row = nums.size();
        int col = nums[0].size();
        if(row * col != r * c) return nums;

        vector<vector<int>> ret;
        for(int i=0;i<r;i++){
            ret.push_back(vector<int>(c));
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ret[i][j] = nums[(i*c+j)/col][(i*c+j)%col];
            }
        }
        return ret;
    }
};