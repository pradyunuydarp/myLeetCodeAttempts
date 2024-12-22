#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,r=0;
        int count=0,maxcount=0,usable=k;
        while(r<nums.size()){
            cout<<"it:"<<count<<endl;
            cout<<"l: "<<l<<", nums[l]: "<<nums[l]<<endl;
            cout<<"r: "<<r<<", nums[r]: "<<nums[r]<<endl;
            while(r<nums.size()&&nums[r]==1){
                cout<<"r: "<<r<<", nums[r]: "<<nums[r]<<" ";
                r++;
            }
            cout<<endl;
            cout<<"r: "<<r<<", nums[r]: "<<nums[r]<<endl;
            maxcount = max(r-l,maxcount);
            cout<<"maxcount:"<<maxcount<<endl;
            while(r<nums.size()&&nums[r]==0&&usable>0){
                cout<<"r=0 & usable="<<usable<<" ";
                r++;
                usable--;
            }
            cout<<endl;
            maxcount = max(r-l,maxcount);
            cout<<"maxcount:"<<maxcount<<endl;
            if(r<nums.size()&&usable==0&&nums[r]==0){
                if(nums[l]==0)usable++;
                l++;
            }
            count++;

        }
        return maxcount;
    }
};

int main(){
    Solution s;
    int n[] = {0,0,0,1};
    int k = 4;
    vector<int>nums;
    for(int i= 0; i<4;i++){
        nums.push_back(n[i]);
    }
    cout<<s.longestOnes(nums,k)<<endl;
}