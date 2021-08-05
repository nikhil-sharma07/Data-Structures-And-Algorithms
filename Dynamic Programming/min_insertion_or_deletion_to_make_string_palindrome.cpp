// Given a string s.In one step you can insert any character at any index of the string.

// Return the minimum number of steps to make s palindrome.

// A Palindrome String is one that reads the same backward as well as forward.

// Input: s = "leetcode"
// Output: 5
// Explanation: Inserting 5 characters the string becomes "leetcodocteel".

#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int lps(string &str, int s, int e)
{
    if (s == e)
    {
        return 1;
    }

    if (s > e)
    {
        return 0;
    }

    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }

    if (str[s] == str[e])
    {
        return dp[s][e] = 2 + lps(str, s + 1, e - 1);
    }
    else
    {
        return dp[s][e] = max(lps(str, s, e - 1), lps(str, s + 1, e));
    }
}

int min_insertions(string &str)
{
    memset(dp, -1, sizeof(dp));
    int length_of_longest_palindrome_subsequnce = lps(str, 0, str.length() - 1);
    return str.length() - length_of_longest_palindrome_subsequnce;
}

int main()
{
    string str = "bccba";
    cout << min_insertions(str) << endl;
    return 0;
}