class Solution{
public:
    vector<int> findOrder(int numCourses,vector<pair<int,int>>& prerequisites){
        vector<int> res;

        vector<int> in_degree(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(auto p : prerequisites){
            in_degree[p.first]++;
            graph[p.second].push_back(p.first);
        }

        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(in_degree[i] == 0)
                q.push(i);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            res.push_back(cur);
            for(auto it = graph[cur].begin();it != graph[cur].end();it++){
                if(--in_degree[*it] == 0)
                    q.push(*it);
            }
        }
        if(res.size() == numCourses)
            return res;
        else
            return vector<int>();
    }
};
