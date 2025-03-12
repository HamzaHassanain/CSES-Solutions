#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:

Your task is to calculate the number of distinct ways you can produce a money sum x
using the available coins (Duplicate coins are allowed).
In this Version, the order DOES NOT matter so
{1,2} and {2,1} are considered a SAME way to produce sum 3.

Solution:

First Solve Coin Combinations I Problem, then we can use the same approach to solve this problem.

Instead of counting for each sum,
we will be counting for each coin;


So we know that the coin number i can be used orderless way to produce sum x,

*/

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    int MOD = 1e9 + 7;

    for (auto &coin : coins)
        for (int sum = 0; sum <= x; sum++)
        {
            if (sum >= coin)
                dp[sum] = (dp[sum] + dp[sum - coin]);

            if (dp[sum] >= MOD)
                dp[sum] -= MOD;
        }

    cout << dp[x];

    return 0;
}