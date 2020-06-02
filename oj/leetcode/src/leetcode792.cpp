//TLE
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int ret = 0;
        unordered_set<string> pass,out;
        for(string word:words){
            if(pass.count(word)){
                ret++;
                continue;
            }else if(out.count(word)){
                continue;
            }
            int i = 0,j=0;
            while(i < S.size() && j<word.size()){
                if(S[i] == word[j]){
                    i++;
                    j++;
                }else{
                    i++;
                }
            }
            if(j >= word.size()){
                ret++;
                pass.insert(word);
            }else{
                out.insert(word);
            }
        }

        return ret;
       
    }
};