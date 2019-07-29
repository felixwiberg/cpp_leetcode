#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            printf("target: %d\n", target);
            vector<int> res = {0,0};
            for(int i = 0; i < nums.size(); i++){
                for(int j = i+1; j < nums.size(); j++){
                    printf("nums[i]: %d, nums[j]: %d\n", nums[i], nums[j]);
                    if(nums[i]+nums[j] == target){
                        res[0] = i;
                        res[1] = j;
                    }
                }
            }
            return res;
        }
};

int main() { 
    Solution sol;
    vector<int> input = {1,2,3,4,5};
    auto res = sol.twoSum(input, 9);
    printf("res: %d and %d\n", res[0], res[1]);
    return 0;
}
