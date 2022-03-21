#include <bits/stdc++.h>
using namespace std;

bool rabinKarp(string s, string p)
{
    long long n = s.length();
    long long m = p.length();
    long long q = 1000000007;
    long long ts = 0, tp = 0;
    long long d = 26;
    long long h = 1;
    for (int i = 1; i < m; i++)
    {
        h = (h * d) % q;
    }

    for (int i = 0; i < m; i++)
    {
        ts = (d * ts + (s[i] - 96)) % q;
        tp = (d * tp + (p[i] - 96)) % q;
    }

    for (int i = 0; i <= (n - m); i++)
    {

        if (ts == tp)
        {
            for (int j = i; j < (i + m); j++)
            {
                if (s[j] != p[j - i])
                {
                    return false;
                }
            }

            return true;
        }

        ts = ((ts - h * (s[i] - 96)) * d + s[i + m] - 96) % q;
        if (ts < 0)
        {
            ts = ts + q;
        }
    }

    return false;
}

int main()
{
    string s, p;
    cin >> s >> p;
    cout << rabinKarp(s, p) << endl;
    return 0;
}