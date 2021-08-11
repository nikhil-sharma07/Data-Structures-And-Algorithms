// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

#include <bits/stdc++.h>
using namespace std;

//Backtracking Solution
// void func(string str, set<string> &s, int idx, string x, string y, vector<string> &res)
// {
//     if (idx == str.length())
//     {
//         y.pop_back();
//         res.push_back(y);
//         return;
//     }

//     for (int i = idx; i < str.length(); i++)
//     {
//         x.push_back(str[i]);
//         if (s.find(x) != s.end())
//         {
//             string temp = y;
//             y = y + x;
//             y.push_back(' ');
//             func(str, s, i + 1, "", y, res);
//             y = temp;
//         }
//     }
// }

vector<string> wordBreak(string str, vector<string> &v)
{
    set<string> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }

    vector<string> res;
    // func(str, s, 0, "", "", res);
    unordered_map<int, vector<string>> mp;
    return res;
}

int main()
{
    string s = "pineapplepenapple";
    vector<string> wordDict{"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> v = wordBreak(s, wordDict);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}