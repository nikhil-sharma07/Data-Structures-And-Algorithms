#include <bits/stdc++.h>
using namespace std;

//TIME COMPLEXITY - O(N^3)
//SPACE COMPLEXITY - O(N^2)
int dp[1001][1001];
int func(int a[], int s, int e)
{
    if (s >= e)
    {
        return 0;
    }

    if (dp[s][e] != -1)
    {
        return dp[s][e];
    }

    int res = INT_MAX;
    for (int k = s; k < e; k++)
    {
        int cost = func(a, s, k) + func(a, k + 1, e) + a[s - 1] * a[k] * a[e];
        res = min(res, cost);
    }

    return dp[s][e] = res;
}

int mcm(int a[], int n)
{
    int s = 1;
    int e = n - 1;
    memset(dp, -1, sizeof(dp));
    return func(a, s, e);
}

int main()
{
    int a[5] = {40, 20, 30, 10, 30};
    cout << mcm(a, 5);
    return 0;
}