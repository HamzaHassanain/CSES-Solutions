#include <bits/stdc++.h>
using namespace std;

/*

Problem Statement:
You are given an integer n. On each step, you may subtract one of the digits from the number.
What is The minimum numer of steps required to make the number equal to 0?


Solution:

You can always subtract a digit from the number to make it smaller,
So For each digit in the current number, we can subtract it form the number to make it smaller, then we transition to the samller number

For all number that are less than 10, the answer is 1, as we can always subtract the number itself to make it 0.

So let's define the state dp[x] as the minimum number of steps required to make the number x equal to 0.

Let the transition be dp[x] = 1 + dp[x-(digit)] for all digits in the number x.

Finally, the answer will be dp[n].


*/

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> dp(max(n + 1, 10));
    for (int i = 1; i <= 9; i++)
        dp[i] = 1;

    for (int x = 10; x <= n; x++)
    {
        dp[x] = 1e9;
        for (char &ch : to_string(x))
        {
            dp[x] = min(dp[x], 1 + dp[x - (ch - '0')]);
        }
    }

    cout << dp[n];

    return 0;
}