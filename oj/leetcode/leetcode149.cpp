class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n < 3) return n;
        int res = 2;
        int count = 0;
        for(int i=0;i<n;i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            int duplicate = 1;
            for(int j=i+1;j<n;j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if (x1 == x2 && y1 == y2) {++duplicate; continue;}
                
                count = 0;
                for(int k = 0;k<n;k++){
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    long l1 = long((y3-y2))*long((x2-x1));
                    long l2 = long((y2-y1))*long((x3-x2));
                    if(l2 == l1){
                        count++;
                    }
                }
                res = max(count,res);
            }
            res = max(res,duplicate);
        }
        return res;
    }
};