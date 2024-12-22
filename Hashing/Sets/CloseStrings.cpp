#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        // unordered_map<char,int>m1,m2;vector<int>v,v2;
        // unordered_map<int,int>counter;
        // int n1 = (int)word1.length(),n2= (int)word2.length();
        // if(n1!=n2)return false;
        // for(int i = 0; i<n1; i++){
        //     m1[word1.at(i)]=0;
        // }
        // for(int i = 0; i<n1; i++){
        //     m1[word1.at(i)]++;
        // }
        // for(auto it = m1.begin(); it!=m1.end(); it++){
        //     v.push_back(it->second);
        // }
        // for(int i = 0; i<n2; i++){
        //     m2[word2.at(i)]=0;
        // }
        // for(int i = 0; i<n2; i++){
        //     m2[word2.at(i)]++;
        // }
        // int m = v.size();
        // for(int i = 0; i<m; i++){
        //     counter[v[i]]=0;
        // }
        // for(int i = 0; i<m; i++){
        //     counter[v[i]]++;
        // }
        // for(auto it = m2.begin(); it!=m2.end(); it++){
        //     v2.push_back(it->second);
        // }
        // int mv2 = v2.size();
        // for(int i = 0; i<mv2; i++){
        //     if(counter.find(v2[i])==counter.end())return false;
        //     counter[v2[i]]--;
        // }
        // for(int i = 0; i<m; i++){
        //     if(counter[v[i]]!=0)return false;
        // }
        // return true;
        unordered_map<char,int>m1,m2;
        unordered_map<int,int>m3,m4;
        for(int i =0 ;i<word1.length(); i++){
            m1[word1.at(i)]=0;
        }
        for(int i =0 ;i<word1.length(); i++){
            m1[word1.at(i)]++;
            cout<<word1.at(i)<<m1[word1.at(i)]<<endl;
        }
        for(int i =0 ;i<word1.length(); i++){
            m3[m1[word1.at(i)]]=0;
        }
        for(int i =0 ;i<word1.length(); i++){
            m3[m1[word1.at(i)]]++;
            
        }

        for(int i =0 ;i<word2.length(); i++){
            m2[word2.at(i)]=0;
        }
        for(int i =0 ;i<word2.length(); i++){
            m2[word2.at(i)]++;
            cout<<word2.at(i)<<m2[word2.at(i)]<<endl;
        }
        for(int i =0 ;i<word2.length(); i++){
            m4[m2[word2.at(i)]]=0;
        }
        for(int i =0 ;i<word2.length(); i++){
            m4[m2[word2.at(i)]]++;
        }
        for(auto i = m1.begin(); i!=m1.end(); i++){
            if(m2.find(i->first)==m2.end())return false;
            if(m3.find(i->second)!=m4.find(i->second))return false;
        }
        return true;

    }
};
int main(){
    Solution s;
    s.closeStrings("abc","bca");
}