#include<cstring>
#include<iostream>

using namespace std;

class Solution{
    public:
        int myAtoi(string str){
            bool neg = false;
            unsigned int ret = 0;
            unsigned int last = 0;
            auto start = str.begin();
            while(start != str.end() && isspace(*start)){
                start++;
            }
            if((int)*start == 45 || (int)*start == 43){
                if((int)*start == 45){
                    neg = true;
                }
                start++;
            }
            if(!(48<=(int)*start && (int)*start <= 57)){
                return 0;
            }
            while(start != str.end()){
                if(!(48<=(int)*start && (int)*start <= 57)){
                    return neg == true ? -1*ret : ret;
                }
                last = ret;
                ret *= 10; 
                ret += *start - '0';
                start++;
                if(ret >= 2147483647){
                    return neg == true ? -2147483648:2147483647;
                }
            }
            return neg == true ? -1*ret : ret;
        }
};

int main(){
    Solution s;
    //string str = "2147483648";
    //string str = " -1";
    //string str = "991283472332";
     string str = "-91283472332"
    //string str = "    -142 hej";
    int ret = s.myAtoi(str);
    cout << ret << endl;
    return 0;
}
