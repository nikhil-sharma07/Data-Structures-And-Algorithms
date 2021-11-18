//Question Link
//https://www.hackerrank.com/contests/ab-yeh-kar-ke-dikhao/challenges/kj-and-street-lights/leaderboard

#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(N^2) Approach
//TLE
// int func(vector<pair<int, int>> v, int pos)
// {
//     int a[pos + 1];
//     memset(a, 0, sizeof(a));
//     unordered_set<int> s;
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = v[i].first; j <= v[i].second; j++)
//         {
//             if(s.find(j) == s.end()){
//                 a[j]=1;
//                 s.insert(j);
//             }else{
//                 a[j]=0;
//             }
//         }
//     }

//     int cnt = 0;
//     int res = 0;
//     for (int i = 0; i <= pos; i++)
//     {
//         if (a[i] == 0)
//         {
//             cnt++;
//         }
//         else
//         {
//             cnt = 0;
//         }

//         res = max(res, cnt);
//     }

//     return res;
// }


//Scanline Algorithm
//Time Complexity - O(N)
int func(vector<pair<int, int>> v, int pos)
{
    int a[pos + 2];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < v.size(); i++)
    {
        int s = v[i].first;
        int e = v[i].second;
        a[s] = a[s] + 1;
        a[e + 1] = a[e + 1] - 1;
    }

    for(int i = 1; i < pos+2; i++){
        a[i]=a[i-1]+a[i];
    }

    int res = INT_MIN;
    int cnt = 0;
    for (int i = 0; i < pos + 1; i++)
    {
        if (a[i] == 1)
        {
            cnt = 0;
        }
        else
        {
            cnt++;
        }

        res = max(res, cnt);
    }

    return res;
}

int main()
{
    int n, p;
    cin >> n >> p;
    vector<pair<int, int>> v;
    while (n--)
    {
        int x, r;
        cin >> x >> r;

        if ((x - r) >= 0 and (x + r) <= p)
        {
            v.push_back({x - r, x + r});
        }
        else if ((x - r) >= 0 and (x + r) > p)
        {
            v.push_back({x - r, p});
        }
        else if ((x - r) < 0 and (x + r) <= p)
        {
            v.push_back({0, x + r});
        }
        else if ((x - r) < 0 and (x + r) > p)
        {
            v.push_back({0, p});
        }
    }

    cout << func(v, p) << endl;
    return 0;
}