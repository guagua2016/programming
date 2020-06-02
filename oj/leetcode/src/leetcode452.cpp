#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;




bool compare(vector<int>& a,vector<int>& b){
    if(a[0] < a[0]){
        return true;
    }else if(a[0] > a[0]){
        return false;
    }else{
        return a[1] <= b[1]; 
    }
}


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() < 2) return points.size();

        sort(points.begin(),points.end(),compare);

        vector<int> interArea = points[0];
        int ret = 0;
        int i = 0;
        while(i < points.size()){
            if(points[i][0] > interArea[1]){
                ret++;
                interArea = points[i];
                i++;
            }else{
                interArea[0] = points[i][0];
                i++;
            }
        }
        return ret + 1;
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> points = {{10,16},{2,8},{1,6},{7,12}};
    sort(points.begin(),points.end(),compare);
    std::cout << Solution().findMinArrowShots(points) << std::endl;



    std::cout << "dsaf" << std::endl;

    return 0;
}