#include <vector>
#include <iostream>

/*
   note: start <= end
   boundary conditions.
*/

using namespace std;
bool binary_search(vector<int> array,int target){
    int len = array.size();
    int start = 0;
    int end = len - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(target == array[mid]){
            return true;
        }else if(target > array[mid]){
            start = mid + 1;
        }else {
            end = mid - 1;
        }
    }
    return false;
}

int main(){
    std::vector<int> v = {1,2,3,4,5,6,7};
    std::cout << binary_search(v,5) << std::endl;
    return 0;
}