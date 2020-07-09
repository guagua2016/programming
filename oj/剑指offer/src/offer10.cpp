class Solution {
public:
    int rectCover(int number) {
        if(number == 1) return 1;
        else if(number == 2) return 2;
        int fn_1 = 2;
        int fn_2 = 1;
        int cur = 0;
        for(int i=3;i<=number;i++){
            cur = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = cur;
        }
        return cur;
    }
};