class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int res=0;
        
        int m = grid.size(),n = grid[0].size();
        queue<pair<int,int>> q1;
        queue<pair<int,int>> q2;
        q1.push({0,0});
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        while(!q1.empty()){
    
            while(!q1.empty()){
                int curX = q1.front().first;
                int curY = q1.front().second;
                q1.pop();
                if(curX<0 || curX>=m || curY<0 || curY>=n || visited[curX][curY]) continue;
                visited[curX][curY] = true;
                if (curX == m-1 && curY == n-1){
                    return res;
                }
   
                int cost = 0;
                for(auto dir : dirs){
                    if (grid[curX][curY] == 1 && dir[0] == 0 && dir[1] == 1) cost = 0;
                    else if (grid[curX][curY] == 2 && dir[0] == 0 && dir[1] == -1) cost = 0;
                    else if (grid[curX][curY] == 3 && dir[0] == 1 && dir[1] == 0) cost = 0;
                    else if (grid[curX][curY] == 4 && dir[0] == -1 && dir[1] == 0) cost = 0;
                    else cost = 1;
                    if(cost == 0){
                        q1.push({curX+dir[0],curY+dir[1]});
                    }else{
                        q2.push({curX+dir[0],curY+dir[1]});
                    } 
                }
            }
            res++;
            swap(q1,q2);
        }
        return res;
    }
    
};