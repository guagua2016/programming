#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;


class Solution {
public:
    static bool compare(vector<int>& l,vector<int>& r){
        if(l[1] < r[1] || (l[1] == r[1] && l[0] < r[0])){
            return true;
        }else{
            return false;
        }
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        list<vector<int>> peoples(people.begin(),people.end());
        peoples.sort(compare);
        for(auto it = peoples.begin();it!=peoples.end();){
            int cnt=0;
            auto it2 = peoples.begin();
            for(;it2!=it;++it2){
                if((*it2)[0] >= (*it)[0]){
                    cnt++;
                    if(cnt > (*it)[1]){
                        break;
                    }
                }
            }
            if(cnt > (*it)[1]){
                auto next = ++it;
                auto it_b = --it;
                peoples.insert(it2,*it_b);
                peoples.erase(it_b);

                it = next;
            }else{
                ++it;
            }
        }
        return vector<vector<int>>(peoples.begin(),peoples.end());
    }
};


int main(int argc, char const *argv[])
{
    vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    vector<vector<int>> ret = Solution().reconstructQueue(people);
    std::cout << "hello,world" << std::endl;
    return 0;
}