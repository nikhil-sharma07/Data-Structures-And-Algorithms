#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long s;
        cin >> s;
        if (s == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << s / (lsong long)(n * n) << endl;
        }
    }

    return 0;
}