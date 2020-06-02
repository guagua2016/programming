#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> res;
        multiset<int> st(A.begin(), A.end());
        for (int i = 0; i < B.size(); ++i) {
            auto it = (*st.rbegin() <= B[i]) ? st.begin() : st.upper_bound(B[i]);
            res.push_back(*it);
            st.erase(it);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    vector<int> A = {2,7,11,15};
    vector<int> B = {1,10,4,11};
    Solution so;
    vector<int> ret = so.advantageCount(A,B);
    for(int r : ret){
        std::cout << r << ",";
    }
    std::cout << std::endl;
    return 0;
}