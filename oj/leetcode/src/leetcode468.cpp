#include <string>
#include <sstream> //stringstream
#include <cctype>  //isalnum
using namespace std;


class Solution {
public:

    bool isValidIPv4Block(string& block){
        int num = 0;
        if(block.size() > 0 && block.size() <= 3){
            for(int i=0;i<block.size();i++){
                if(!isalnum(block[i]) || (i==0 && block[i]=='0' && block.size() > 1)){
                    return false;
                }
                num = num * 10 + block[i] - '0';
            }
            return num <= 255;
        }
        return false;
    }

    bool isValidIPv6Block(string& block){
        const string validIPv6Chars = "0123456789abcdefABCDEF";
        if(block.size()>0 && block.size() <=4){
            for(int i=0;i<block.size();i++){
                if(validIPv6Chars.find(block[i]) == string::npos){
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    string validIPAddress(string IP) {
        stringstream ss(IP);
        string ans[] = {"IPv4","IPv6","Neither"};

        string block;
        if(IP.substr(0,4).find('.') != string::npos){
            for(int i=0;i<4;i++){
                if(!getline(ss,block,'.') || !isValidIPv4Block(block)){
                    return ans[2];
                }
            }
            return ss.eof()?ans[0]:ans[2];

        }else if(IP.substr(0,5).find(':' != string::npos)){
            for(int i=0;i<8;i++){
                if(!getline(ss,block,':') || !isValidIPv6Block(block)){
                    return ans[2];
                }
            }
            return ss.eof()?ans[1]:ans[2];

        }

        return ans[2];
    }
};

int main(int argc, char const *argv[])
{
    string ip = "172.16.254.01";
    Solution().validIPAddress(ip);
    return 0;
}