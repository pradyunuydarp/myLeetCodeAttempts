#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       double m = median_two_sorted_arrays(nums1,0,nums1.size()-1,nums2,0,nums2.size()-1);
       return m;
    }
    double median_two_sorted_arrays(vector<int>&nums1,int l1,int r1,vector<int>&nums2,int l2,int r2){
        // int mid1 = (r1-l1)/2;
        printf("l1:%dr1:%dl2:%dr2:%d\n",l1,r1,l2,r2);
        double med1,med2;
        int m1 = (r1-l1)/2 ;
        int m2 = (r2-l2)/2 ;
        printf("m1%d,m2%d,A[m1]%d,B[m2]%d\n",m1,m2,nums1[m1],nums2[m2]);
        if(((r1-l1)%2)){
            med1 = (double)(nums1[m1]+nums1[m1+1])/2;
            printf(" %d ",med1); 
        }
        else{
            med1 = nums1[m1];
            printf(" %d ",med1);
        }
        if(((r2-l2)%2)){
            med2 = (double)(nums2[m2]+nums2[m2+1])/2;
            printf(" %d ",med2);
        }
        else{
            med2 = nums1[m2];
            printf(" %d ",med2);
        }
        // int mid2 = (r2-l2)/2;
        // if(nums1[mid1]==nums2[mid1]) return nums1[mid1];
        if(med1==med2) return med1;
        else if(med1<med2){
            return median_two_sorted_arrays(nums1,m1+1,r1,nums2,l2,r2);
        }
        else{
           return median_two_sorted_arrays(nums1,l1,r1,nums2,m2+1,r2); 
        }
    } 
};
int main(){
    vector<int>nums1; nums1.push_back(1);nums1.push_back(3);
    vector<int>nums2; nums2.push_back(2);
    Solution sol;
    double m = sol.findMedianSortedArrays(nums1,nums2);
    printf("m:%f",m);
    if((int)m==2){
        printf("SUCCESS\n");
        return 0;
    }
    return 1;
}