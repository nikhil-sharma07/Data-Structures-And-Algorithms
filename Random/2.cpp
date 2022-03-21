#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str = "";
    int i;
    for (i = n; i > 3; i -= 2)
    {
        str += '1';
    }

    if (i == 3)
    {
        str += '7';
    }
    else
    {
        str += '1';
    }
    reverse(str.begin(), str.end());
    cout << str << endl;
    return 0;
}