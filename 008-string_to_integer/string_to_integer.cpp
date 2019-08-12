#include<cstring>
#include<iostream>

using namespace std;

class Solution{
    public:
        int myAtoi(string str){
            bool neg = false;
            unsigned long long ret = 0;
            auto start = str.begin();
            while(start != str.end() && isspace(*start)){start++;}
            if(*start == 45 || *start == 43){
                if(*start == 45){neg = true;}
                start++;
            }
            if(!(48<=*start && *start <= 57)){return 0;}
            while(start != str.end()){
                if(!(48<=*start && *start <= 57)){return neg == true ? -1*ret : ret;}
                ret *= 10; 
                ret += *start - '0';
                start++;
                if(!neg && ret >= 2147483647){return 2147483647;}
                if(neg && ret >= 2147483648){return -2147483648;}
            }
            return neg == true ? -1*ret : ret;
        }
};

int main(){
    Solution s;
    string str = "  -2147483647 hejjjj";
    //string str = " -1";
    //string str = "991283472332";
    //string str = "-91283472332";
    //string str = "    -142 hej";
    int ret = s.myAtoi(str);
    cout << ret << endl;
    return 0;
}
