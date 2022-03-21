#include <bits/stdc++.h>
using namespace std;

int index(string str, char ch)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ch)
        {
            return i;
        }
    }

    return -1;
}

void smallestSubsequence(string &S, int K, string str)
{
    int N = S.size();
    stack<char> answer;

    for (int i = 0; i < N; ++i)
    {
        if (answer.empty())
        {
            answer.push(S[i]);
        }
        else
        {
            int idx1 = index(str, S[i]);
            int idx2 = index(str, answer.top());
            while ((!answer.empty()) && (idx1 < idx2) && (answer.size() - 1 + N - i >= K))
            {
                answer.pop();
            }

            if (answer.empty() || answer.size() < K)
            {
                answer.push(S[i]);
            }
        }
    }

    string ret;
    while (!answer.empty())
    {
        ret.push_back(answer.top());
        answer.pop();
    }

    reverse(ret.begin(), ret.end());
    cout << ret;
}

int main()
{
    string str = "zyxwvutsrqponmlkjihgfedcba";
    string s = "ehkx";
    smallestSubsequence(s, 2, str);
}