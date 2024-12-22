#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
    bool check_prefix(string pfx, string s1, string s2)
    {
        if (s1.length() % pfx.length() || s2.length() % pfx.length())
        {
            return false;
        }
        int x = s1.length() / pfx.length();
        int y = s2.length() / pfx.length();
        string chk1 = "", chk2 = "";
        for (int i = 0; i < x; i++)
        {
            chk1 += pfx;
        }
        for (int i = 0; i < y; i++)
        {
            chk2 += pfx;
        }
        if ((!chk1.compare(s1)) && (!chk2.compare(s2)))
            return true;
        else
            return false;
    }
    string multiplier(string pfx, string s1, string s2)
    {
        string gcd = pfx;
        int x = (s1.length() / pfx.length());
        int y = (s2.length() / pfx.length());
        int k = __gcd(x, y);
        for (int i = 0; i < k - 1; i++)
        {
            gcd += pfx;
        }
        return gcd;
    }
    string gcdOfStrings(string str1, string str2)
    {
        int k = min(str1.length(), str2.length());
        string possible_prefix = "", substr = "";
        int limit = 0;
        for (int i = 0; i < k; i++)
        {
            if (str1.at(i) != str2.at(i))
            {
                return "";
            }
            else
            {
                substr += str1.at(i);
                if (check_prefix(substr, str1, str2))
                {
                    // cout << substr << endl;
                    return multiplier(substr, str1, str2);
                    possible_prefix = substr;
                }
            }
        }
        return possible_prefix;
    }
};
int main()
{
    Solution sol;
    cout << sol.gcdOfStrings("ABABABAB", "ABAB") << endl;
    return 0;
}