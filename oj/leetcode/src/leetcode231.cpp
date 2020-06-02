class Solution {
public:
    bool isPowerOfTwo(int n) {
        long t = 1;
        while(t < n){
            t = t  << 1;
        }
        if(t == n) return true;
        return false;
    }
};