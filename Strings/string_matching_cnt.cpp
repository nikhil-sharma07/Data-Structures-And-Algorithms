#include <bits/stdc++.h>
using namespace std;

int kmp_algo(string text, string pat)
{
    int n = text.length();
    int m = pat.length();
    int lps[m];
    lps[0] = 0;
    int i = 1, j = 0;
    int cnt = 0;
    while (i < m)
    {
        if (pat[j] == pat[i])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    int x = 0, y = 0;
    while (x < n)
    {
        if (text[x] == pat[y])
        {
            x++;
            y++;
        }
        else
        {
            if (y == 0)
            {
                x++;
            }
            else
            {
                y = lps[y - 1];
            }
        }

        if (y == m)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    string text, pattern;
    cin >> text;
    cin >> pattern;
    cout << kmp_algo(text, pattern) << endl;
    return 0;
}