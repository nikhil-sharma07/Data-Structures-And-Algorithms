// The chess knight has a unique movement, it may move two squares vertically and one square horizontally,
// or two squares horizontally and one square vertically(with both forming the shape of an L).
// We have a chess knight and a phone pad as shown below, the knight can only stand on a numeric cell.
// Given an integer n, return how many distinct phone numbers of length n we can dial.

// You are allowed to place the knight on any numeric cell initially and then you should perform n - 1 jumps to dial a number of length n. All jumps should be valid knight jumps.

// As the answer may be very large, return the answer modulo 109 + 7.

// Input: n = 4
// Output: 104

#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

bool isValid(int mat[4][3], int i, int j)
{
    if (i < 0 or j < 0 or i > 3 or j > 2 or mat[i][j] == -1)
    {
        return false;
    }
    return true;
}

int dp[5][5][5001];
int func(int mat[4][3], int i, int j, int n)
{
    if (n == 0)
    {
        return 1;
    }

    if (dp[i][j][n] != -1)
    {
        return dp[i][j][n];
    }

    int cnt = 0;
    if (isValid(mat, i - 2, j - 1))
    {
        cnt = (cnt % mod + func(mat, i - 2, j - 1, n - 1) % mod) % mod;
    }

    if (isValid(mat, i - 2, j + 1))
    {
        cnt = (cnt % mod + func(mat, i - 2, j + 1, n - 1) % mod) % mod;
    }

    if (isValid(mat, i + 2, j - 1))
    {
        cnt = (cnt % mod + func(mat, i + 2, j - 1, n - 1) % mod) % mod;
    }

    if (isValid(mat, i + 2, j + 1))
    {
        cnt = (cnt % mod + func(mat, i + 2, j + 1, n - 1) % mod) % mod;
    }

    if (isValid(mat, i - 1, j - 2))
    {
        cnt = (cnt % mod + func(mat, i - 1, j - 2, n - 1) % mod) % mod;
    }

    if (isValid(mat, i - 1, j + 2))
    {
        cnt = (cnt % mod + func(mat, i - 1, j + 2, n - 1) % mod) % mod;
    }

    if (isValid(mat, i + 1, j - 2))
    {
        cnt = (cnt % mod + func(mat, i + 1, j - 2, n - 1) % mod) % mod;
    }

    if (isValid(mat, i + 1, j + 2))
    {
        cnt = (cnt % mod + func(mat, i + 1, j + 2, n - 1) % mod) % mod;
    }

    return dp[i][j][n] = cnt;
}

int knightDialer(int n)
{
    int mat[4][3];
    mat[0][0] = 1;
    mat[0][1] = 2;
    mat[0][2] = 3;
    mat[1][0] = 4;
    mat[1][1] = 5;
    mat[1][2] = 6;
    mat[2][0] = 7;
    mat[2][1] = 8;
    mat[2][2] = 9;
    mat[3][0] = -1;
    mat[3][1] = 8;
    mat[3][2] = -1;
    memset(dp, -1, sizeof(dp));
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == 3 and (j == 0 or j == 2))
            {
                continue;
            }
            res = (res + func(mat, i, j, n - 1)) % mod;
        }
    }

    return res;
}

int main()
{
    int n = 3131;
    cout << knightDialer(n) << endl;
    return 0;
}