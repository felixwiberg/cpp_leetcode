#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s){ 
            vector<int> ascii(128, 0);
            int tmp_sum = 0, longest_substring = 0, len = s.length();
            if(len==1){return 1;}
            for(int i = 0; i<len; i++){
                for(int j = i; j<len; j++){
                    if(ascii[s[j]] == 0){
                        ascii[s[j]] = 1;
                        tmp_sum += 1;
                    }else{
                        if(tmp_sum > longest_substring){ longest_substring = tmp_sum; }
                        tmp_sum = 0;
                        fill(ascii.begin(), ascii.end(), 0);
                        break;
                    }
                }
            }
            return longest_substring;
        }
};

int main(){
    Solution s;
    string str = "a";
    int ret = s.lengthOfLongestSubstring(str);
    cout << "Longest substring in " << str << " is: " << ret << endl;
    return 0;
}

