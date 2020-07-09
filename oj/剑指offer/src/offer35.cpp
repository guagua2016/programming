#include <vector>
#include <iostream>
using namespace std;



class Solution {
private:
    int doInversePairs(vector<int>& data,int left,int right){
        if(right <= left) return 0;
        int mid = (right + left)/2;
        int leftCount = doInversePairs(data,left,mid);
        int rightCount = doInversePairs(data,mid+1,right);
        return (leftCount + rightCount + merge(data,left,mid,right))%1000000007;
    }

    int merge(vector<int>& data,int left,int mid,int right){
        int *tmp = new int[right-left+1];

        int count = 0;
        int t = right-left;
        int p = mid;
        int q = right;
        while(p >= left && q > mid){
            if(data[p] > data[q]){
                count = (count + q-mid) % 1000000007;
                tmp[t--] = data[p--];
            }else{
                tmp[t--] = data[q--];
            }
        }
        while(p >= left){
            tmp[t--] = data[p--];
        }
        while(q > mid){
            tmp[t--] =data[q--];
        }
        for(int i=0;i<right-left+1;i++){
            data[i+left] = tmp[i];
        }
        delete[] tmp;
        return count;
    }

public:
    int InversePairs(vector<int> data) {
        if(data.size() < 2) return -1;
        return doInversePairs(data,0,data.size()-1);
    }
};

int main(int argc, char const *argv[])
{
    Solution so;
    vector<int> data = {1,3,5,2,4,6};
    std::cout << so.InversePairs(data) << std::endl;
    return 0;
}