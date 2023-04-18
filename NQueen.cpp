// TC=O(N!)

#include <bits/stdc++.h>
using namespace std;


void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n, vector<int> &left, vector<int> &upperDiagonal, vector<int> &lowerDiagonal) {
    if (col == n) {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++) {
        //check if no collision
        if (left[row] == 0 and upperDiagonal[n - 1 + col - row] == 0 and lowerDiagonal[col + row] == 0) {
            board[row][col] = 'Q';
            left[row] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            lowerDiagonal[col + row] = 1;
            solve(col + 1, board, ans, n, left, upperDiagonal, lowerDiagonal);
            board[row][col] = '.';
            left[row] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
            lowerDiagonal[col + row] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++) {
        board[i] = s;
    }
    vector<int> left(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, n, left, upperDiagonal, lowerDiagonal);
    return ans;
}

