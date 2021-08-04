//Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set
//with sum equal to given sum.
//eg. a[] = {3, 34, 4, 12, 5, 2} and sum = 9  Output = True
//Recursion + Memoization (Top Down)
#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];
bool isSubsetSum(int a[], int n, int sum)
{
    if (sum == 0)
    {
        return true;
    }

    if (n == 0)
    {
        return false;
    }

    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (a[n - 1] <= sum)
    {
        return dp[n][sum] = isSubsetSum(a, n - 1, sum - a[n - 1]) or isSubsetSum(a, n - 1, sum);
    }
    else
    {
        return dp[n][sum] = isSubsetSum(a, n - 1, sum);
    }
}

int main()
{
    int a[] = {3, 34, 4, 12, 5};
    int sum = 9;
    int n = sizeof(a) / sizeof(a[0]);
    memset(dp, -1, sizeof(dp));
    if (isSubsetSum(a, n, sum) == true)
        cout << "Found a subset with given sum";
    else
        cout << "No subset with given sum";
    return 0;
}