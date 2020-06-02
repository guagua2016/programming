class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n = A.size();
        int maxSum = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxSum = max(maxSum,count(A,B,i,j));
                maxSum = max(maxSum,count(B,A,i,j));
            }
        }
        return maxSum;
    }

    int count(vector<vector<int>>& A,vector<vector<int>>& B,int rowOffset,int colOffset){
        int ret = 0;
        int n = A.size();
        for(int i=rowOffset;i<n;i++){
            for(int j=colOffset;j<n;j++){
                ret += A[i][j] & B[i-rowOffset][j-colOffset];
            }
        }
        return ret;

    }
};