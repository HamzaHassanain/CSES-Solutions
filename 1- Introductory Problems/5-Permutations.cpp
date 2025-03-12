#include <bits/stdc++.h>

using namespace std;

/*

A permutation of n integers  is called beautiful if there are no adjacent elements whose difference is 1.
Given n, construct a beautiful permutation if such a permutation exists.


First:
    if n is 1, then the permutation is 1
    if n is less than 4, then there is no beautiful permutation

Second:

    we can just start from 1 and increment by 2 until we reach n
    then start from 2 and increment by 2 until we reach n
    then print the permutation

    Do not forget to handle the case when n is 4 by printing 2 4 1 3

*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> p(n);

    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    if (n < 4)
    {
        cout << "NO SOLUTION";
        return 0;
    }

    if (n == 4)
    {
        cout << "2 4 1 3";
        return 0;
    }

    int i = 1;
    for (int j = 0; j < n; j += 2)
    {
        p[j] = i;
        i++;
    }

    for (int j = 1; j < n; j += 2)
    {
        p[j] = i;
        i++;
    }

    for (int x : p)
    {
        cout << x << " ";
    }

    return 0;
}