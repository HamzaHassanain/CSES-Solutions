#include <bits/stdc++.h>
using namespace std;

/*
statment:
We have an a by b rectangle and we want to cut it into squares,
on each move you can select a rectangle and cut it into two rectangles in such a way that all side lengths remain integers.

We want to find the minimum possbile number moves

Solution

if a == b then we are done, we don't need to cut it anymore
so we can say the minimum number of moves is 0

otherwise we can cut the rectangle into two rectangles in two ways

1. cut it horizontally
2. cut it vertically

if we cut it horizontally then we can cut it at any height h where 1 <= h < a
and we can cut it into two rectangles of size (h, b) and (a - h, b)
Then we can solve the subproblems of size (h, b) and (a - h, b)

if we cut it vertically then we can cut it at any width w where 1 <= w < b
and we can cut it into two rectangles of size (a, w) and (a, b - w)
Then we can solve the subproblems of size (a, w) and (a, b - w)

Now, Let's define dp[h][w] as the minimum number of moves to cut a rectangle of size (h, w)
     into squares which is initialized to infinity or 0 if h == w


Then we can define the transition as follows
    dp[h][w] = min{ dp[h - i][w] + dp[i][w] + 1 } for i in [1, h - 1]
    and also dp[h][w] = min{ dp[h][w - i] + dp[h][i] + 1 } for i in [1, w - 1]

The answer will be dp[a][b]


*/

int main()
{
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a + 10, vector<int>(b + 10, 1e9));
    for (int h = 1; h <= a; h++)
    {
        for (int w = 1; w <= b; w++)
        {
            if (w == h)
                dp[h][w] = 0;
            else
            {
                for (int sub = 1; sub < h; sub++)
                    dp[h][w] = min(dp[h][w], 1 + dp[h - sub][w] + dp[sub][w]);
                for (int sub = 1; sub < w; sub++)
                    dp[h][w] = min(dp[h][w], 1 + dp[h][w - sub] + dp[h][sub]);
            }
        }
    }

    cout << dp[a][b];
}