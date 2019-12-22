class Solution {
public:
    int arrangeCoins(int n) {
        long sum  = 0;
        int ret = 0;
        while(sum <= n){
            ret++;
            sum += ret;
        } 

        return ret - 1;    
    }
};