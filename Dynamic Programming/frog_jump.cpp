// A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

// Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

// If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

// Input: stones = [0,1,3,5,6,8,12,17]
// Output: true
// Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

// Input: stones = [0,1,2,3,4,8,9,11]
// Output: false
// Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

#include <bits/stdc++.h>
using namespace std;

int dp[2001][2001];
bool func(vector<int> &v, int idx, int k, unordered_map<int, int> &m)
{
    if (idx == v.size() - 1)
    {
        return true;
    }

    if (idx > v.size() - 1)
    {
        return false;
    }

    if (dp[idx][k] != -1)
    {
        return dp[idx][k];
    }

    int pos1 = v[idx] + k - 1;
    int pos2 = v[idx] + k;
    int pos3 = v[idx] + k + 1;

    if (k == 1)
    {
        if (m.find(pos2) != m.end())
        {
            if (func(v, m[pos2], k, m))
            {
                return true;
            }
        }

        if (m.find(pos3) != m.end())
        {
            if (func(v, m[pos3], k + 1, m))
            {
                return true;
            }
        }

        return dp[idx][k] = false;
    }

    if (m.find(pos1) != m.end())
    {
        if (func(v, m[pos1], k - 1, m))
        {
            return true;
        }
    }

    if (m.find(pos2) != m.end())
    {
        if (func(v, m[pos2], k, m))
        {
            return true;
        }
    }

    if (m.find(pos3) != m.end())
    {
        if (func(v, m[pos3], k + 1, m))
        {
            return true;
        }
    }

    return dp[idx][k] = false;
}

bool canCross(vector<int> &v)
{
    if (v[1] - v[0] > 1)
    {
        return false;
    }

    memset(dp, -1, sizeof(dp));
    unordered_map<int, int> m;
    for (int i = 0; i < v.size(); i++)
    {
        m[v[i]] = i;
    }

    return func(v, 1, 1, m);
}

int main()
{
    vector<int> stones{0, 1, 2, 3, 4, 8, 9, 11};
    cout << canCross(stones);
    return 0;
}