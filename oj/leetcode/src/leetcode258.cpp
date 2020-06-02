class Solution {
public:
    inline int addAddDigits(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num = num / 10;
        }
        return sum;
    }

    int addDigits(int num) {
        if(num < 10) return num;
        while(num > 9){
            num = addAddDigits(num);
        }
        return num;
    }
};