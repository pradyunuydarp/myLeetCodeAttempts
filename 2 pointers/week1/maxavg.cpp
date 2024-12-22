#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <climits>
#include "../../../../../../../Applications/ArmGNUToolchain/13.2.Rel1/arm-none-eabi/arm-none-eabi/include/c++/13.2.1/parallel/numericfwd.h"
using namespace std;
class Solution {
public:
    double summer(int s, int t, vector<int>&nums){
        int sum = 0;
        if(s==t)return (double)(nums[s]);
        else return (double)accumulate(nums.begin()+s,nums.begin()+t+1,0.0);
    }
    double findMaxAverage(vector<int>& nums, int k) {
        double maxavg = INT_MIN;
        int window = min(k-1,(int)nums.size()-1);
        int s=0,t=window;
        double wavg=INT_MIN;
        while(t<nums.size()){
            if(s==0)wavg = (double)summer(s,t,nums);
            else{
                wavg = wavg - nums[s-1] + nums[t];
            }
            maxavg = max(maxavg,(double)(wavg)/(double)k);
            s++;t++;
        }
        return maxavg;
    }
};

int main(){
    Solution s;
    int n[] = {1,12,-5,-6,50,3};
    vector<int>nums;
    for(int i = 0; i<6; i++){
        nums.push_back(n[i]);
    }
    int k = 4;
    cout<<s.findMaxAverage(nums,k)<<endl;

    return 0;
}