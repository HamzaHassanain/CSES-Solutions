#include <bits/stdc++.h>

using namespace std;

/*


You are given an array of n integers. You want to modify the array so that it is increasing
, i.e., every element is at least as large as the previous element.



We can just check if the current is less than or equal to the previous element, then add the difference between the two elements to the answer.
then set the current element to the previous element

then repeat the process until we reach the end of the array.

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        ans += max(0, a[i - 1] - a[i]);
        a[i] = max(a[i], a[i - 1]);
    }
    cout << ans;

    return 0;
}