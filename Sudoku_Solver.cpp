#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// T.C. -> O(9 ^ m) , where m : number of empty cells
// S.C. -> O(1)
bool isSafe(int row, int col, vector<vector<char>> &board, char c)
{

    for (int i = 0; i < 9; i++)
    {

        // Check for  value already present in  same row and col
        if (board[row][i] == c || board[i][col] == c)
            return false;

        // 3*3 matrix check
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
            return false;
    }
    return true;
}

bool solve(vector<vector<char>> &board)
{

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            // Check for empty cell
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isSafe(i, j, board, c))
                    {
                        board[i][j] = c;

                        if (solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.'; // Backtrack - remove inserted value while returning from the recursive call
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}};

    cout << "\n Sudoku Before Solving : " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << " " << board[i][j] << " ";
        cout << "\n";
    }

    solve(board);

    cout << "\n \n Sudoku After Solving : " << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << " " << board[i][j] << " ";
        cout << "\n";
    }
    cout << "\n";

    return 0;
}
