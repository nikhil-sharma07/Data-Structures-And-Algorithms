#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        bool res = true;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = str[j] - '0';
            }
        }

        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < m - 1; j++)
            {
                int sum = mat[i][j] + mat[i][j + 1] + mat[i + 1][j] + mat[i + 1][j + 1];
                if (sum == 3)
                {
                    res = false;
                    break;
                }
            }

            if (res == false)
                break;
        }

        if (res == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}