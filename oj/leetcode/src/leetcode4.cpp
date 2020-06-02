class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();

        int index2 = (n1 + n2)/2;
        int index1 = index2;
        if((n1 + n2) % 2 == 0){
            index1 = index2-1;
        }

        int i1 = 0;
        int i2 = 0;
        int value1 = 0;
        int value2 = 0;
        int value = 0;
        while(i1 < n1 || i2 < n2){
            if(i2 >= n2 || (i1 < n1 && nums1[i1] <= nums2[i2])){
                value = nums1[i1];
                i1++;
            }else{
                value = nums2[i2];
                i2++;
            }
            if(i1+i2-1 == index1){
                value1 = value;
            }
            if(i1+i2-1 == index2){
                value2 = value;
                break;
            }
        }
        return (value1 + value2)/2.0;
    }
};
