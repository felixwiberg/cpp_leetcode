#include<string>
#include<iostream>

using namespace std;

class Solution{
    public:
        string longestPalindrome(string s){
            int len = s.size(),
                m = 0,
                start = 0,
                end = 0,
                longest = 0,
                retstart = 0,
                retend = 0;

            if(len == 1){
                return s;
            }

            for(int i = 1; i<(len-1)*2; i++){
                if(i%2==0){
                    m = 1;
                }else{
                    m = 0;
                }
                
                for(int j = 1+m; i+j<=(len-1)*2 & i-j>=0; j+=2){
                    printf("s[i/2]: %c, s[(i-j)/2]: %c, s[(i+j)/2]: %c\n", s[i/2], s[(i-j)/2], s[(i+j)/2]);
                    if(s[(i-j)/2] == s[(i+j)/2]){
                        start = (i-j)/2;
                        end = (i+j)/2;
                        printf("start: %d, end: %d\n", start,end);
                    }else{
                        break;
                    }
                }

                if(end-start > longest){
                    longest = end-start;
                    retstart = start;
                    retend = end;
                }
            }
            return s.substr(retstart, retend-retstart+1);
        }
};

int main(){
    Solution s;
    string str = "abbbj";
    cout << "string: \'" << str << "\'" << endl;
    string ret = s.longestPalindrome(str);
    cout << "returned: \'" << ret << "\'" << endl;
    return 0;
}
