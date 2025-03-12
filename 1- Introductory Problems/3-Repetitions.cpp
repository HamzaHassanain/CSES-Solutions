#include <bits/stdc++.h>

using namespace std;

/*


You are given a DNA sequence: a string consisting of characters A, C, G, and T.
Your task is to find the longest repetition in the sequence.
This is a maximum-length substring containing only one type of character.


we can do a two-pointers approach to solve this problem.

first start at i, then find j such that j is the first index that satisfies s[j] != s[i].
then the answer is max(answer, j - i).
then set i to j and repeat the process until i reaches the end of the string.

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    int answer = 1;

    int i = 0;
    while (i < n)
    {
        int j = i;

        while (j < n && s[j] == s[i])
        {
            j++;
        }

        answer = max(answer, j - i);
        i = j;
    }
    cout << answer;

    return 0;
}