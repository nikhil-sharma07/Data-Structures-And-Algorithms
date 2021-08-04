// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the
// number of 1's in the binary representation of i.
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

#include <bits/stdc++.h>
using namespace std;

vector<int> countBits(int n)
{
    if (n == 0)
    {
        return {0};
    }

    vector<int> res(n);
    res.push_back(0);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            res[i] = 1 + res[i - 1];
        }
        else
        {
            res[i] = res[i / 2];
        }
    }

    return res;
}

int main()
{
    int n = 30;
    vector<int> v = countBits(n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}