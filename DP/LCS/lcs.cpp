#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
// int lcs(string X, string Y, int m, int n)
// {
//     if (m == 0 or n == 0)
//     {
//         return 0;
//     }

//     if (dp[m][n] != -1)
//     {
//         return dp[m][n];
//     }

//     if (X[m - 1] == Y[n - 1])
//     {
//         return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1);
//     }
//     else
//     {
//         return dp[m][n] = max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
//     }
// }

int lcs(string X, string Y, int m, int n)
{
    int shreya[m + 1][n + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 or j == 0)
            {
                shreya[i][j] = 0;
            }
            else if (X[i - 1] == Y[j - 1])
            {
                shreya[i][j] = 1 + shreya[i - 1][j - 1];
            }
            else
            {
                shreya[i][j] = max(shreya[i - 1][j], shreya[i][j - 1]);
            }
        }
    }

    // Printing LCS
    string res = "";
    int i = m, j = n;
    while (i > 0 and j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            res += X[i - 1];
            i--;
            j--;
        }
        else if (shreya[i - 1][j] > shreya[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(res.begin(), res.end());

    cout << res << endl;

    return shreya[m][n];
}

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
    int m = X.length();
    int n = Y.length();
    memset(dp, -1, sizeof(dp));
    cout << lcs(X, Y, m, n) << endl;
    return 0;
}