#include <bits/stdc++.h>
using namespace std;

//Brute Force
// bool check(vector<vector<char>> &matrix, int si, int sj, int ei, int ej)
// {
//     for (int i = si; i <= ei; i++)
//     {
//         for (int j = sj; j <= ej; j++)
//         {
//             if (matrix[i][j] == '0')
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int maximalSquare(vector<vector<char>> &matrix)
// {
//     int area = 0;
//     for (int i = 0; i < matrix.size(); i++)
//     {
//         for (int j = 0; j < matrix[0].size(); j++)
//         {
//             if (matrix[i][j] == '0')
//             {
//                 continue;
//             }
//             for (int k = i; k < matrix.size(); k++)
//             {

//                 for (int l = j; l < matrix[0].size(); l++)
//                 {
//                     if (matrix[k][l] == '0')
//                     {
//                         break;
//                     }
//                     if ((k - i) == (l - j) and area < (k - i + 1) * (l - j + 1) and check(matrix, i, j, k, l))
//                     {
//                         area = (k - i + 1) * (l - j + 1);
//                     }
//                 }
//             }
//         }
//     }

//     return area;
// }

//Dynamic Programming
int maximalSquare(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n];
    int area = 0;
    for (int i = 0; i < m; i++)
    {
        dp[i][0] = matrix[i][0] - '0';
        area = max(area, dp[i][0]);
    }

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i] - '0';
        area = max(area, dp[0][i]);
    }

    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (matrix[i][j] == '0')
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            area = max(area, dp[i][j]);
        }
    }

    return area * area;
}

int main()
{
    vector<vector<char>> matrix{
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}};

    cout << maximalSquare(matrix);
    return 0;
}