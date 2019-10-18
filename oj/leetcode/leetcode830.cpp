class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ret;
        int len = S.length();

        int start = 0;
        int i = 1;
        while(start != len){
            if(S[i] == S[start]){
                i++;
            }else{
                if(i-start >=3){
                    ret.push_back(vector<int>{start,i-1});
                }
                start = i;
            }
        }
        return ret;
    }
};