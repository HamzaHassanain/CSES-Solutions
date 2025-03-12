#include <bits/stdc++.h>

using namespace std;

/*

The problem asks us to generate all permutations of a string.

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    vector<string> permutations;
    sort(s.begin(), s.end());
    do
    {
        permutations.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << permutations.size() << '\n';
    for (string permutation : permutations)
        cout << permutation << '\n';
    return 0;
}