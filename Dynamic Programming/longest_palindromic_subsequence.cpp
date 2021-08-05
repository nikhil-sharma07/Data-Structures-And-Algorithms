// Given a string s, find the longest palindromic subsequence's length in s.

// A subsequence is a sequence that can be derived from another sequence by deleting some or no elements \
// without changing the order of the remaining elements.

// Input: s = "cbbd"
// Output: 2
// Explanation: One possible longest palindromic subsequence is "bb".

#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int longestPalindromicSubsequence(string &str, int s, int e)
{
    if (s == e)
    {
        return 1;
    }
    if (s > e)
        return 0;

    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }

    if (str[s] == str[e])
    {
        return dp[s][e] = 2 + longestPalindromicSubsequence(str, s + 1, e - 1);
    }
    else
    {
        return dp[s][e] = max(longestPalindromicSubsequence(str, s + 1, e), longestPalindromicSubsequence(str, s, e - 1));
    }
}

int main()
{
    string str = "babbb";
    memset(dp, -1, sizeof(dp));
    cout << longestPalindromicSubsequence(str, 0, str.length() - 1) << endl;
    return 0;
}