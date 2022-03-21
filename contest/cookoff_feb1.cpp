#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int w;
        cin >> w;
        int n;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }

        sort(v.begin(), v.end(), greater<int>);

        int r = 0;
        int sum = 0;
        while (r < n)
        {
            sum += v[r];
            if (sum >= w)
            {
                break;
            }
            r++;
        }

        cout << n - r << endl;
    }
}