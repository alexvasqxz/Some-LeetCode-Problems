//
//  Topic: Backtracking
//      Problem: N Queens
//
//  Created by Gustavo Vasquez
//  Copyright © 2021 Alex Vasquez. All rights reserved.

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard
// such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle.
// Each solution contains a distinct board configuration of the n-queens'
// placement, where 'Q' and '.' both indicate a queen and an empty space,
// respectively.

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
    set<pair<int,int>> squares;
    vector<vector<string>> ans;
    
    bool isValid(int i, int j){
        if (squares.empty()){
            return true;
        }
        pair<int,int> p = {i,j};
        for (auto q : squares){
            if (p.first == q.first || p.second == q.second){
                return false;
            }
            float m =  abs((float)(p.first - q.first)/(p.second - q.second));
            if (m == 1.0){
                return false;
            }
        }
        return true;
    }
    
    void queens(int col, int n){
        if (col == n){
            createVector(n);
        }
        for (int row = 0; row < n; row++){
            if(isValid(row,col)){
                squares.insert({row,col});
                queens(col+1,n);
                squares.erase({row,col});
            }
        }
    }

    void createVector(int n){
        vector<string> temp;
        for (int i = 0; i < n; i++){
            string s = "";
            for (int j = 0; j < n; j++){
                if (squares.find({i,j}) != squares.end()){
                    s += "Q";
                }
                else{
                    s += ".";
                }
            }
            temp.push_back(s);
        }
        ans.push_back(temp);
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        queens(0,n);
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<string>> Queens = sol.solveNQueens(5);
    for (int i = 0; i < Queens.size(); i++){
        for (int j = 0; j < Queens[i].size(); j++){
            cout << Queens[i][j] << endl;
        }
        cout << endl;
    }
    
    return 0;
}
