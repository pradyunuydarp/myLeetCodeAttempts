#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int bin_search(vector<int>&nums,int l, int r, int x,vector<bool>&visited){
        cout<<"l: "<<l<<"r :"<<r<<" n[l]-k: "<<x<<endl;
        if(l<0||r>nums.size())return -1;
        int m = (r-l)/2;
        cout<<"m: "<<m<<endl;
        if(l>r) return -1;
        // cout<<"hey";
        if(nums[l]==x && visited[l]==false)return l;
        if(nums[r]==x && visited[r]==false)return r;
        if(nums[m]==x && visited[m]==false)return m;
        else if(x>nums[m]){
            return bin_search(nums,m+1,r-1,x,visited); 
        }
        else{
            return bin_search(nums,l+1,m-1,x,visited);
        }
    }
    int maxOperations(vector<int>& nums, int k) {
        // int l = 0; r = nums.size()-1,count=0;
        // while(l<r){
        //     while(nums[l]>k)l++;
        //     while(nums[r]>k)r--;
        //     if(l<r){

        //     }
        // }
        cout<<"k-"<<k<<endl;
        sort(nums.begin(),nums.end());
        for(int i = 0; i<nums.size(); i++)cout<<nums[i]<<" ";
        cout<<endl;
        long long l = 0, r = nums.size()-1,count=0,p=-1;
        vector<bool>visited(nums.size(),false);
        while(l<nums.size()){
            cout<<"l:"<<l<<"numsl: "<<nums[l]<<endl;
            if((!visited[l]) && nums[l]<=k){

                int p = bin_search(nums,l+1,r,k-nums[l],visited);
                cout<<"p: "<<p<<endl;
                if(p!=-1&&p!=l){
                    count++;
                    cout<<"count: "<<count<<endl;
                    visited[l] = true; visited[p] = true;
                }
            }
            l++;
        }
        return count;

    }
};


int main(){
    int numbs[] = {3,1,3,4,3};
    int k = 6;
    vector<int>nums;
    for(int i = 0; i<5; i++){
        nums.push_back(numbs[i]);
    }
    Solution s;
    s.maxOperations(nums,k);
}