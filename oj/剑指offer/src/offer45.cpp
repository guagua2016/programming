#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
    bool IsContinuous(vector<int> numbers){
        sort(numbers.begin(),numbers.end());
        int n = numbers.size();
        if(n < 5) return false;
        int minVal = 14;
        int maxVal = -1;
        for(int i=0;i<n;i++){
            if(numbers[i] == 0){
                continue;
            }
            if(numbers[i] < minVal){
                minVal = numbers[i];
            }
            if(numbers[i] > maxVal){
                maxVal = numbers[i];
            }
            if(i > 0 && numbers[i] == numbers[i-1]){
                return false;
            }
        }
        if(maxVal - minVal < 5){
            return true;
        }else{
            return false;
        }
    }
};