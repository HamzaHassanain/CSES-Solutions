#include <bits/stdc++.h>
using namespace std;

/*
Statment:

count the number of ways numbers 1,2,\ldots,n can be divided into two sets of equal sum.



Solution:

If the sum from 1 to n is not even then the answer is 0.



considering numbers from 1 to n

each number can be it the set 1, or in the set 2,


we can turn the problem to:

Let Summ = (n*(n+1))/2 / 2
the number of ways to get Summ using numbers from 1 to n
We can see this is a knapsack problem (count the number of ways to get Summ using numbers from 1 to n)



Summ will not exceed 500*500/2 = 125000, 125000 / 2 = 62500
lets count the number of ways to get sum 62500
this will be our answer

state  = dp[i][j] => the number of ways to get sum j using numbers from 1 to i

trnasition: dp[i][j] = dp[i-1][j] + dp[i-1][j-i]

answer is dp[n][Summ]

number of way to make sum Summ
*/

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    const int MOD = 1e9 + 7;

    int n;
    cin >> n;

    int summ = n * (n + 1) / 2;

    if (summ % 2)
    {
        cout << 0;
        return 0;
    }
    vector<vector<int>> dp(summ / 2 + 1, vector<int>(n + 1, 0));

    dp[0][0] = 1;

    for (int sum = 1; sum <= summ / 2; sum++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[sum][i] = dp[sum][i - 1];
            if (sum - i >= 0)
            {
                dp[sum][i] += dp[sum - i][i - 1];
                dp[sum][i] %= MOD;
            }
        }
    }

    cout << dp[summ / 2][n];

    return 0;
}