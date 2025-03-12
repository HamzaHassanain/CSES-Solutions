#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:

Your task is to calculate the number of distinct ways you can produce a money sum x
using the available coins (Duplicate coins are allowed).
In this Version, the order matters so
{1,2} and {2,1} are considered DIFFRENT ways to produce sum 3.

Solution:

First Solve Minimizing Coins Problem, then we can use the same approach to solve this problem.
But instead of minimizing the number of coins, we will count the number of ways to produce sum x.

So let the state dp[x] be the number of ways to produce sum x using the available coins.

Our base case will be dp[0]=1, as there is always one way to produce sum 0, which is by not taking any coin.

The Dp Transition will be dp[x] = dp[x] + dp[x-coin] for all coins available that are less than or equal to x.

Finally, the answer will be dp[x].

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
    for (int sum = 0; sum <= x; sum++)
        for (auto &coin : coins)
        {
            if (sum >= coin)
                dp[sum] = (dp[sum] + dp[sum - coin]);

            if (dp[sum] >= MOD)
                dp[sum] -= MOD;
        }

    cout << dp[x];

    return 0;
}