// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

// Input: nums = [3,1,5,8]
// Output: 167
// Explanation:
// nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
// coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

#include <bits/stdc++.h>
using namespace std;

//Top Down DP
int dp[501][501];
int func(vector<int> nums, int left, int right)
{
    if (left > right)
    {
        return 0;
    }

    if (dp[left][right] != -1)
    {
        return dp[left][right];
    }

    if (left == right)
    {
        return nums[left] * nums[left - 1] * nums[left + 1];
    }

    int res = INT_MIN;
    for (int i = left; i <= right; i++)
    {
        int left_val = func(nums, left, i - 1);
        int right_val = func(nums, i + 1, right);
        res = max(res, left_val + nums[i] * nums[left - 1] * nums[right + 1] + right_val);
    }

    return dp[left][right] = res;
}

int maxCoins(vector<int> nums)
{
    vector<int> v;
    v.push_back(1);
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(nums[i]);
    }

    v.push_back(1);
    return func(v, 1, v.size() - 2);
}

int main()
{
    vector<int> nums{3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
    return 0;
}