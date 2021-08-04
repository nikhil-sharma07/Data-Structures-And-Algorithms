// Given a m *n matrix of ones and zeros, return how many square submatrices have all ones.
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation:
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

#include <bits/stdc++.h>
using namespace std;
int count_squares(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n];
    int cnt = 0;
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = matrix[i][0];
        if (dp[i][0])
        {
            cnt++;
        }
    }

    for (int i = 1; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
        if (dp[0][i])
        {
            cnt++;
        }
    }

    if (matrix[0][0])
    {
        dp[0][0] = 1;
        cnt++;
    }
    else
    {
        dp[0][0] = 0;
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                cnt += dp[i][j];
            }
        }
    }

    return cnt;
}

int main()
{
    vector<vector<int>> matrix{
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}};

    cout << count_squares(matrix);
    return 0;
}