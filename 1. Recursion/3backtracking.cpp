#include <bits/stdc++.h>
using namespace std;

template <class T>
void print2DVector(vector<vector<T>> vec)
{
    cout << "[ ";
    for (auto row : vec)
    {
        cout << "[ ";
        for (auto num : row)
        {
            cout << num << " ";
        }
        cout << "]\n";
    }
    cout << " ]";
}

// 1. Flood fill algo -> (0, 0) to (n - 1, m - 1) using only paths where 0 is given, 1 means obstacle
// Print all paths, we cannot step at a same step again, answer in terms of T,L,D,R
void floodFill(vector<vector<int>> maze, int row, int col, string ans, vector<vector<bool>> &visited)
{

    if (row < 0 || col < 0 || row == maze.size() || col == maze[0].size() || maze[row][col] == 1 || visited[row][col] == true)
    {
        return;
    }

    if (row == maze.size() - 1 && col == maze[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }

    visited[row][col] = true;

    floodFill(maze, row - 1, col, ans + "T", visited);
    floodFill(maze, row, col - 1, ans + "L", visited);
    floodFill(maze, row + 1, col, ans + "D", visited);
    floodFill(maze, row, col + 1, ans + "R", visited);

    visited[row][col] = false;
}

// 2. N Queens, every row should have exactly one queen, practice it by dry run and diagram
bool isSafeQueen(vector<vector<bool>> &chess, int row, int col)
{
    // Check vertical and diagonally

    // 1. Vertical (upwards only)
    for (int i = row - 1; i >= 0; i--)
    {
        if (chess[i][col] == true)
            return false;
    }

    // 2. Check diagonally (upwards)

    // a)
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chess[i][j] == true)
            return false;
    }

    // b)
    for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++)
    {
        if (chess[i][j] == true)
            return false;
    }

    return true;
}

void nQueens(vector<vector<bool>> &chess, string ans, int row)
{

    if (row == chess.size())
    {
        cout << ans << endl;
        return;
    }

    for (int col = 0; col < chess.size(); col++)
    {
        if (isSafeQueen(chess, row, col))
        {
            chess[row][col] = 1;
            nQueens(chess, ans + to_string(row) + "-" + to_string(col) + ", ", row + 1);
            chess[row][col] = 0;
        }
    }
}

// 3. Knights Tour -> n * n chess, one knight can potentially go to 8 cells from it's initial position
// Initial position of the knight is given, we have to move knight at all cels on the chess board without re-visiting a cell
// Print all the possible configurations
void knightsTour(vector<vector<int>> &chess, int row, int col, int move)
{
    // Base Cases
    if (row < 0 || col < 0 || row > chess.size() - 1 || col > chess.size() - 1 || chess[row][col] != 0)
    {
        return;
    }

    if (move == chess.size() * chess.size())
    {
        chess[row][col] = move;
        print2DVector(chess);
        chess[row][col] = 0;
        return;
    }

    // Recurisve case
    chess[row][col] = move;
    knightsTour(chess, row - 2, col + 1, move + 1);
    knightsTour(chess, row - 1, col + 2, move + 1);
    knightsTour(chess, row + 1, col + 2, move + 1);
    knightsTour(chess, row + 2, col + 1, move + 1);
    knightsTour(chess, row + 2, col - 1, move + 1);
    knightsTour(chess, row + 1, col - 2, move + 1);
    knightsTour(chess, row - 1, col - 2, move + 1);
    knightsTour(chess, row - 2, col - 1, move + 1);
    chess[row][col] = 0;
}

int main()
{
    int n = 5, m = 4;
    string helper;

    vector<vector<int>> maze(n, vector<int>(m, 0));

    // a boolean array to find out that we visited that cell or not
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    // floodFill(maze, 0, 0, helper, visited);

    vector<vector<bool>> chess(n, vector<bool>(n, false));
    // nQueens(chess, helper, 0);

    int row = 0, col = 3;
    vector<vector<int>> chessKnights(n, vector<int>(n, 0));
    knightsTour(chessKnights, row, col, 1);

    return 0;
}