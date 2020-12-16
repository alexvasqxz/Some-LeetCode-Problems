//
//  Topic: Hash Tables
//      Problem: Valid Sudoku
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Determine if a 9x9 Sudoku board is valid, only the filled
// cells need to be checked for validation.
// The rules for a Sudoku validation are:
// 1. Each row must contain the 1-9 digits without repeting
// 2. Each column must contain the 1-9 digits without repeting
// 3. Each of the nine 3x3 subgrids must cointain the 1-9
// digits without repeting
// The example given in the main function is valid, but if we substitute
// the first 5 on the upper left corner for an 8 it should return
// false because we already have an 8 in the same column and subgrid

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
    
    bool isValidSudoku(vector<vector<char>>& board) {
        row = vector<unordered_set<int>>(9);
        col = vector<unordered_set<int>>(9);
        subgrid = vector<vector<unordered_set<int>>>(3, vector<unordered_set<int>>(3));
        
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board.size(); j++){
                if (board[i][j] != '.'){
                    if (row[i].count(board[i][j] - '0') || col[j].count(board[i][j] - '0')
                        || subgrid[i/3][j/3].count(board[i][j] - '0')){
                        return false;
                    }
                    row[i].insert(board[i][j] - '0');
                    col[j].insert(board[i][j] - '0');
                    subgrid[i/3][j/3].insert(board[i][j] - '0');
                }
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    
    vector<vector<char>> board =
        {{'5','3','.','.','7','.','.','.','.'}
        ,{'6','.','.','1','9','5','.','.','.'}
        ,{'.','9','8','.','.','.','.','6','.'}
        ,{'8','.','.','.','6','.','.','.','3'}
        ,{'4','.','.','8','.','3','.','.','1'}
        ,{'7','.','.','.','2','.','.','.','6'}
        ,{'.','6','.','.','.','.','2','8','.'}
        ,{'.','.','.','4','1','9','.','.','5'}
        ,{'.','.','.','.','8','.','.','7','9'}};
    
    cout << sol.isValidSudoku(board) << endl;
}
