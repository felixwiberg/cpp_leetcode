#include<iostream>
#include<cmath>

using namespace std;

class Solution {
    public:
        bool isPalindrome(int x){
            if(x<0){return false;}
            int z = x;
            unsigned int y = 0;
            if(x/(int)pow(10, n-1) - x%10 != 0){return false;}
            while(x){
                y = y*10 + x%10;
                x /= 10;
            }
            return z == y? true:false;
        }
};

int main(){
    Solution s;
    int x = 2147447412;
    bool ret = s.isPalindrome(x);
    cout << "palindrome? : " << ret << endl;
    return 0;
}
