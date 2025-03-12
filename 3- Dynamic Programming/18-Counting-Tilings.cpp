#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
Statment:

Your task is to count the number of ways you can fill an n * m grid using 1 * 2 and 2 * 1 tiles.


Solution:

Since n is too small, we can do a dp bitmask on n

now what exactly can we do ?
we know at at some column, we can place a 1*2 tile or a 2*1
if we place a 2 by one tile, the next column will not be affected
if we place a 1 by 2 tile, the next column will be affected

so let's just consider two columns at a time,
as n is too small, we can itrate over all possible masks for one column, and generate all possible masks for the next one

With that done, if we are at a column with the state as mask, I know what are the prevois possbile dp states

so I can just iterate over all possible masks for the previous column and add the
dp value of that mask to the current mask


State: dp[i][mask] = number of ways to fill the first i columns with the i-th column having the mask as the state
Transition: dp[i][mask] = sum(dp[i-1][prev]) for all possible prev states

ans = dp[m][0]

base case: dp[0][0] = 1


*/
vector<int> possibleMasks[(1 << 11)];
int n, m;
// i is the current column
// prev is the mask of the previous column
// cur is the mask of the current column
void gen(int i, int prev, int cur)
{
    if (i == n)
    {
        // we have reached the end of the row
        possibleMasks[cur].push_back(prev);
        return;
    }

    // if the current cell is already filled
    if (prev & (1 << i))
    {
        gen(i + 1, prev, cur);
        return;
    }

    // if we can place a 2*1 tile
    if (i + 1 < n and not((1 << (i + 1)) & prev))
    {
        gen(i + 2, prev, cur);
    }
    // if we can place a 1*2 tile
    gen(i + 1, prev, cur | (1 << i));
}

// using int as long long
signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int prev = 0; prev < (1 << 10); prev++)
    {
        gen(0, prev, 0);
    }
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp(m + 1, vector<int>(1 << 10, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= m; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            for (auto &prev : possibleMasks[mask])
            {
                dp[i][mask] += dp[i - 1][prev];
                dp[i][mask] %= MOD;
            }
        }
    }

    cout << dp[m][0];

    return 0;
}