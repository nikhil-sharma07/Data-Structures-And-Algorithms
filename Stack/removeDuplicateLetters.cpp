#include <bits/stdc++.h>
using namespace std;
string removeDuplicateLetters(string s)
{
    int n = s.size();
    stack<char> st;
    string res = "";
    vector<int> check(26, 0);
    vector<int> cnt(26, 0);

    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;

    for (int i = 0; i < n; i++)
    {

        if (check[s[i] - 'a'])
        {
            cnt[s[i] - 'a']--;
            continue;
        }

        if (st.empty())
        {
            st.push(s[i]);
            cnt[s[i] - 'a']--;
            check[s[i] - 'a'] = 1;
            continue;
        }

        while (!st.empty() and st.top() >= s[i] and cnt[st.top() - 'a'] > 0)
        {
            check[st.top() - 'a'] = 0;
            st.pop();
        }

        st.push(s[i]);
        cnt[s[i] - 'a']--;
        check[s[i] - 'a'] = 1;
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
    string s = "cbacdcbc";
    cout << removeDuplicateLetters(s) << endl;
    return 0;
}
