#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0,j=0,cnt=0,n=nums.size();
        for(;i<n;i++){
            while(i<n && nums.at(i)!=0)i++;
            if(i<n){
                if(nums.at(i)==0)cnt++;
                j = i+1;
                while(j<n && nums.at(j)==0)j++;
                for(int p = 0; j+p<n; p++){
                    if(nums.at(j+p)!=0){
                        nums.at(i+p) = nums.at(j+p);
                        nums.at(j+p)=0;
                    }
                    else{
                        cnt++;
                    }
                }
            }
            else return;
        }

    }
};

int main(){
    Solution s;
    vector<int>nums;
    // [0,1,0,3,12]
    // int b[] = {0,1,0,3,12};
    int b[]={1};
    for(int i = 0; i<1; i++){
        nums.push_back(b[i]);
    }
    s.moveZeroes(nums);
    for(int i = 0; i<1; i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}