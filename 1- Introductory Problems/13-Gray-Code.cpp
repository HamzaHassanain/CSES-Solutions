#include <bits/stdc++.h>

using namespace std;

/*

Gray code is a binary numeral system where two successive values differ in only one bit.

The number of gray codes of length n is  2^n

we can itrate over all bitmasks from 0 to 2^n - 1 and convert each bitmask to gray code.
This will cause a problem, the bitmask will not guarantee that two successive values differ in only one bit.

so we can try the following approach:

1- generate the gray codes of length n - 1.
2- add 0 to the beginning of each gray code.
3- add 1 to the beginning of each gray code in reverse order.



*/

vector<string> produceGrayCodes(int n)
{
    if (n == 1)
        return {"0", "1"};

    vector<string> grayCodes = produceGrayCodes(n - 1);

    vector<string> result;
    for (string code : grayCodes)
    {
        result.push_back("0" + code);
    }
    for (int i = grayCodes.size() - 1; i >= 0; i--)
    {
        result.push_back("1" + grayCodes[i]);
    }

    return result;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<string> grayCodes;

    grayCodes = produceGrayCodes(n);
    for (string code : grayCodes)
        cout << code << '\n';

    return 0;
}