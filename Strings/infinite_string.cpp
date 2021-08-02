//Given a string we can repeat the string infinite number of times and given 2 indexes start and end we have to
//calculate the frequency of a particular character in from the starting index till the end index both inclusive.
//eg. let string be "aab" and start index=2 and end index=8 and we have to find occurrences of of character 'a'
//then answer would be 8.
//we can make string "aabaabaabaab" and there are 4 'a's from starting to end in this string

#include <bits/stdc++.h>
using namespace std;
int func(string str, int n, int s, int e, char ch)
{
    int res = 0; //will store the final answer
    int cnt = 0; //count number of occurrences of the character in the given string
    for (int i = 0; i < n; i++)
    {
        if (str[i] == ch)
        {
            cnt++;
        }
    }

    if (cnt == 0)
    {
        return 0; //if there is no occurrences of the character in the string then answer will be 0
    }

    int x = (e + 1) / n;
    int y = (s + 1) / n;

    int ne = 0; //number of occurrences of the character till ending index
    int ns = 0; //number of occurrences of the character till starting index

    ne = x * cnt;
    int n_left_ending; //number of characters left till ending index
    n_left_ending = e + 1 - ne;
    if (n_left_ending)
    {
        cnt = 0;
        for (int i = 0; i <= n_left_ending; i++)
        {
            if (str[i] == ch)
            {
                cnt++;
            }
        }
        ne += cnt;
    }

    ns = y * cnt;
    int n_left_starting = s + 1 - ns;
    if (n_left_ending)
    {
        cnt = 0;
        for (int i = 0; i <= n_left_starting; i++)
        {
            if (str[i] == ch)
            {
                cnt++;
            }
        }
        ns += cnt;
    }

    res = ne - ns;
    if (str[n - 1] == ch)
    {
        res++;
    }
    return res;
}

int main()
{
    string str = "aab";
    int n = str.length();
    int s = 5;
    int e = 15;
    char ch = 'b';
    cout << func(str, n, s, e, ch);
    return 0;
}
