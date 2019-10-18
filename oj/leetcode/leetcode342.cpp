class Solution {
public:
    bool isPowerOfFour(int num) {
        long t = 1;
        while(t < num){
            t = t << 2;
        }
        if(t == num) return true;
        return false;
        
    }
};