#include <bits/stdc++.h>

using namespace std;

/*

Let's look at string as the frequency of each character in the string.

If the string is a palindrome, then the frequency of each character should be even, except for one character that can be odd.

So, we can iterate over the frequency array and add the characters with even frequency to the beginning and end of the string,
and the character with odd frequency to the middle of the string.



*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;

    vector<int> freq(26, 0);
    for (char c : s)
        freq[c - 'A']++;

    string palandrome = string(s.size(), '-');
    int i = 0, j = s.size() - 1;
    for (int k = 0; k < 26; k++)
    {
        while (freq[k] >= 2)
        {
            palandrome[i] = palandrome[j] = k + 'A';
            i++;
            j--;
            freq[k] -= 2;
        }
    }

    char mid = '-';

    for (int k = 0; k < 26; k++)
        if (freq[k] == 1)
        {
            if (mid == '-')
                mid = k + 'A';
            else
            {
                cout << "NO SOLUTION\n";
                return 0;
            }
        }

    if (mid != '-')
    {
        palandrome[s.size() / 2] = mid;
        freq[mid - 'A']--;
    }

    for (int k = 0; k < 26; k++)
        if (freq[k] != 0)
        {
            cout << "NO SOLUTION\n";
            return 0;
        }

    cout << palandrome;
    return 0;
}