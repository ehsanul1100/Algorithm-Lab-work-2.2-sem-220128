#include "bits/stdc++.h"
using namespace std;
int isSafe(vector<vector<int>> &board, int row, int col)
{
    int n = board.size();
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    for (i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    for (i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

int placeQueens(int row, vector<vector<int>> &board)
{
    int n = board.size();
    if (row == n)
        return 1;

    for (size_t i = 0; i < n; i++)
    {
        if (isSafe(board, row, i))
        {
            board[row][i] = 1;
            if (placeQueens(row + 1, board))
            {
                return 1;
            }
            board[row][i] = 0;
        }
    }
    return 0;
}
vector<int> nQueen(int queens)
{
    vector<vector<int>> board(queens, vector<int>(queens, 0));
    if (placeQueens(0, board))
    {
        vector<int> answer(queens, -1);
        for (size_t i = 0; i < queens; i++)
        {
            for (size_t j = 0; j < queens; j++)
            {
                if (board[i][j])
                {
                    answer[i] = j + 1;
                }
            }
        }

        return answer;
    }
    else
    {
        return {-1};
    }
}
int main()
{
    int queens;
    cout << "Enter number of queens: ";
    cin >> queens;
    vector<int> answer(queens);
    answer = nQueen(queens);
    for (auto i : answer)
    {
        cout << i << " ";
    }

    cout << endl;
    return 0;
}