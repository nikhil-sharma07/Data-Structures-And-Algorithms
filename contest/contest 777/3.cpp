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
        bool possible = true;
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            string str = "";
            cin >> str;
            for (int j = 0; j < m; j++)
            {
                mat[i][j] = str[j] - '0';
            }
        }

        if (mat[0][0] == 1)
        {
            possible = false;
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    if (mat[i][j] == 1)
                    {
                        if (j == 0)
                        {
                            if (i != 0)
                            {
                                v.push_back({i - 1, j, i, j});
                            }
                        }
                        else
                        {
                            v.push_back({i, j - 1, i, j});
                        }
                    }
                }
            }
        }

        if (!possible)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << v.size() << endl;
            for (int i = 0; i < v.size(); i++)
            {
                for (int j = 0; j < v[i].size(); j++)
                {
                    cout << v[i][j] + 1 << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}