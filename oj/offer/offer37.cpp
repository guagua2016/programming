#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int n = data.size();
        return help(data,0,n-1,k);
    }
private:
    int help(vector<int>& data,int left,int right,int k){
        if(left > right) return 0;
        if(data[right] < k || data[left] > k) return 0;
        int mid = (right + left)/2;
        if(data[mid] == k){
            return help(data,left,mid-1,k) + help(data,mid+1,right,k) + 1;
        }else if(data[mid] > k){
            return help(data,left,mid-1,k);
        }else if(data[mid] < k){
            return help(data,mid+1,right,k);
        }
    } 
};


int main(int argc, char const *argv[])
{
    vector<int> v = {1,2,2,3,3,3,3,4,5};
    Solution so;
    std::cout << so.GetNumberOfK(v,3) << std::endl;
    return 0;
}