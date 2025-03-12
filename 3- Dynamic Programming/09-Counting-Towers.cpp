#include <bits/stdc++.h>
using namespace std;

/*

statement:

We have a tower of height n, and width of 2 units, and we have to calculate the number of ways to build the tower.
We can use a block of any height and any width

solution:

Let's think about the last raw, we can either have both cells as a part of the same block, or both cells as parts of different blocks

Let's say dp[1][h] as the number of cells that have the last cell as a part of a block of width 1
      and dp[2][h] as the number of cells that have the last cell as a part of a block of width 2


Let's see how we can calculate dp[1][h]
Let's remove the last raw, there will be 2 towers of type one and one tower of type 2
We can deduce that:
dp[1][h] = 2 * dp[1][h-1] + dp[2][h-1]


Same goes for dp[2][h]
dp[2][h] = 4 * dp[2][h-1] + dp[1][h-1]

Finally, the answer will be dp[1][n] + dp[2][n]

we have up to 100 test cases and the n is up to 1e6, so we can precalculate the dp array as the answer will be the same for all test cases
*/

int main()
{

    long long MOD = 1e9 + 7;
    int tc;
    cin >> tc;
    vector<vector<long long>> dp(3, vector<long long>(1e6 + 10));
    dp[1][1] = 1;
    dp[2][1] = 1;
    for (int h = 2; h <= 1e6; h++)
    {
        dp[2][h] = (4 * dp[2][h - 1]) % MOD + dp[1][h - 1];
        dp[2][h] %= MOD;

        dp[1][h] = (2 * dp[1][h - 1]) % MOD + dp[2][h - 1];
        dp[1][h] %= MOD;
    }

    while (tc--)
    {

        int n;
        cin >> n;

        cout << (dp[1][n] + dp[2][n]) % MOD << "\n";
    }
}