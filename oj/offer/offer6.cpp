#include <vector>

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int n= rotateArray.size();
        if(n==0){
            return 0;
        }
        if(n == 1) return rotateArray[0];

        int left = 0;
        int right = rotateArray.size() - 1;
        while(left < right){
            if(rotateArray[left] < rotateArray[right]) 
                return rotateArray[0];
            int mid = (left + right) / 2;
            if(rotateArray[left] < rotateArray[mid]){
                left = mid + 1;
            }else if(rotateArray[mid] < rotateArray[right]){
                right = mid;
            }else if{
                left++;
            }
        }
        return rotateArray[left];
    }
};