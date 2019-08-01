#include<string>
#include<iostream>

using namespace std;

class Solution{
    public:
        string longestPalindrome(string s){
            int len = s.size(),
                c = 0,
                m = 0,
                longest = 0,
                start = 0,
                end = 0,
                retstart = 0,
                retend = 0;

            if(len == 1){
                return s;
            }

            for(int i = 1; i<(len-1)*2; i++){
                c = 0;
                if(i%2==0){
                    c++;
                    m = 1;
                }else{
                    m = 0;
                }
                for(int j = 1+m; i+j<=(len-1)*2 & i-j>=0; j+=2){
                    if(s[(i-j)/2] == s[(i+j)/2]){
                        c++;
                        start = (i-j)/2;
                        end = (i+j)/2;
                    }else{
                        break;
                    }
                }

                if(c > longest){
                    longest = c;
                    retstart = start;
                    retend = end;
                }
            }
            return s.substr(retstart, retend-retstart+1);
        }
};

int main(){
    Solution s;
    string str = "aabbaa";
    cout << "string: \'" << str << "\'" << endl;
    string ret = s.longestPalindrome(str);
    cout << "returned: \'" << ret << "\'" << endl;
    return 0;
}
