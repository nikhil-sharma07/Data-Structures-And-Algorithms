#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int freq[n + 1];
    memset(a, 0, sizeof(a));
    memset(freq, 0, sizeof(freq));
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        a[l] = a[l] - l + 1;
        a[r + 1] = a[r + 1] + l - 1;
        freq[l] += 1;
        freq[r + 1] += -1;
    }

    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i];
        freq[i] = freq[i - 1] + freq[i];
    }

    int m;
    cin >> m;
    while (m--)
    {
        int num;
        cin >> num;
        cout << a[num] + freq[num] * num << endl;
    }

    return 0;
}