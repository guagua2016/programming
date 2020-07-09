class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int maxSum = array[0];
        int* t = new int[array.size()];
        t[0] = array[0];
        int former = array[0];
        for(int i=1;i<array.size();i++){
            if(former>0){
                former = former + array[i];
            }else{
                former = array[i];
            }
            if(former > maxSum){
                maxSum = former;
            }
        }
        return maxSum;
    }
};