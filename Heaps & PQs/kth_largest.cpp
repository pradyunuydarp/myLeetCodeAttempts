#include "../import.h"
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>Q;
        for(auto i: nums){
            Q.push(i);
        }
        int ans = 0;
        int j = 0;
        for(; j<k && (!Q.empty()); j++){
            if(j==k-1){
                ans = Q.top();
            }
            Q.pop();
        }
        return ans;

    }
};