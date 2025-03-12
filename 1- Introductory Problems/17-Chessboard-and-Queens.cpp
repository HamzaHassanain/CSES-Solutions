#include <bits/stdc++.h>

using namespace std;

/*

This problem is also known as the Eight Queens problem.

The problem asks us to place eight queens on a chessboard so that no two queens attack each other.

NOTE that the reserved squares does not prevent queens from attacking each other.

A chess queen can move horizontally, vertically, or diagonally.


So we can do a backtracking solution to solve the problem.

We can try all possible ways to place the queens on the chessboard.

Given the board , for each row, we can try placing a queen in each column, and check if it is safe to place the queen in the current cell.

If it is safe, we can place the queen in the current cell and move to the next row.

If we placed 8 queens on the chessboard, we can return 1.
*/

bool isSafe(vector<string> &board, int row, int col)
{
    for (int i = 0; i < 8; i++)
    {
        if (board[row][i] == 'Q' || board[i][col] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < 8; i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }

    return true;
}

long long eightQueens(vector<string> &board, int row = 0, int count = 0)
{
    if (count == 8)
        return 1;

    long long ans = 0;
    for (int i = 0; i < 8; i++)
    {
        if (isSafe(board, row, i) and board[row][i] != 'Q' and board[row][i] != '*')
        {
            board[row][i] = 'Q';
            ans += eightQueens(board, row + 1, count + 1);
            board[row][i] = '.';
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<string> board(8);
    for (int i = 0; i < 8; i++)
        cin >> board[i];

    long long ans = eightQueens(board);
    cout << ans << '\n';
    return 0;
}