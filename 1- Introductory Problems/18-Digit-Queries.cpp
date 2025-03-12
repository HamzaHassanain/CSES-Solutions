#include <bits/stdc++.h>

using namespace std;

/*


Let's split the problem into 3 parts:

1- Find the number of digits in the number that contains the digit we are looking for.
2- Find the number that contains the digit we are looking for.
3- Find the digit itself.

For number 1:

Let's say we are looking for the 12th digit. The first 9 digits are 1 digit numbers,
the next 90 digits are 2 digit numbers, the next 900 digits are 3 digit numbers, and so on.
So we can find the number of digits by finding the smallest number that contains the digit we are looking for.

For number 2:

We can find the number that contains the digit we are looking for by dividing the remaining number by the number of digits.

For number 3:

We can find the digit itself by finding the remainder of the remaining number divided by the number of digits.

*/
long long binpow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long tc;
    cin >> tc;

    while (tc--)
    {
        long long n;
        cin >> n;

        long long count_digits = 1;

        long long base = 9;

        // Find the number of digits in the number that contains the digit we are looking for.
        while (n > count_digits * base)
        {
            n -= count_digits * base; // Subtract the number of digits in the numbers that have less digits than the number we are looking for.
            count_digits++;
            base *= 10;
        }
        n--; // 0-based index
        long long x = n / count_digits;
        long long ans = binpow(10, count_digits - 1) + x; // Find the number that contains the digit we are looking for.

        string s = to_string(ans);

        cout << s[n % count_digits] << "\n";
    }

    return 0;
}