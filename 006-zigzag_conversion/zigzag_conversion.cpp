#include<string>
#include<cstring>
#include<iostream>

using namespace std;

class Solution{
    public:
        string convert(string s, int numRows){
            if(numRows == 1){
                return s;
            }
            
            int len = s.size();
            int dir = -1;
            int row = 0;

            string arr[numRows];
            for(int i = 0; i<len; i++){
                arr[row].push_back(s[i]);
                if(row == numRows-1){
                    dir = -1;
                }
                if(row == 0){
                    dir = 1;
                }
                row += dir;
            }
            string ret;
            for(int j = 0; j<numRows; j++){
                ret += arr[j];
            }
            return ret;
        }
};

int main(){
    Solution s;
    string str = "hejjagheterfelix";
    string ret = s.convert(str, 3);
    cout << ret <<endl;
    return 0;
}
