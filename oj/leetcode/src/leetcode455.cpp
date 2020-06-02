#include <algorithm>
#include <vector>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int n1 = g.size();
        int n2 = s.size();

        int p1 = 0;
        int p2 = 0;

        int ret = 0;
        while(p1 < n1 && p2 < n2){
            if(s[p2] >= g[p1]){
                p2++;
                p1++;
                ret++;
            }else{
                p2++;
            }
        }

        return ret;
        
    }
};