#include <vector>
#include <iostream>
using namespace std;


//TLE
class Solution1 {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        if(informTime[headID] == 0) return 0;
        int res = 0;
        for(int i=0;i<manager.size();i++){
            int t = 0;
            if(manager[i] == headID){
                std::cout << i << std::endl;
                t = numOfMinutes(n,i,manager,informTime) + informTime[headID];  
                res = max(res,t);
            }
        }
        
       return res;
    }
};

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> m(n);//manager_id,subordinations
        // vector<vector<int>> m;
        for(int i=0;i<manager.size();i++){
            m[manager[i]].push_back(i);
        }
        return dfs(headID,m,informTime);
    }
    
    int dfs(int headID,vector<vector<int>>&m,vector<int>& informTime){
        if(informTime[headID] == 0) return 0;
        int res = 0;
        for(int id : m[headID]){
            res = max(dfs(id,m,informTime)+informTime[headID],res);
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    int n = 11;
    int headID = 4; 
    vector<int> manager = {5,9,6,10,-1,8,9,1,9,3,4};
    vector<int> informTime = {0,213,0,253,686,170,975,0,261,309,337};
    std::cout << Solution().numOfMinutes(n,headID,manager,informTime) << std::endl;
    return 0;
}
