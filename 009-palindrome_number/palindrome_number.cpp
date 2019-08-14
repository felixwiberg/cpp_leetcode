#include<iostream>
#include<cmath>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x){
            if(x < 0){ return false; }
            if(x < 10 && x >= 0){ return true; }
            int c = x;
            int n = 0;
            while(c > 0){
                c /= 10;
                n++;
            }
            while(x>10){
                if(x/(int)pow(10, n-1) - x%10 == 0){
                    x -= x/(int)pow(10, n-1)*(int)pow(10, n-1);
                    x /= 10;
                    n -= 2;
                }else{
                    return false;
                }
            }
            return true;
        }
};

int main(){
    Solution s;
    int x = 99;
    bool ret = s.isPalindrome(x);
    cout << "palindrome? : " << ret << endl;
    return 0;
}
