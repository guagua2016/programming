class Solution {
public:
    int jumpFloor0(int number) {
        if(number <= 1) return 1;
        else if(number == 2) return 2;
        else return jumpFloor(number-1) + jumpFloor(number-2);
    }

    int jumpFloor(int number){
        if(number <= 1) return 1;
        else if (number == 2) return 2;
        int former = 2;
        int former_former = 1;
        int cur = 0;
        for(int i=3;i<=number;i++){
            cur = former + former_former;
            former_former = former;
            former = cur;
        }
        return cur;
    }
};