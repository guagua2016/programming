class Solution {
public:
 
    static bool compare(vector<int>& a,vector<int>& b){
        return a[1] > b[1];
    }
        
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        vector<vector<int>> workers;
        for(int i=0;i<n;i++){
            workers.push_back(vector<int>{speed[i],efficiency[i]});   
        }
        sort(workers.begin(),workers.end(),compare);
        
        priority_queue<int,vector<int>,greater<int>> minHeap;
        long total = 0;
        long minE;
        long res = 0;
        for(int i=0;i<k;i++){
            total += workers[i][0];
            minE = workers[i][1];
            res = max(res,total*minE);
            minHeap.push(workers[i][0]);
        }
        
        for(int i=k;i<n;i++){
            if(workers[i][0] > minHeap.top()){
                minE = workers[i][1];
                total += (workers[i][0] - minHeap.top());
                res = max(res,total * minE);
                minHeap.pop();
                minHeap.push(workers[i][0]);
            }
        }
        
        return res % 1000000007;
    }
};