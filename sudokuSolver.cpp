
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <queue>
#include <set>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    
    vector<unordered_set<int>> row, col;
    vector<vector<unordered_set<int>>> subgrid;
    vector<int> solverow, solvecol;
    
    void solveSudoku(vector<vector<char>>& board) {
        col = vector<unordered_set<int>>(9);
        row = vector<unordered_set<int>>(9);
        subgrid = vector<vector<unordered_set<int>>>(3, vector<unordered_set<int>>(3));
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                if (board[i][j] == '.'){
                    solverow.push_back(i);
                    solvecol.push_back(j);
                }
                else{
                    row[i].insert(board[i][j] - '0');
                    col[j].insert(board[i][j] - '0');
                    subgrid[i/3][j/3].insert(board[i][j] - '0');
                }
            }
        }
        
        fillBoard(board, 0);
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                cout << board[i][j] << ' ';
            }
            cout << endl;
        }
    }
    
    bool fillBoard(vector<vector<char>>& b, int index){
        if (index == solvecol.size()){
            return true;
        }
        int r = solverow[index];
        int c = solvecol[index];
        for (int n = 1; n <= 9; n++){
            if (!row[r].count(n) && !col[c].count(n) && !subgrid[r/3][c/3].count(n)){
                b[r][c] = to_string(n)[0];
                row[r].insert(n);
                col[c].insert(n);
                subgrid[r/3][c/3].insert(n);
                if (fillBoard(b, index+1)){
                    return true;
                }
                b[r][c] = '.';
                row[r].erase(n);
                col[c].erase(n);
                subgrid[r/3][c/3].erase(n);
            }
        }

        return false;
    }
};

int main(){
    Solution sol;
    vector<vector<char>> board = {{'8','.','.','5','.','.','.','6','9'},
                                  {'6','.','2','.','9','.','7','.','.'},
                                  {'.','.','5','.','4','.','1','8','.'},
                                  {'7','.','9','2','.','.','3','.','6'},
                                  {'.','3','.','.','.','.','.','1','.'},
                                  {'1','.','8','.','.','4','9','.','7'},
                                  {'.','8','6','.','1','.','2','.','.'},
                                  {'.','.','3','.','6','.','8','.','1'},
                                  {'4','1','.','.','.','9','.','.','5'}};
    
    sol.solveSudoku(board);
    
    return 0;
}
