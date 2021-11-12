#include <bits/stdc++.h>
using namespace std;

map<string, bool> mp;

bool mcm(string s1, string s2)
{
    if (s1 == s2)
        return true;

    int n = s1.length();
    if (n <= 1)
        return false;
    // why we are taking the equal case as well? This is because if the string length is of 1, then s1 and s2 should be equal. And this condition is already checked in the first condition.

    string key = s1 + " " + s2;
    if (mp.find(key) != mp.end())
        return mp[key];

    string s1l, s1r, s2l, s2r;
    for (int i = 1; i < n; i++) // here i represents the length that is why we have started i from 1 to n
    {
        s1l = s1.substr(0, i);
        s1r = s1.substr(n - i, i);
        s2l = s2.substr(0, i);
        s2r = s2.substr(n - i, i);

        if (mcm(s1l, s2r) and mcm(s1r, s2l)) // if the swap is happening
            return true;
        else if (mcm(s1l, s2l) and mcm(s1r, s2r)) // if the swap is not happening
            return true;
    }
    return mp[key] = false;
}

int main()
{
    // string s1 = "great", s2 = "eatrg";
    string s1 = "abcde", s2 = "caebd";

    s1.length() != s2.length() ? cout << 0 : cout << mcm(s1, s2);

    return 0;
}