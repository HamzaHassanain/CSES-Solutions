#include <bits/stdc++.h>

using namespace std;

/*


Since the string is binary, only contains 0 and 1, so for each digit, it can only be 0 or 1, we have two choices for each digit.

Since we have n digits, each one can be one of two choices, so the answers is 2 * 2 * 2 * ... * 2 = 2^n.

So the answer is 2^n.

It can be calculated using the binary exponentiation algorithm in O(log n) time complexity.




*/

long long binpow(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;

    cout << binpow(2, n, 1e9 + 7);

    return 0;
}