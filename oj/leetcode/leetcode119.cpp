class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        if(rowIndex < 0) return res;

        res.push_back(1);
        if(rowIndex == 0) return res;

        int count = 0;
        vector<int> v1;
        while(count != rowIndex){
            v1.swap(res);
            vector<int>().swap(res);
            res.push_back(1);
            for(int i=0;i<v1.size()-1;i++){
                res.push_back(v1[i]+v1[i+1]);
            }
            res.push_back(1);
            count++;
        }
        return res;
    }
};