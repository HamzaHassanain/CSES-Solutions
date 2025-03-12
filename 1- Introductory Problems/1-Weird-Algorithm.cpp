#include <bits/stdc++.h>

using namespace std;

/*


The idea is just to simulate the process of the algorithm, and print the numbers in the sequence.
The only trick here is that n will not fit in an 32-bit integer, so we need to use a 64-bit integer.


*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2 == 0)
            n = n / 2ll;
        else
            n = 3ll * n + 1ll;

        cout << n << " ";
    }
}