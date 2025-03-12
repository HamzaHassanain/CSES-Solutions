#include <bits/stdc++.h>
using namespace std;

/*

Statement:

The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:

Add one character to the string.
Remove one character from the string.
Replace one character in the string.

For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.


Solution:

Consider what happens when we do each of the mentioned operations if the mismatch is at the index i in s1 and j in s2:

1- Adding one character to the string S1:
    adding a the character s2[j] before the index i in s1, so we move to match s2[j+1] with s1[i] and repeat the process.
2- Adding one character to the string S2
    adding a the character s1[i] before the index j in s2, so we move to match s1[i+1] with s2[j] and repeat the process.
3- Replacing one character in the string S1
    replacing the character s1[i] with s2[j], so we move to match s1[i+1] with s2[j+1] and repeat the process.
4- Replacing one character in the string S2
    replacing the character s2[j] with s1[i], so we move to match s1[i+1] with s2[j+1] and repeat the process.
5- Removing one character from the string S1
    removing the character s1[i], so we move to match s1[i+1] with s2[j] and repeat the process.
6- Removing one character from the string S2
    removing the character s2[j], so we move to match s1[i] with s2[j+1] and repeat the process.

So we can see that we have only 3 possible cases when we have a mismatch:
    1- do some operation and go to s1[i+1] and s2[j+1]
    2- do some operation and go to s1[i+1] and s2[j]
    3- do some operation and go to s1[i] and s2[j+1]

Now let's define dp[i][j] as the minimum number of operations required to transform the prefix of s1 of size i to the prefix of s2 of size j.

The base case is when we have an empty string,
so the minimum number of operations required to transform an empty string to a string of size i is i, and the same for the string s2.

The transition will be as follows:
    1- if s1[i] == s2[j] then dp[i][j] = dp[i-1][j-1]
    2- if s1[i] != s2[j] then dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})

So the final answer will be dp[n][m] where n is the size of s1 and m is the size of s2.


*/

int main()
{

    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = i;

    for (int j = 0; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]});
        }
    }

    cout << dp[n][m];
    return 0;
}