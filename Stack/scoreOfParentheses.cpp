#include <bits/stdc++.h>
using namespace std;

int func(string &s, int left, int right)
{
    if (right - left + 1 == 2)
    {
        return 1;
    }

    int idx = left + 1, val = 0;
    int l = left;
    while (idx <= right)
    {
        int opening = 1, closing = 0;
        while (opening != closing)
        {
            if (s[idx] == '(')
                opening++;
            else
                closing++;
            idx++;
        }
        idx--;

        if (left == l and right == idx)
            val = 2 * func(s, left + 1, idx);
        else
            val += func(s, left, idx);
        left = idx + 1;
        idx += 2;
    }

    return val;
}

int scoreOfParentheses(string &s)
{
    return func(s, 0, s.size() - 1);
}

int main()
{
    string s = "()(()()()())";
    cout << scoreOfParentheses(s) << endl;
    return 0;
}
