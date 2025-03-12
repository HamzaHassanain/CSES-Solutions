#include <bits/stdc++.h>

using namespace std;

/*

We can see that grid consists of many squares and the values at boundaries of the square is either in increasing or decreasing order.
We can see that The answer lies at the boundary of the square which side is the max of x,y So now to get the value at yth row and xth column we can
compute the area of inner square which side is just one less than the side of square whose boundary contains the answer.
The remaining value can be added to the area of inner square by checking the parity of min of x,y
We can see that for even row in the grid, the numbers are in decreasing order,
and for the odd row the numbers are in increasing order in the anticlockwise direction.




*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        long long x, y;
        cin >> x >> y;

        if (x > y) // answer lies in the row
        {
            if (x % 2) // if x is odd then the numbers are in increasing order
            {
                long long ans = (x - 1ll) * (x - 1ll) + 1;
                cout << ans + y - 1;
            }
            else // if x is even then the numbers are in decreasing order
            {
                long long ans = x * x;
                cout << ans - y + 1;
            }
        }
        else // answer lies in the column
        {
            // NOTE THAT: Y conditions are the reverse of X's

            if (y % 2) // if y is odd then the numbers are in increasing order
            {
                long long ans = y * y;
                cout << ans - x + 1;
            }
            else // if y is even then the numbers are in decreasing order
            {
                long long ans = (y - 1ll) * (y - 1ll) + 1;
                cout << ans + x - 1;
            }
        }

        cout << "\n";
    }

    return 0;
}