#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s){
            
            if(s.length() == 1){return 1;}
            if(s.length() == 2 && s[0] != s[1]){return 2;}

            vector<int> ascii(128, 0);
            int tmp_sum = 0, longest_substring = 0;

            for(int i = 0; i<s.length(); i++){
                for(int j = i; j<s.length(); j++){
                    if(ascii[s[j]] == 0){
                        ascii[s[j]] = 1;
                        tmp_sum += 1;
                    }else{
                        if(tmp_sum > longest_substring){ longest_substring = tmp_sum; }
                        tmp_sum = 0;
                        j = 128;
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
    string str = "bb";
    int ret = s.lengthOfLongestSubstring(str);
    cout << "Longest substring in " << str << " is: " << ret << endl;
    return 0;
}

