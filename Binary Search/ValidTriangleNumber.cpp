// Given an integer array nums, return the number of triplets chosen from the array that can make triangles
// if we take them as side lengths of a triangle.

// Input: nums = [2,2,3,4]
// Output: 3
// Explanation: Valid combinations are:
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3

#include <bits/stdc++.h>
using namespace std;

// O(N^3) Approach
// int triangleNumber(vector<int> &nums)
// {
//     int n = nums.size();
//     int cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < nums.size(); j++)
//         {
//             for (int k = j + 1; k < nums.size(); k++)
//             {
//                 int a = nums[i];
//                 int b = nums[j];
//                 int c = nums[k];
//                 if (a + b > c and b + c > a and c + a > b)
//                 {
//                     cnt++;
//                 }
//             }
//         }
//     }

//     return cnt;
// }

// O(N^2logN) Approach
//  int triangleNumber(vector<int> &nums)
//  {
//      sort(nums.begin(), nums.end());
//      int n = nums.size();
//      int cnt = 0;
//      for (int i = 0; i < n; i++)
//      {
//          for (int j = i + 1; j < nums.size(); j++)
//          {
//              int a = nums[i];
//              int b = nums[j];
//              int idx = lower_bound(nums.begin() + j + 1, nums.end(), a + b) - nums.begin() - 1;
//              cnt += (idx - j);
//          }
//      }

//     return cnt;
// }

int triangleNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int l = 0, r = i - 1;
        while (l < r)
        {
            if (nums[l] + nums[r] > nums[i])
            {
                cnt += (r - l);
                r--;
            }
            else
            {
                l++;
            }
        }
    }

    return cnt;
}

int main()
{
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);

    cout << triangleNumber(nums) << endl;
    return 0;
}
