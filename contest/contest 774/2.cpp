#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> nums;
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            long long num;
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());
        vector<long long> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int countRed = n - i, countBlue = i;
            long long sumRed = prefix[n - 1] - prefix[i - 1], sumBlue = prefix[i - 1];
            if (countRed >= countBlue)
            {
                break;
            }

            if (sumRed > sumBlue)
            {
                res = true;
                break;
            }
        }

        if (res)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}