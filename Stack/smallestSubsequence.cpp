#include <bits/stdc++.h>
using namespace std;

string smallestSubsequence(string s, int k, char letter, int repetition)
{
    int n = s.size();
    stack<char> st;
    string res = "";
    int freq = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == letter)
            freq++;
    }

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(s[i]);
            if (s[i] == letter)
            {
                freq--;
                cnt++;
            }

            continue;
        }
        // stack --> {e} k=3,freq=5,cnt=1
        // abbccccdd

        int left = n - i;
        while (!st.empty() and st.top() >= s[i] and (k - st.size() < left))
        {
            if (st.top() == letter)
            {
                if (cnt == repetition and freq == 0)
                {
                    break;
                }

                if (cnt < repetition and (repetition - cnt) == freq)
                {
                    break;
                }

                cnt--;
            }

            st.pop();
        }

        st.push(s[i]);
        if (s[i] == letter)
        {
            cnt++;
            freq--;
        }
    }

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s = "leeeee";
    cout << smallestSubsequence(s, 3, 'e', 2) << endl;
    return 0;
}
