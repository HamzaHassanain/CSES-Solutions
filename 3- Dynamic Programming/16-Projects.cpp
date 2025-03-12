#include <bits/stdc++.h>
using namespace std;

#define int long long
/*
Statment:
There are n projects you can attend. For each project, you know its starting and
ending days and the amount of money you would get as reward. You can only attend one project during a day.

What is the maximum amount of money you can earn?

Solution:

If I chose to attend project i, I can't attend any project that starts before project i ends
So, I need to find the next project that starts after project i ends

Let's sort the projects by their starting days

Let's say dp[i] is the maximum amount of money I can earn if I attend project i

dp[i] = max(dp[i+1], dp[j] + reward[i]) for all j > i and start[j] > end[i]
We can easily find j using binary search

Finally, the answer is the maximum value in dp

*/

// using int as long long
signed main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin >> n;

    vector<vector<int>> projects(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> projects[i][0] >> projects[i][1] >> projects[i][2];

    sort(projects.begin(), projects.end());

    vector<int> start, end, reward;
    for (int i = 0; i < n; i++)
    {
        start.push_back(projects[i][0]);
        end.push_back(projects[i][1]);
        reward.push_back(projects[i][2]);
    }

    vector<int> dp(n, 0);

    for (int i = n - 1; i >= 0; i--)
    {
        int nxt = -1;
        int l = i + 1, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (start[mid] > end[i])
            {
                nxt = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        dp[i] = reward[i];
        if (nxt != -1)
            dp[i] += dp[nxt];
        if (i < n - 1)
            dp[i] = max(dp[i], dp[i + 1]);
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}