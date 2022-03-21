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
        long val = 1;
        long limit = 1e9;
        bool flag = true;
        vector<long> v;
        for (int i = 1; i <= n; i++)
        {
            if (val > limit)
            {
                flag = false;
                break;
            }
            v.push_back(val);
            val = 3 * val;
        }

        if (flag == false)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}