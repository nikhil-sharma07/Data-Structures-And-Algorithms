#include <bits/stdc++.h>
using namespace std;

// 3 5
// 380

bool isPossible(string s, int n, int k, int l)
{
    int cnt = 0;

    while (l >= 0 and s[l] == '0')
    {
        l--;
    }

    for (int i = l; i >= 0; i--)
    {
        int num = (s[i] - '0' + cnt) % 10;
        if (num != 0)
            cnt += (abs(num - 10));
        if (cnt > k)
        {
            return false;
        }
    }
    return true;
}

int max_zeros(string s, int n, int k)
{
    int l = 0, r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (isPossible(s, n, k, mid))
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return l;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        cout << max_zeros(s, n, k) << endl;
    }

    return 0;
}