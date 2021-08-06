// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing
// the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

//If we sort the array the applying LCS on nums and sorted array we can find the longest increasing subsequence.

#include <bits/stdc++.h>
using namespace std;

//O(N^2) Approach
// int lengthOfLIS(vector<int> &nums)
// {
//     int n = nums.size();
//     int dp[n];
//     dp[0] = 1;
//     int res = 1;
//     for (int i = 1; i < n; i++)
//     {
//         int mx = INT_MIN;
//         for (int j = 0; j < i; j++)
//         {
//             if (nums[i] > nums[j])
//             {
//                 if (mx < dp[j])
//                 {
//                     mx = dp[j];
//                 }
//             }
//         }

//         if (mx == INT_MIN)
//         {
//             dp[i] = 1;
//         }
//         else
//         {
//             dp[i] = mx + 1;
//         }
//         res = max(res, dp[i]);
//     }

//     return res;
// }

//O(NlogN) Approach
int lengthOfLIS(vector<int> &nums)
{
    vector<int> v;
    v.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (v[v.size() - 1] < nums[i])
        {
            v.push_back(nums[i]);
        }
        else
        {
            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            v[idx] = nums[i];
        }
    }

    return v.size();
}

int main()
{
    vector<int> nums{0, 1, 0, 3, 2, 3};
    cout << lengthOfLIS(nums) << endl;
    return 0;
}