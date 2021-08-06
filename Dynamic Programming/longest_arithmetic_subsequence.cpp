#include <bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int> &nums)
{
    unordered_map<int, int> m;
    int dp[nums.size()];
    dp[0] = 1;
    int res = 0;

    //9,4,7,2,10
    for (int i = 1; i < nums.size(); i++)
    {
        int d = nums[i] - nums[0];
        int mx = 1;
        for (int j = 1; j < i; j++)
        {
            int val = nums[i] - nums[j];
            if (m[j] == val and dp[j] > mx)
            {
                mx = dp[j];
                d = val;
            }
        }

        dp[i] = mx + 1;
        m[i] = d;
        res = max(res, dp[i]);
    }

    return res;
}

int main()
{
    vector<int> nums{9, 4, 7, 2, 10};
    cout << longestArithSeqLength(nums) << endl;
    return 0;
}