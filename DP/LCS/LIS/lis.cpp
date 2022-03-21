#include <bits/stdc++.h>
using namespace std;

// O(N*N) Approach
//  int lengthofLIS(vector<int> nums)
//  {
//      int n = nums.size();
//      int dp[n];
//      dp[0] = 1;
//      for (int i = 1; i < n; i++)
//      {
//          dp[i] = 1;
//          for (int j = 0; j < i; j++)
//          {
//              if (nums[i] > nums[j])
//                  dp[i] = max(dp[i], 1 + dp[j]);
//          }
//      }

//     return *max_element(dp, dp + n);
// }

// O(N*LogN) Approach
int lengthofLIS(vector<int> nums)
{
    int n = nums.size();
    vector<int> lis_vec;
    lis_vec.push_back(nums[0]);
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > lis_vec.back())
        {
            lis_vec.push_back(nums[i]);
        }
        else
        {
            int idx = lower_bound(lis_vec.begin(), lis_vec.end(), nums[i]) - lis_vec.begin();
            lis_vec[idx] = nums[i];
        }
    }

    return lis_vec.size();
}

int main()
{
    vector<int> nums{50, 3, 10, 7, 40, 80};
    cout << lengthofLIS(nums);
}