#include <iostream>
using namespace std;

/*

This looks like a backtracking DFS problem.

Frist Let's write down the basic dfs backtracking code.

First we have a visited matrix to keep track of the visited cells.

Then we have our dfs function, we can just simply do as the problem says:
    Left => x, y-1, Right => x, y+1, Up => x-1, y, Down => x+1, y
    Or if It is a '?' we can go in all 4 directions.

For the backtracking part, add the visited cell to the visited matrix, then do the dfs, then remove the visited cell from the visited matrix.

With our constraints, this will take upto 500 seconds to run, which is not acceptable.


We have to come up with a way to optimize this.

We can use the fact that we only visit the cell onces, so in the dfs, we might end up in a case where we are locked up in a subgrid, and we can't go to the destination.

we want to prevent this from happening.

We can see that we can't go to the destination if we have visited both the cells on the left and right of the current cell,
or if we have visited both the cells on the top and bottom of the current cell.

So we can add a check in the dfs function to check if we are in this case, and if we are, we can return 0.

We just start with the 7*7 grid, then we mark the cells after the border as visited, then we do the dfs.


*/

const int n = 7, m = 7;
const int destX = 7, destY = 1;
bool vis[9][9] = {0};
// vector<vector<bool>> vis(9, vector<bool>(9, false)); Gave ME AL TLE
int count_grid_paths(const string &s, int i, int x, int y)
{
    if (x <= 0 or x > n or y <= 0 or y > m)
        return 0;

    // handle the case where we are locked in a subgrid
    if ((vis[x][y - 1] and vis[x][y + 1]) and (!vis[x - 1][y] and !vis[x + 1][y]))
        return 0;
    if ((vis[x - 1][y] and vis[x + 1][y]) and (!vis[x][y - 1] and !vis[x][y + 1]))
        return 0;

    if (x == destX and y == destY) // if we reached the destination then we must be have visited all the cells
    {
        if (i == s.length())
            return 1;
        return 0;
    }

    if (i == s.length())
        return 0;

    // if (vis[x][y]) GAVE ME A TLE
    //     return 0;
    int ans = 0;
    vis[x][y] = true;
    if (s[i] == '?' or s[i] == 'U')
    {
        if (!vis[x - 1][y])
            ans += count_grid_paths(s, i + 1, x - 1, y);
    }
    if (s[i] == '?' or s[i] == 'D')
    {
        if (!vis[x + 1][y])
            ans += count_grid_paths(s, i + 1, x + 1, y);
    }
    if (s[i] == '?' or s[i] == 'L')
    {
        if (!vis[x][y - 1])
            ans += count_grid_paths(s, i + 1, x, y - 1);
    }
    if (s[i] == '?' or s[i] == 'R')
    {
        if (!vis[x][y + 1])
            ans += count_grid_paths(s, i + 1, x, y + 1);
    }
    vis[x][y] = false; // backtracking stuff
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i <= 8; i++)
    {
        vis[0][i] = true;
        vis[8][i] = true;
        vis[i][0] = true;
        vis[i][8] = true;
    }
    cout << count_grid_paths(s, 0, 1, 1);

    return 0;
}