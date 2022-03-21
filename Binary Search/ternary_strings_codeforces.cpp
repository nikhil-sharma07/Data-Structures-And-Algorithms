#include <bits/stdc++.h>
using namespace std;

bool isPossible(string s, int k)
{
    int a = 0, b = 0, c = 0;
    int n = s.size();
    for (int i = 0; i < k; i++)
    {
        if (s[i] == '1')
        {
            a++;
        }
        else if (s[i] == '2')
        {
            b++;
        }
        else if (s[i] == '3')
        {
            c++;
        }
    }

    if (a >= 1 and b >= 1 and c >= 1)
    {
        return true;
    }

    int r = k;
    while (r < n)
    {
        if (s[r] == '1')
        {
            a++;
        }
        else if (s[r] == '2')
        {
            b++;
        }
        else if (s[r] == '3')
        {
            c++;
        }

        if (s[r - k] == '1')
        {
            a--;
        }
        else if (s[r - k] == '2')
        {
            b--;
        }
        else if (s[r - k] == '3')
        {
            c--;
        }

        if (a >= 1 and b >= 1 and c >= 1)
        {
            return true;
        }
        r++;
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        int l = 3, r = s.size();
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (isPossible(s, mid))
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (isPossible(s, l))
            cout << l << endl;
        else
            cout << "0" << endl;
    }
}