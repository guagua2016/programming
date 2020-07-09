#include <vector>
using namespace std;

class Solution
{
public:
  //Insert one char from stringstream
    string str;
    char count[256] = {0};

    void Insert(char ch)
    {
        str.push_back(ch);
        count[ch]++;
         
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {   
        int n = str.size();
        for(int i=0;i<n;i++){
            if(count[str[i]] == 1){
                return str[i];
            }
        }
        return '#';
    }
};