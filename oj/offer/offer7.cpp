#include <iostream>

class Solution {
public:

    //excessed time
    int Fibonacci0(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        return Fibonacci0(n-1) + Fibonacci0(n-2);
    }

    int Fibonacci(int n){
        if(n == 0) return 0;
        if(n == 1) return 1;
        int *dp = new int[40]; 
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }

};


int main(){
    Solution so;
    std::cout << so.Fibonacci(39) << std::endl;
}