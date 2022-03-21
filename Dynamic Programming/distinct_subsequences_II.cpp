#include <bits/stdc++.h>
using namespace std;

int distinctSubseqII(string s)
{
    int n = s.size();
    int shreya[n + 1];
    shreya[0] = 1;
    unordered_map<char, int> mp;
    for (int i = 1; i <= n; i++)
    {
        shreya[i] = 2 * shreya[i - 1];
        if (mp.find(s[i - 1]) != mp.end())
        {
            shreya[i] = shreya[i] - shreya[mp[s[i - 1]] - 1];
        }
        mp[s[i - 1]] = i;
    }

    return shreya[n] - 1;
}

int main()
{
    string s = "aba";
    cout << distinctSubseqII(s) << endl;
    return 0;
}

//  1 0 0 1 1 1 0 1
//  2 4 5 8 11 14 24

""
    "1"
    "0"
    "10"
    "100"
    "11"
    "101"
    "1001"

    "1"
    "11"
    "01"
    "101"
    "1001"
    "111"
    "1011"
    "10011"
