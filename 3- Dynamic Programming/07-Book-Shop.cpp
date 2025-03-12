#include <bits/stdc++.h>
using namespace std;

/*

Problem Statement:
You are in a book shop which sells n different books. You know the price and number of pages of each book.
You have decided that the total price of your purchases will be at most x.

What is the maximum number of pages you can buy? You can buy each book at most once.



Solution (Easy Way):

This problem is known as the 0/1 knapsack problem.

We always can choose to take the book at index I or just leave it and move to the next book.

If you choose to take the book at index I, then for the next books,
our budget will decrease by the price of the book at index I.

So let's write a simple recursive function to solve this problem.
Since the function has two choices for each book, the time complexity of this function is O(2^n).
We can use simple memoization to optimize the time complexity to O(n*x)!

Looking at the Constraints, this solution will result in a TLE!

We have to write a bottom-up DP solution to solve this problem.

So there is a simple way to change the recursive function to a bottom-up DP solution.

1- for each variable we have in our states, do a loop, from 0 to MAX_VALUE if in the recursive function we reduce its value,
or from MAX_VALUE to 0 if we increase its value.

2- change the function call to dp call.

3- set the bases cases of the recursive function as the base cases of the dp table




Solution (DP Way):

First we can chsoe to take the book at index I or just leave it and move to the next book.

So let's define the state dp[i][x] as the maximum number of pages we can buy from the first i books with a budget of x.

Let's define the transition as follows:
    dp[i][money] =
        1- Take The book at i => page[i] + dp[i-1][money-cost[i]]
        2- Leave the book at i => dp[i-1][money]

Bases cases:
    dp[0][money] = 0 for all money (sicen we are filling the dp in one based indexing)

Finally, the answer will be dp[n][x]



*/

int memo[1001][int(1e5) + 1];
int recursiveDp(vector<int> &cost, vector<int> &page, int n, int x, int i)
{
    if (i == n)
        return 0;
    if (memo[i][x] != -1)
        return memo[i][x];
    int ans = 0;
    if (cost[i] <= x)
        ans = max(ans, page[i] + recursiveDp(cost, page, n, x - cost[i], i + 1));
    ans = max(ans, recursiveDp(cost, page, n, x, i + 1));

    return memo[i][x] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // int n, x;
    // cin >> n >> x;
    // vector<int> page(n), cost(n);
    // for (int i = 0; i < n; i++)
    //     cin >> cost[i];
    // for (int i = 0; i < n; i++)
    //     cin >> page[i];
    // vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    // // seting the base case
    // for (int money = 0; money <= x; money++)
    //     dp[n][money] = 0;

    // for (int i = n - 1; i >= 0; i--) // in the recursive we call the function with i+1 so we have to loop from n-1 to 0
    // {
    //     for (int money = 0; money <= x; money++) // in the recursive we call the function with x-cost[i] so we have to loop from 0 to x
    //     {
    //         dp[i][money] = dp[i + 1][money]; // not taking the book at index i
    //         if (cost[i] <= money)
    //             dp[i][money] = max(dp[i][money], page[i] + dp[i + 1][money - cost[i]]); // taking the book at index i
    //     }
    // }

    // // the same as the recursive function (recursiveDp(cost, page, n, x, 0))
    // cout << dp[0][x];

    int n, x;
    cin >> n >> x;
    vector<int> page(n + 1), cost(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> cost[i];
    for (int i = 1; i <= n; i++)
        cin >> page[i];

    vector<vector<int>> dp(n + 2, vector<int>(x + 1, 0));
    for (int money = 0; money <= x; money++)
        dp[0][money] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int money = 0; money <= x; money++)
        {
            dp[i][money] = dp[i - 1][money];
            if (cost[i] <= money)
                dp[i][money] = max(dp[i][money], page[i] + dp[i - 1][money - cost[i]]);
        }
    }

    cout << dp[n][x];

    return 0;
}