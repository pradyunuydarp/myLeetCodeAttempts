#include "../../import.h"
class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = l + (r-l)/2;
            if(nums[m]==t)return m;
            if(nums[l]<=nums[m]){
                if(nums[l]<=t && t<=nums[m]){
                    r = m-1;
                }
                else{
                    l = m+1;
                }
            }
            if(nums[r]>=nums[m]){
                if(nums[r]>=t && t>=nums[m]){
                    l = m+1;
                }
                else{
                    r = m-1;
                }
            }
        }
        return -1;
    }
};