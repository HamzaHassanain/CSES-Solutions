#include <bits/stdc++.h>

using namespace std;

/*

We want to divide the apples into two groups such that the difference between the total weights of the two groups is minimized.

We can solve the problem using brute force by trying all possible ways to divide the apples into two groups.

Consider the following example:

we can use bitmasking to try all possible ways to divide the apples into two groups.

if we have 3 apples, we can try all possible ways to divide the apples into two groups as follows:

0 Means first group, 1 Means second group

000, 001, 010, 011, 100, 101, 110, 111

So if the corresponding bit is 0, we take the apple weight with a negative sign, 1 means we take the apple weight with a positive sign.

array is {1, 2, 3}
000 -> -1 - 2 - 3 = -6
001 -> -1 - 2 + 3 = 0
010 -> -1 + 2 - 3 = -2
011 -> -1 + 2 + 3 = 4
100 -> 1 - 2 - 3 = -4
101 -> 1 - 2 + 3 = 2
110 -> 1 + 2 - 3 = 0
111 -> 1 + 2 + 3 = 6


Now, the final answer is the minimum absolute difference between the two groups.

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<long long> weights(n);
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    long long minDifference = LLONG_MAX;

    for (int i = 0; i < (1 << n); i++)
    {
        long long answer = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                answer += weights[j];
            else
                answer -= weights[j];
        }
        minDifference = min(minDifference, abs(answer));
    }

    cout << minDifference << '\n';

    return 0;
}