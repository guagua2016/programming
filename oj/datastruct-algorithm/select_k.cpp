#include <iostream>
#include <cassert>
using namespace std;

int selectKth(int a[],int start,int end,int k){
    assert(start <= end && k <= end+1);
    int left = start;
    int right = end;
    int pivotVal = a[left];
    while(left < right){
        while(left < right && a[right] >= pivotVal) right--;
        a[left] = a[right];
        while(left < right && a[left] <= pivotVal) left++;
        a[right] = a[left];
    }
    a[left] = pivotVal;
    if(left+1 == k) return a[left];
    else if(left+1 < k) return selectKth(a,left+1,end,k);
    else return selectKth(a,start,left-1,k);
}

int main() {
    int a[10] = {1,3,5,6,7,8,2,4};

    std::cout << selectKth(a,0,7,2) << std::endl;
    std::cout << selectKth(a,0,7,7) << std::endl;

    return 0;
}