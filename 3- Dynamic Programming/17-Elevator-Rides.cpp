#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
Statment:
There are n people who want to get to the top of a building which has only one elevator.
You know the weight of each person and the maximum allowed weight in the elevator.
What is the minimum number of elevator rides?


Solution:

Since N is small, we know we need to do a dp on the mask of people in the elevator

let's itrate over all possible masks of people in the elevator  (go throw 1 to 2^n - 1)

for each mask, we need to know the maximum possible weight we can take, and the minimum
number of rides we need to take


let's say dp[mask] is the minimum number of rides we need to take if the people in the mask are in the elevator

We want the previous mask, we can use bitwise xor to get the previous mask

know if the previous weight + the current weight <= x, we can take the current weight
otherwise, we need to take a new ride

Finally, the answer is dp[(1 << n) - 1].first

*/

// using int as long long
signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];
    vector<pair<int, int>> dp(1 << n, {1e9, 0});
    dp[0] = {1, 0};
    for (int mask = 1; mask < (1 << n); mask++)
    {

        for (int i = 0; i < n; i++)
        {
            bool in_elevator = mask & (1 << i);
            if (in_elevator)
            {
                auto [count, sum] = dp[mask ^ (1 << i)];
                if (sum + w[i] <= x)
                    sum += w[i];
                else
                    count++, sum = w[i];

                dp[mask] = min(dp[mask], {count, sum});
            }
        }
    }

    cout << dp[(1 << n) - 1].first;

    return 0;
}