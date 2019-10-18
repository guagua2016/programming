#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxCon = 0;
        int con=0;
        int n = seats.size();

        int start_index = -1;
        for(int i=0;i<n;i++){
            if(seats[i] == 0){
                con++;
            }else{
                if(con > maxCon){
                    start_index = i - con;
                    if(start_index == 0){
                        maxCon = (maxCon,con * 2);
                    }else{
                        maxCon = max(maxCon,con);
                    }
                }
                con = 0;
            }
        }
        if(seats[n-1] == 0){
            maxCon = max(maxCon,con*2);
        }
        return (maxCon + 1)/2;
        
    }
};


int main(int argc, char const *argv[])
{
    vector<int> v = {0,1,1,1,0,0,1,0,0};
    Solution so;
    std::cout << so.maxDistToClosest(v) << std::endl;
    return 0;
}