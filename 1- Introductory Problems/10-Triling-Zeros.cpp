#include <bits/stdc++.h>

using namespace std;

/*


If we observe carefully, the number of trailing zeros in N! is same as calculating the number of times the number N! is divisible by 10.
We can find this by finding the number of pairs of {2, 5} in the prime factorization of N! as 2 * 5 = 10.
Since the number of 2s will always be greater than the number of 5s in prime factorization of N!,
therefore we can only calculate the number of 5s to calculate the total number of trailing zeros.

Also, the number of 5s in the prime factorization can be different for different numbers.
Every multiple of 5 will have at least one 5 in the prime factorization. Similarly,
every multiple of 25 will have at least two 5s and every multiple of 125 will have at least three 5s in the prime factorization as so on. So,
we can first count the number of 5s for every multiple of 5 then for every multiple of 25, then 125 and so on to calculate the final answer.


*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long N;
    cin >> N;

    function<long long(long long)> countTrailingZeros = [&](long long n) -> long long
    {
        if (n < 5)
            return 0;

        return n / 5 + countTrailingZeros(n / 5);
    };

    cout << countTrailingZeros(N);

    return 0;
}