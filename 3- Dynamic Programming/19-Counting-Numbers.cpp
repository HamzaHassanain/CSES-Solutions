#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sz(x) (int)x.size()

/*


Statment:
Your task is to count the number of integers between a and b where no two adjacent digits are the same.


Solution:

This problem can be solved using digit dp.

digit dp is pretty simple,
we solve the problem for the range [0, r] and then subtract the answer for the range [0, l-1]

consider the number as a string call it limit, we itrate over the digits of that number and:
if we previously picked a digit that is less than the limit digit at this position, we can pick any digit

if we previously picked a digit that is equal to the limit digit at this position,
we can only pick a digit that is less than or equal to the limit digit at this position

Then we just need to check for the condtion given in the probelem statement

For our problem:

Let's define dp[i][smaller][prv][leading_zeros] as the number of ways to fill the first i digits of the number
where smaller is a boolean that tells us if we can pick any digit or we are restricted to pick a digit less than or equal to the limit digit at this position, leading_zeros is a boolean that tells us if we are allowed to pick a zero or not


Transition:
dp[i][smaller][prv][leading_zeros] = sum(dp[i+1][smaller || c < r[i]][c][leading_zeros and (c == '0')]) for all possible c from '0' to '9'

Base case:
dp[n][0][0][1] = 1

*/
// 34678
ll dp[20][2]['0' + 20][2];
// 000
ll count(const string &r, int i = 0, int smaller = 0, char prv = 0, bool leading_zeros = 1)
{
    if (i >= sz(r)) // base case
        return 1;

    if (dp[i][smaller][prv][leading_zeros] != -1)
        return dp[i][smaller][prv][leading_zeros];

    ll ans = 0;
    for (char c = '0'; c <= '9'; ++c)
    {
        // if current digit is equal to the previous digit and we are not allowed to pick it
        if (c == prv and !leading_zeros)
            continue;

        // if we previously picked a digit that is less than the limit digit at this position, we can pick any digit
        if (smaller || c <= r[i])
            ans += count(r, i + 1, smaller || c < r[i], c, leading_zeros and (c == '0'));
    }
    return dp[i][smaller][prv][leading_zeros] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll l, r;
    cin >> l >> r;

    string lim1 = to_string(r);
    string lim2 = to_string(l - 1);

    memset(dp, -1, sizeof(dp));

    ll c1 = count(lim1); // solve for the range [0, r]

    memset(dp, -1, sizeof(dp)); // reset the dp table

    ll c2 = count(lim2); // solve for the range [0, l-1]
    cout << c1 - c2;

    return 0;
}