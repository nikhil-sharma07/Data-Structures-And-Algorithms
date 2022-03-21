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
        string str = "";
        if (n == 1 or n == 2)
        {
            str.push_back(n + '0');
        }
        else
        {
            char ch = '1';
            int sum = 0;
            while (sum < n)
            {
                sum += (ch - '0');
                str.push_back(ch);
                if (ch == '1')
                    ch = '2';
                else
                    ch = '1';
            }

            if (sum != n)
            {
                char ch = '2';
                int sum = 0;
                str = "";
                while (sum < n)
                {
                    sum += (ch - '0');
                    str.push_back(ch);
                    if (ch == '1')
                        ch = '2';
                    else
                        ch = '1';
                }
            }
        }

        reverse(str.begin(), str.end());
        cout << str << endl;
    }
    return 0;
}