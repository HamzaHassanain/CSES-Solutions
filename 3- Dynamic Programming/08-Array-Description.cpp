#include <bits/stdc++.h>
using namespace std;
/*

Statement:

We know the array A has n integers where 1 <= A[i] <= m and the diffrence between the adjacent elements is at most 1.
Some array elements are lost (replaced by 0) and we have to calculate the number of possible arrays.


Solution:

first lets see what can we do if the array only contains 1 element
if this element is a positive number, then the answer is just 1
if this element is 0, then the answer is m

so lets define dp[i][j] as the number of possible arrays that can be formed from the first i elements of the array and the ith element is j
this way we can find the answer by summing all the dp[n][j] for j from 1 to m

let's see how we can calculate dp[i][j]

if A[i] is x, then the only possible values for A[i-1] ar  ex+1, x-1, and x

this way we can define the transition as the following:

dp[i][x] = 0 if A[i] != 0 and A[i] != x
Otherwise dp[i][x] = dp[i-1][x-1] + dp[i-1][x+1] + dp[i-1][x]

Finally, the answer will be the sum of dp[n-1][x] for all x from 1 to m

The base case is dp[0][x] = 1 for all x from 1 to m if A[0] = 0,
                 dp[0][A[0]] = 1 if A[0] != 0
*/
int main()
{
    int MOD = 1e9 + 7;
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    vector<vector<long long>> dp(n + 10, vector<long long>(m + 10));
    for (auto &x : a)
        cin >> x;

    if (!a[0])
        for (int x = 1; x <= m; x++)
            dp[0][x] = 1;
    else
        dp[0][a[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (a[i] and a[i] != x)
                continue;
            dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x + 1]) % MOD + dp[i - 1][x]) % MOD;
        }
    }

    long long sum = 0;
    for (int x = 1; x <= m; x++)
    {
        sum += dp[n - 1][x];
        sum %= MOD;
    }
    cout << sum << "\n";
}