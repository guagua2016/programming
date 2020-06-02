#include <unordered_map>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>> m;        
        for(auto edge : edges){
            int from = min(edge[0],edge[1]);
            int to = max(edge[0],edge[1]);
            m[from].push_back(to);  
        }
        double res = 0.0;
        dfs(m,t,target,1,1.0,res);
        return res;
    }
    
    void dfs(unordered_map<int,vector<int>>&m,int t,int target,int curVertex,double curPro,double& res){
        if(t == 0){
            if(curVertex == target){
                res = curPro;
            }
            return;
        }

        if(m[curVertex].empty()){
            dfs(m,t-1,target,curVertex,curPro,res);
        }else{
            curPro = curPro * 1.0/m[curVertex].size();
            for(auto vertex : m[curVertex]){
                dfs(m,t-1,target,vertex,curPro,res);
            }
        }
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> edges = {{2,1},{3,2},{4,1}};
    std::cout << Solution().frogPosition(4,edges,4,1) << std::endl;
    return 0;
}
