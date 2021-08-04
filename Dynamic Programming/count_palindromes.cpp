// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

#include <bits/stdc++.h>
using namespace std;

// bool isPalindrome(string &str, int s, int e)
// {
//     while (s < e)
//     {
//         if (str[s] != str[e])
//         {
//             return false;
//         }
//         s++;
//         e--;
//     }

//     return true;
// }

// int dp[1001][1001];
// int count_palindromes(string &str, int s, int e)
// {
//     if (s == e)
//     {
//         return 1;
//     }

//     if (s > e)
//     {
//         return 0;
//     }

//     if (dp[s][e] != -1)
//     {
//         return dp[s][e];
//     }

//     if (isPalindrome(str, s, e))
//     {
//         return dp[s][e] = 1 + count_palindromes(str, s + 1, e) + count_palindromes(str, s, e - 1) - count_palindromes(str, s + 1, e - 1);
//     }
//     else
//     {
//         return dp[s][e] = count_palindromes(str, s + 1, e) + count_palindromes(str, s, e - 1) - count_palindromes(str, s + 1, e - 1);
//     }
// }

//Bottom-Up DP
int count_palindromes(string str)
{
    int n = str.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (str[i] == str[j] and dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j])
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int main()
{
    string str = "abba";
    // memset(dp, -1, sizeof(dp));
    // cout << count_palindromes(str, 0, str.length() - 1) << endl;
    cout << count_palindromes(str) << endl;
    return 0;
}