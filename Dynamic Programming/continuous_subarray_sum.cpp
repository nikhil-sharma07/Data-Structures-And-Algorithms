#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> m;
    int sum = 0;
    if (nums.size() == 1)
    {
        return 0;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum % k == 0 and i + 1 >= 2)
        {
            return true;
        }

        if (m.find(sum % k) != m.end() and i - m[sum % k] >= 2)
        {
            return true;
        }

        if (m.find(sum % k) == m.end())
        {
            m[sum % k] = i;
        }
    }

    return false;
}

int main()
{
    vector<int> nums{23, 2, 4, 6, 7};
    cout << checkSubarraySum(nums, 6);
}