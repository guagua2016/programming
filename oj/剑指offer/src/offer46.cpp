class Solution{
public:
    int LastRemaining_Solution(int n,int m){
        if(n<1 || m < 1) return -1;

        int* arr = new int[n];
        int count = n;
        int i= -1;
        int step = 0;
        while(count > 0){
            i++;
            if(i == n) i = 0;
            if(arr[i] == -1) continue;
            step++;
            if(step == m){
                step = 0;
                arr[i] = -1;
                count--;
            }
        }
        return i;
    }
};