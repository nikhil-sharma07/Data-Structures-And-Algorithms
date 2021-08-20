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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != -1)
            {
                cout << a[i] << " ";
                sum += a[i];
            }
            else
            {
                cout << (sum / i) << " ";
                sum += (sum / i);
            }
        }
        cout << endl;
    }

    return 0;
}