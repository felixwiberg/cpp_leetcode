#include<vector>
#include<iostream>
#include<iterator>
#include<cmath>

using namespace std;

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            double ret = 0;
            int len1 = nums1.size(), 
                len2 = nums2.size(),
                i = 0,
                j = 0,
                k = 0;
            vector<int> merged(len1+len2, 0);
            while(i < len1 || j < len2){
                if(nums1[i] > nums2[j]){
                    merged[k++] = nums1[i];
                    i++;
                }else{
                    merged[k++] = nums2[j];
                    j++;
                }
            }

    
            copy(merged.begin(), merged.end(), ostream_iterator<int>(cout,","));
            cout << endl;
            cout << "l1 + l2: " << len1+len2 << endl;
            if((len1 + len2) % 2 == 0){
                return (merged[(len1 + len2)/2-1] + merged[(len1 + len2)/2])/2.0;
            }else{
                return merged[(len1 + len2 - 1)/2];
            }
        }
};

int main(){
    vector<int> nums1 = {10};
    vector<int> nums2 = {12};
    Solution s;
    double ret = s.findMedianSortedArrays(nums1, nums2);
    cout << "the median of ";
    copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout,","));
    cout << " and ";
    copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout,","));
    cout << " is: " << ret << endl;
    return 0;
}
