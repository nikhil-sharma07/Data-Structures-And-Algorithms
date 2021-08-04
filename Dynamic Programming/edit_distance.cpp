// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character

// Input: word1 = "horse", word2 = "ros"
// Output: 3
// Explanation:
// horse -> rorse (replace 'h' with 'r')
// rorse -> rose (remove 'r')
// rose -> ros (remove 'e')

#include <bits/stdc++.h>
using namespace std;

int dp[501][501];
int minDist(string word1, string word2, int m, int n)
{
    if (m == 0)
    {
        return n;
    }

    if (n == 0)
    {
        return m;
    }

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }

    if (word1[m - 1] == word2[n - 1])
    {
        return dp[m][n] = minDist(word1, word2, m - 1, n - 1);
    }
    else
    {
        return dp[m][n] = 1 + min(minDist(word1, word2, m, n - 1), min(minDist(word1, word2, m - 1, n), minDist(word1, word2, m - 1, n - 1)));
    }
}

int minDistance(string word1, string word2)
{
    int m = word1.length();
    int n = word2.length();
    memset(dp, -1, sizeof(dp));
    return minDist(word1, word2, m, n);
}

int main()
{
    string word1 = "horse";
    string word2 = "ros";
    int res = minDistance(word1, word2);
    cout << res << endl;
    return 0;
}