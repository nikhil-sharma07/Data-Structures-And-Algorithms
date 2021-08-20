#include <bits/stdc++.h>
using namespace std;

//Time Complexity - O(N*log(log N))
int N = 1000000;
bool sieve[1000001];
void createSieve()
{
    for (int i = 0; i <= N; i++)
    {
        sieve[i] = true;
    }

    sieve[0] = false;
    sieve[1] = false;

    for (int i = 2; (long long)i * i <= N; i++)
    {
        if (sieve[i] == true)
        {
            for (long long j = (long long)i * i; j <= N; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

int main()
{
    createSieve();
    for (int i = 0; i <= 100; i++)
    {
        if (sieve[i] == true)
        {
            cout << i << " ";
        }
    }

    return 0;
}