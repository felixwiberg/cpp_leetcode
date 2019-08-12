#include<cstring>
#include<iostream>

using namespace std;

class Solution{
    public:
        int myAtoi(string str){
            bool neg = false;
            int ret = 0;
            auto start = str.begin();
            while(start != str.end() && isspace(*start)){
                start++;
            }
            if((int)*start == 45){
                start++;
                neg = true;
            }
            if(!(48<=(int)*start && (int)*start <= 57)){
                return 0;
            }
            while(start != str.end()){
                if(!(48<=(int)*start && (int)*start <= 57)){
                    return neg == true ? -1*ret : ret;
                }
                ret *= 10; 
                ret += *start - '0';
                cout << "start: " << *start << endl;
                cout << "ret: " << ret << endl;
                start++;
            }
            return neg == true ? -1*ret : ret;
        }
};

int main(){
    Solution s;
    string str = "    -142 hej";
    int ret = s.myAtoi(str);
    cout << ret << endl;
    return 0;
}
