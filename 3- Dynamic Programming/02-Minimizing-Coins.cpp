#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:

Produce a sum of money x using the available coins in such a way that the number of coins is minimal.



Solution:

We can produce sum 0 by not taking any coin,

Then for all coins available, we can produce sum x that is the value of that coin using only that coin.

If we can produce sum x, then we can procude sum x+coin (for all coins available)

While we are producing a sum of x , there might be multiple ways to produce that sum,
so we need to take the minimum number of coins needed to produce that sum.

So we can define the state dp[x] as the minimum number of coins needed to produce sum x.
Define our bases cases as, dp[0]=0, as we can produce sum 0 by not taking any coin, and dp[x]=1e9 for all x>0 , as we can't produce any sum using 0 coins.

The Dp Transition will be dp[x] = min(dp[x], dp[x-coin]+1) for all coins available.

Finally, the answer will be dp[x] if it is less than 1e9, otherwise, there is no way to produce sum x using the available coins.




*/

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);

    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int sum = 1; sum <= x; sum++)
    {
        for (auto &coin : coins)
        {
            if (sum >= coin)
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]);
    return 0;
}