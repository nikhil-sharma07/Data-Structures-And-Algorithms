#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string dict;
    cin >> dict;
    int k;
    cin >> k;
    int n = s.size();
    int cnt = 0;
    int l = 0, r = 0;
    unordered_map<int, vector<int>> mp;
    long long q = 1000000007;
    long long d1 = 256;
    long long d2 = 26;
    int res = 0;
    while (r < n)
    {
        if (dict[s[r] - 97] == '0')
        {
            cnt++;
        }

        while (cnt > k)
        {
            if (dict[s[l] - 97] == '0')
            {
                cnt--;
            }
            l++;
        }

        long long ts1 = 0;
        long long ts2 = 0;
        for (int i = l; i <= r; i++)
        {
            ts1 = (d1 * ts1 + (s[i] - 96)) % q;
            ts2 += (s[i] - 96);
            if (mp.find(ts1) == mp.end())
            {
                mp[ts1].push_back(ts2);
                res++;
            }
            else
            {
                vector<int> v = mp[ts1];
                bool flag = true;
                for (int i = 0; i < v.size(); i++)
                {
                    if (v[i] == ts2)
                    {
                        flag = false;
                        break;
                    }
                }

                if (flag)
                {
                    res++;
                    mp[ts1].push_back(ts2);
                }
            }
        }
        r++;
    }

    cout << res << endl;

    return 0;
}