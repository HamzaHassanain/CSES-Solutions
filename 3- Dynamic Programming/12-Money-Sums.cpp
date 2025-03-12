#include <bits/stdc++.h>

using namespace std;

/*
Statement:
You have n coins with certain values. Your task is to find all money sums you can create using these coins.

Solution:

First solve Dice Combinations

So let's just construct all possible sums of coins available, (mark true if we can produce that sum, false otherwise)

So how do we construct all possible sums of coins available?

let's define our dp[x] as true if we can produce sum x using the available coins, false otherwise.
first we can produce sum 0 by not taking any coin, so dp[0]=true
then for all available coins, we can produce sum x (for x >= 1 and x <= coin) if we can produce sum x-coin.

so simply dp[x] = dp[x] || dp[x-coin] for all coins available.

Finally, the answer will be the number of sums that we can produce using the available coins.

*/

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int coins[n];
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    // this is a bitset solution, which is faster , uses less memory
    // bitset<int(1e6) + 10> dp;
    // dp[0] = 1;
    // for (int i = 0; i < n; i++)
    // {
    //     dp |= (dp << coins[i]);
    // }`
    // cout << dp.count() - 1 << "\n";

    // for (int i = 1; i <= int(1e6); i++)
    //     if (dp[i])
    //         cout << i << " ";

    vector<int> dp(int(1e5) + 10, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int x = int(1e5); x >= coins[i]; x--)
            dp[x] |= dp[x - coins[i]];

    vector<int> ans;
    for (int i = 1; i <= int(1e5); i++)
        if (dp[i])
            ans.push_back(i);

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << "\n";
    return 0;
}