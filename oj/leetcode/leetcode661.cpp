class Solution {
public:
    int smooth(vector<vector<int>>& M,int x,int y){
        int sum = M[x][y];
        int count =1;
        int rows = M.size();
        int cols = M[0].size();
        if(x - 1 >=0){
            sum += M[x-1][y];
            count++;
        }

        if(x + 1 < rows){
            sum+= M[x+1][y];
            count++;
        }

        if(y-1>=0){
            sum+=M[x][y-1];
            count++;
        }

        if(y+1<cols){
            sum+=M[x][y+1];
            count++;
        }

        if(x-1>=0 && y-1>=0){
            sum+=M[x-1][y-1];
            count++;
        }

        if(x+1<rows && y-1>=0){
            sum+=M[x+1][y-1];
            count++;
        }
        if(x-1>=0 && y+1<cols){
            sum+=M[x-1][y+1];
            count++;
        }
        if(x+1<rows && y+1<cols){
            sum+=M[x+1][y+1];
            count++;
        }

        return sum/count;
    }


    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int rows = M.size();
        if(rows == 0) return vector<vector<int>>(0,vector<int>());
        int cols = M[0].size();
        vector<vector<int>> ret = vector<vector<int>>(row,vector<int>(cols,0));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ret[i][j] = smooth(M,i,j);
            }
        }
        return ret;

    }
};