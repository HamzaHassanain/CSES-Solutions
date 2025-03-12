#include <bits/stdc++.h>

using namespace std;

/*


First if the sum from 1 to n is not even then the answer is NO.

Second:

lets say sum = the summation of the numbers from 1 to n.
We can just build sum/2, then the other half will be the other set.

To build sum/2 we can just iterate from n to 1 and add the number to the set if it's less than or equal to sum/2.


*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;

    long long sum = n * (n + 1) / 2;

    if (sum % 2)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    vector<long long> set1, set2;
    sum /= 2;

    while (n)
    {
        if (sum - n >= 0)
        {
            set1.push_back(n);
            sum -= n;
        }
        else
        {
            set2.push_back(n);
        }
        n--;
    }

    cout << set1.size() << "\n";
    for (auto x : set1)
        cout << x << " ";

    cout << "\n"
         << set2.size() << "\n";
    for (auto x : set2)
        cout << x << " ";
    cout << "\n";

    return 0;
}