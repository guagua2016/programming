#include <vector>
#include <iostream>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3)
            return 0;

        int left = 0;
        int right = n - 1;

        int res = 0;
        int mx = -1;
        while (left < right) {
            while (left < right && height[left] <= height[right]) {
                if (height[left] < mx)
                    res += mx - height[left];
                else
                    mx = height[left];
                left++;
            }
            while (left < right && height[left] > height[right]) {
                if (height[right] < mx)
                    res += mx - height[right];
                else
                    mx = height[right];
                right--;
            }
        }
        return res;
    }
};