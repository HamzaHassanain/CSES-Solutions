#include <bits/stdc++.h>
using namespace std;

/*
Statment:
Determine the longest increasing subsequence in the array, i.e.,
the longest subsequence where every element is larger than the previous one.

N is large


Solution:

1- easy N^2 dp solution
=> dp[i][j] is the longest increasing subsequence ending at i and the last element is j
=> Try doing a pick or leave pattern
=> dp[i][j] = max(dp[i][j], dp[i-1][k] + 1) for all k < j and a[k] < a[j]


2- Tricky NlogN solution

if I am at index i, I can binary search for the smallest element that is less than a[i] , j , j < i and is a part of a longest increasing subsequence

lets say dp[i] is the last element of the longest increasing subsequence ending at i
I can binary search on dp to find the smallest element that is less than a[i]
If I end up at an index j and dp[j-1] < a[i] and dp[j] > a[i] , then I can update dp[j] = a[i] as
this well be the best possible ending for the longest increasing subsequence ending at j

Let's say the base case:
dp[0] = 0
for all i > 0 dp[i] = INF

Transition:
dp[i] = a[i] iff dp[lastIndxValid-1] < a[i] and dp[lastIndxValid] > a[i]
where lastIndxValid is the smallest index such that dp[lastIndxValid] > a[i] in other words, the lower bound of a[i] in dp

finally, the answer is the largest index such that dp[i] != INF


*/

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> dp(n, 1e9 + 10);

    dp[0] = 0;
    int lis = 1;
    for (int i = 0; i < n; i++)
    {
        int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();

        if (dp[idx - 1] < a[i] and a[i] < dp[idx])
            dp[idx] = a[i];

        lis = max(lis, idx);
    }

    cout << lis;

    return 0;
}