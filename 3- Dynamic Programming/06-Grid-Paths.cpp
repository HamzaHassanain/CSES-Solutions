#include <bits/stdc++.h>
using namespace std;

/*

Problem Statement:
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x.

What is the maximum number of pages you can buy? You can buy each book at most once.



Solution:

We can only move right or down
So for each cell except the first cell (and the blocked cells),
we can reach it from the cell above (if it exists) or from the cell to the left (if it exists)

So let's define the state dp[i][j] as the number of ways to reach cell (i, j) from cell (0, 0)

Let's define the transition as follows:
dp[i][j] = dp[i-1][j] + dp[i][j-1] if the cell (i, j) is not blocked

Finally, the answer will be dp[n-1][n-1]

Base case: dp[0][0] = 1 if the cell (0, 0) is not blocked as there is only one way to reach it

*/

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    const int MOD = 1e9 + 7;

    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = (grid[0][0] == '.');

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '*')
                continue;

            if (i > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j]);
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;

            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i][j - 1]);
            if (dp[i][j] >= MOD)
                dp[i][j] -= MOD;
        }
    }

    cout << dp[n - 1][n - 1];

    return 0;
}