#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mymap;
        // char check_char = ;
        int l=0,len=0;
        for(int i = 0; i < s.length(); i++ ){
            printf("l-%d",l);
            auto it = mymap.find(s.at(i));
            if(it==mymap.end()){
                printf("notfound:%c\n",s.at(i));
                mymap[s.at(i)]=i;
            }
            else{
                if(l<=it->second){
                    printf("found:%c\n",it->first);
                    l = it->second+1;
                    printf("l-%d",l);
                }
                it->second = i;
            }
            printf("%c,l:%d,i:%d,len:%d\n",s.at(i),l,i,len);
            len = max(len,i-l+1);
            printf("%c,l:%d,i:%d,len:%d\n",s.at(i),l,i,len);
        }
        return len;
    }
};
int main(){
    string s = "abba";
    Solution* sol = new Solution();
    int n = sol->lengthOfLongestSubstring(s);
    if(n==2){
        printf("SUCCESS\n");
        return 0;
    }
    printf("%d\n",n);
    return 1;
}