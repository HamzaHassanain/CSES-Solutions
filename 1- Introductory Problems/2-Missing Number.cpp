#include <bits/stdc++.h>

using namespace std;

/*


What the problem describes is also called a mex, witch is the minimum excludant of a set of numbers.

This problem can be solved in diffrent ways

We well look at the easiest way to solve it,
sort the array and iterate over it, if the current number is not equal to the index , then the answer is the index .


We also can do an xor operation on the array and the numbers from 1 to n, the result will be the missing number.

We also can itrate over the array, then swap the ith element with the element at the index of the ith element,
then iterate over the array again to find the missing number.

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n;
    cin >> n;

    vector<long long> v(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> v[i];

    sort(v.begin(), v.end());
    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] != i + 1)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << n;

    // // xor solution
    long long allXor = 0;
    for (int i = 1; i <= n; i++)
        allXor ^= i;

    for (int i = 0; i < n - 1; i++)
        allXor ^= v[i];

    cout << allXor;

    // swap solution
    for (int i = 0; i < n - 1; i++)
    {
        while (v[i] != i + 1 && v[i] < n)
        {
            swap(v[i], v[v[i] - 1]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (v[i] != i + 1)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << n;

    return 0;
}