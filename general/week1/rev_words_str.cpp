#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        char word[10000];
        string retstr = "";
        int wordlength = -1;
        for(int i = s.length()-1,k=0; i>=0;k=0){
                while(i>=0 && s.at(i)==' '){
                    i--;
                }
                while(i>=0 && s.at(i)!=' '){
                    word[k] = s.at(i);
                    cout<<word[k];
                    k++;i--;
                }
                cout<<endl;
                wordlength = --k;
                while(k>=0){
                    retstr+=word[k];
                    k--;
                }
                while(i>=0 && s.at(i)==' '){
                    i--;
                }
                if(i>=0 && wordlength>=0)retstr+=' ';
        }
        return retstr;
    }
};

int main(){
    Solution s;
    cout<<"{"<<s.reverseWords("F R  I   E    N     D      S      ")<<"}"<<endl;
    return 0;
}