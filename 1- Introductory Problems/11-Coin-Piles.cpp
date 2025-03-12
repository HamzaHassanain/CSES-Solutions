#include <bits/stdc++.h>

using namespace std;

/*


For a query, we have 2 piles having A and B coins.
Let’s say we remove 1 coin from the first pile X number of times and remove 2 coins from the first pile Y number of times.
So, if we want to empty the first pile, the following equation should be true:

1 * X + 2 * Y = A (Equation 1)

When we remove 1 coin from the first pile, we also remove 2 coins from the second pile. Similarly,
when we remove 2 coins from the first pile, we also remove 1 coin from the second pile. So,
if we want to empty the first pile, the following equation should be true:

2 * X + 1 * Y = B (Equation 2)

Simplifying the above equations, we get the value of
X = (2 * B – A)/3 and the value of Y = (2 * A – B)/3.

So, to check whether it is possible to empty both the piles, (2 * B – A)
should be positive and divisible by 3 and (2 * A – B) should pe positive and divisible by 3.


*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        long long a, b;
        cin >> a >> b;

        long long x = (2 * b - a) / 3;
        long long y = (2 * a - b) / 3;

        bool ok = 1;
        ok &= (2 * b - a) % 3 == 0;
        ok &= (2 * a - b) % 3 == 0;
        ok &= x >= 0;
        ok &= y >= 0;

        if (ok)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}