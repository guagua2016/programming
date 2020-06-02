class Solution {
public:
    int maxArea(vector<int>& height) {

        int maxArea = 0;
        int left = 0;
        int right = height.size()-1;

        int area = 0;
        while(left < right){
            area = (right - left)*min(height[left],height[right]);
            maxArea =  max(maxArea,area);
            if(height[left] <= height[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};