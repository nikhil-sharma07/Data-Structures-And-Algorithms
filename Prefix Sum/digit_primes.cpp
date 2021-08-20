// A prime number is a positive number, which is divisible by exactly two different integers. A digit prime
// is a prime number whose sum of digits is also prime. For example the prime number 41 is a digit prime
// because 4 + 1 = 5 and 5 is a prime number. 17 is not a digit prime because 1 + 7 = 8, and 8 is not
// a prime number. In this problem your job is to find out the number of digit primes within a certain
// range less than 1000000.

//Input
// First line of the input file contains a single integer N (0 < N ≤ 500000) that indicates the total number
// of inputs. Each of the next N lines contains two integers t1 and t2 (0 < t1 ≤ t2 < 1000000)

// Output
// For each line of input except the first line produce one line of output containing a single integer that
// indicates the number of digit primes between t1 and t2 (inclusive).

// Sample Input
// 3
// 10 20
// 10 100
// 100 10000
// Sample Output
// 1
// 10
// 576

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

// int countP[500001];
// void countPrimes()
// {
//     countP[0] = 0;
//     for (int i = 1; i <= 500000; i++)
//     {
//         if (sieve[i])
//         {
//             countP[i] = countP[i - 1] + 1;
//         }
//         else
//         {
//             countP[i] = countP[i - 1];
//         }
//     }
// }

int countDigitPrimes[1000000];
void countDigit()
{
    countDigitPrimes[0] = 0;
    countDigitPrimes[1] = 0;
    for (int i = 2; i < 1000000; i++)
    {
        if (sieve[i])
        {
            int sum = 0;
            int temp = i;
            while (temp)
            {
                sum += (temp % 10);
                temp = temp / 10;
            }
            if (sieve[sum] == true)
            {
                countDigitPrimes[i] = countDigitPrimes[i - 1] + 1;
            }
            else
            {
                countDigitPrimes[i] = countDigitPrimes[i - 1];
            }
        }
        else
        {
            countDigitPrimes[i] = countDigitPrimes[i - 1];
        }
    }
}

int main()
{
    int t;
    cin >> t;
    createSieve();
    countDigit();
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == 0)
        {
            cout << countDigitPrimes[b] << endl;
        }
        else
        {
            cout << countDigitPrimes[b] - countDigitPrimes[a - 1] << endl;
        }
    }

    return 0;
}