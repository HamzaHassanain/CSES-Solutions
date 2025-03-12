#include <bits/stdc++.h>

using namespace std;

/*


The Tower of Hanoi is a mathematical puzzle.

It consists of three rods and a number of disks of different sizes, which can slide onto any rod.

The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.

The objective of the puzzle is to move the entire stack to another rod, obeying the following simple rules:

1- Only one disk can be moved at a time.
2- Each move consists of taking the upper disk from one of the stacks and placing it on top of another stack or on an empty rod.
3- No larger disk may be placed on top of a smaller disk.

The number of moves required to solve a Tower of Hanoi puzzle is 2^n - 1, where n is the number of disks.s

We can solve the problem using recursion

consider the following example:

if we have 3 disks, we can solve the problem as follows:
Let's first define auxiliary rod as the rod that is not the source rod or the destination rod.
                   destination rod as the rod that we want to move the disks to.
                   source rod as the rod that the disks are on.

1- move the top 2 disks to the auxiliary rod.
2- move the bottom disk to the destination rod.
3- move the top 2 disks from the auxiliary rod to the destination rod.

if we have n disks, we can solve the problem as follows:

1- move the top n - 1 disks to the auxiliary rod.
2- move the bottom disk to the destination rod.
3- move the top n - 1 disks from the auxiliary rod to the destination rod.



*/

void towerOfHanoi(int disks, int source, int auxiliary, int destination)
{
    if (disks == 1)
    {
        cout << source << ' ' << destination << '\n';
        return;
    }

    towerOfHanoi(disks - 1, source, destination, auxiliary);
    cout << source << ' ' << destination << '\n';
    towerOfHanoi(disks - 1, auxiliary, source, destination);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int disks;

    cin >> disks;

    cout << (1 << disks) - 1 << '\n';
    towerOfHanoi(disks, 1, 2, 3);

    return 0;
}