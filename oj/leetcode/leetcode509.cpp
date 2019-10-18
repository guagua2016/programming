class Solution {
public:
    int fib(int N) {
        if(N < 2) return N;
        int n_1 = 1;
        int n_2 = 0;
        for(int i=2;i<=N;i++){

            int tmp = n_1;
            n_1 = n_1 + n_2;
            n_2 = tmp;
        }
        return n_1;
        
    }
};