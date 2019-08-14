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
            int array[n];
            for(int i = n-1; i>=0; i--){
                array[i] = x%10;
                x /= 10;
            }
            for(int i = 0; i<n/2; i++){
                if(!(array[i] == array[n-i-1])){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    Solution s;
    int x = 11011;
    bool ret = s.isPalindrome(x);
    cout << "palindrome? : " << ret << endl;
    return 0;
}
