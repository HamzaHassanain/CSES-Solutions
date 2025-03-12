#include <bits/stdc++.h>

using namespace std;

/*

First Let's calculate the total number of ways to place two knights on a chessboard of size k x k.

We can place the first knight in k*k ways, and the second knight in k*k-1 ways.
We divide by 2 to avoid counting each pair twice.


Then the total number of ways to place two knights on a chessboard of size k x k is k*k*(k*k-1)/2.

Now, let's calculate the number of ways that two knights attack each other.

We know that a knight moves in an L shape, so two squares horizontally and one square vertically,
                                            or two squares vertically and one square horizontally.


So If one knight at a cell, it locks 8 cells, and the other knight can't be placed in these cells.


now we can divide the chessboard into L shapes, and each L is a 2x3 rectangle or a 3x2 rectangle.

So, let's find the number of ways to cut the KxK chessboard into L shapes.

for the 2x3 rectangle, we have (k-1)*(k-2) ways to place it on the chessboard.
for the 3x2 rectangle, we have (k-2)*(k-1) ways to place it on the chessboard.

So the total number of ways to cut the KxK chessboard into L shapes is 2  * (k-1)(k-2) + 2 * (k-2)*(k-1).
We multiply by 2 because we have two Knights.

Finally, the number of ways that two knights attack each other is k*k*(k*k-1)/2 - 2  * (k-1)(k-2) - 2 * (k-2)*(k-1).


*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;

    for (long long k = 1; k <= n; k++)
    {
        long long KK = k * k;
        long long total = KK * (KK - 1) / 2;
        long long invalids = 4 * (k - 1) * (k - 2);

        cout << total - invalids << "\n";
    }

    return 0;
}