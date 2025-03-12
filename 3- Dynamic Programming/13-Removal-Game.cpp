#include <bits/stdc++.h>
using namespace std;

/*
Statment:

we have an array A of n integers.
Two players are playing a game, each player can remove the first number or the last number from the array.
Find the maximum score of the first player


Solution:

Let's look at the problem form other perspective, let's say we only have one score,
the first player wants to maximize the score and the second player wants to minimize the score.

now it is easy to find the answer.

let dp[i][j] be the maximum score the first player can get from the subarray [i, j]

First=> the first player can can take the elemnt a[i], and second player takes a[i+1], then we can solve the subproblem [i+2, j]
Second=> the first player can can take the elemnt a[i], and second player takes a[j], then we can solve the subproblem [i+1, j-1]
Third=> the first player can can take the elemnt a[j], and second player takes a[j-1], then we can solve the subproblem [i, j-2]
Fourth => the first player can can take the elemnt a[j], and second player takes a[i], then we can solve the subproblem [i+1, j-1]

Note that the second player minimizes the score, and the first player maximizes the score.

Finllay the answer is the maximum of the four cases.

Bases case:
if we have only on elemnt i then dp[i][i] = a[i]

The answer is dp[0][n-1]
*/

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<vector<long long>> dp(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = v[i];
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i + 2 <= j)
                dp[i][j] = max(v[i] + min(dp[i + 2][j], dp[i + 1][j - 1]), v[j] + min(dp[i + 1][j - 1], dp[i][j - 2]));
            else
                dp[i][j] = max(v[i], v[j]);

            if (i + 1 <= j - 1)
                dp[i][j] = max(dp[i][j], v[i] + min(dp[i + 1][j - 1], dp[i + 2][j]));

            if (i <= j - 2)
                dp[i][j] = max(dp[i][j], v[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
        }
    }
    cout << dp[0][n - 1];
    return 0;
}