#include <bits/stdc++.h>
using namespace std;

/*
Problem Statement:

count the number of ways to construct sum n by throwing a dice one or more times.
Each throw produces an outcome between 1 and  6.



Solution:

You can reach sum x by throwing a dice if you can reach sum x-1 or x-2 or x-3 or x-4 or x-5 or x-6.

So we can define the state dp[x] as the number of ways to reach sum x by throwing a dice.
Our base case will be dp[0]=1, as there is always one way to reach sum 0, which is by not throwing the dice at all.
The Dp Transition will be dp[x] = dp[x-1] + dp[x-2] + dp[x-3] + dp[x-4] + dp[x-5] + dp[x-6].



*/

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int MOD = 1e9 + 7;

    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int face = 1; face <= 6; face++)
            if (i - face >= 0)
                dp[i] = (dp[i] + dp[i - face]) % MOD;
    }

    cout << dp[n];
    return 0;
}