//
//  Topic: BFS
//      Problem: Rotting Oranges
//
//  Created by Gustavo Vasquez
//  Copyright © 2021 Alex Vasquez. All rights reserved.

/*
 You are given an m x n grid where each cell can have one of three values:

 0 representing an empty cell,
 1 representing a fresh orange, or
 2 representing a rotten orange.
 Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

 Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
 */

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
    
    bool isWithinParameters(int r, int c, int R, int C){
        if (r < 0 || c < 0 || r >= R || c >= C){
            return false;
        }
        return true;
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        queue<pair<pair<int,int>,int>> O;
        int rr[4] = {1,-1,0,0};
        int cr[4] = {0,0,1,-1};
        
        for (int i = 0; i < R; i++){
            for (int j = 0; j < C; j ++){
                if (grid[i][j] == 2){
                    O.push({{i,j},0});
                }
            }
        }
        int ans = 0;
        while (!O.empty()){
            pair<pair<int,int>, int> temp = O.front();
            O.pop();
            ans = max(ans, temp.second);
            for (int k = 0; k < 4; k++){
                int row = temp.first.first + rr[k];
                int col = temp.first.second + cr[k];
                if (isWithinParameters(row, col, R, C) && grid[row][col] == 1){
                    grid[row][col] = 2;
                    O.push({{row, col}, temp.second + 1});
                }
            }
        }
        
        
        for (int i = 0; i < R; i ++){
            for (int j = 0; j < C; j++){
                if (grid[i][j] == 1){
                    return -1;
                }
            }
        }
        
        return ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> oranges = {{0,1,1,2},{0,1,1,0},{1,1,2
        ,0}};
    cout << sol.orangesRotting(oranges) << endl;
    
    return 0;
}
