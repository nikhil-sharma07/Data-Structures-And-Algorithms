#include <bits/stdc++.h>
using namespace std;

int bestCandidate(vector<int> v, int x)
{
    int idx = 0;
    int mn = INT_MAX;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (abs(v[i] - x) < mn)
        {
            mn = abs(v[i] - x);
            idx = i;
        }
    }

    return idx;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        vector<int> B;
        long long val = 0;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            A.push_back(num);
        }

        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            B.push_back(num);
        }

        int idx1 = bestCandidate(B, A[0]);
        int idx2 = bestCandidate(B, A[n - 1]);
        if ((idx1 == 0 and idx2 == n - 1) or (idx1 == n - 1 and idx2 == 0))
        {
            val = abs(A[0] - B[idx1]) + abs(A[n - 1] - B[idx2]);
        }
        else if ((idx1 == 0 and idx2 !=))

            cout << val << endl;
    }

    return 0;
}
