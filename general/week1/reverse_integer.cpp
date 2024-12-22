#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int reverse_str(int x) {
        int r = 0,n=10,x1=x,d1=0;
        int r = 0,n=10,x1=abs(x),d1=0;
       string int_str = to_string(x);
       string rev_str = reverse(int_str.begin(),int_str.end());
       string max_str = to_string(INT_MAX);
    //    int numdigs = int_str.length();
        if(strcmp(rev_str,max_str))>0)return 0;
        while(x1>0){
            d1 = x1%n;
            r = (r*n)+d1;
            x1/=n;
            printf("%d,%d,%d\n",d1,r,x1);
        }
        return r;
    }
};
int main(){
    Solution sol;
    printf("%d\n",sol.reverse(123));
    return 0;
}