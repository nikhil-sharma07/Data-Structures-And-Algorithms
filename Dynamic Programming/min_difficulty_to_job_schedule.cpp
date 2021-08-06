#include <bits/stdc++.h>
using namespace std;

int dp[500][20];
int func(vector<int> &v, int d, int i)
{
    if (d == 0)
    {
        int e = *max_element(v.begin() + i, v.end());
        return e;
    }

    if (i == v.size())
    {
        return -1;
    }

    if (dp[i][d] != -1)
    {
        return dp[i][d];
    }

    int res = INT_MAX;
    int mx = INT_MIN;
    for (int k = i; k < v.size() - 1; k++)
    {
        mx = max(v[k], mx);
        int val = func(v, d - 1, k + 1);
        if (val != -1)
        {
            res = min(res, mx + val);
        }
    }

    if (res == INT_MAX)
        return dp[i][d] = -1;

    return dp[i][d] = res;
}

int minDifficulty(vector<int> &v, int d)
{
    memset(dp, -1, sizeof(dp));
    return func(v, d - 1, 0);
}

int main()
{
    vector<int> v{6, 5, 4, 3, 2, 1};
    int d = 2;
    cout << minDifficulty(v, d) << endl;
}