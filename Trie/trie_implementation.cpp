#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag;
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
        root->flag = false;
    }

    void insert(string word)
    {
        Node *temp = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (temp->links[word[i] - 'a'] != NULL)
            {
                temp = temp->links[word[i] - 'a'];
            }
            else
            {
                Node *newNode = new Node();
                temp->links[word[i] - 'a'] = newNode;
                temp = newNode;
            }
        }

        temp->flag = true;
    }

    bool search(string word)
    {
        Node *node = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (node->links[word[i] - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                node = node->links[word[i] - 'a'];
            }
        }

        if (node->flag == true)
        {
            return true;
        }

        return false;
    }

    bool startswith(string word)
    {
        Node *node = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            Node *temp = node.links;
            if (temp[word[i] - 'a'] == NULL)
            {
                return false;
            }
            else
            {
                node = temp[word[i] - 'a'];
            }
        }

        if (node->flag == true)
        {
            return false;
        }

        return true;
    }
};

int main()
{
    string keys[] = {"the", "a", "there",
                     "answer", "any", "by",
                     "bye", "their"};
    int n = sizeof(keys) / sizeof(keys[0]);
    Trie *trie = new Trie();
    for (int i = 0; i < n; i++)
    {
        trie->insert(keys[i]);
    }

    cout << trie->search("th") << endl;
    return 0;
}