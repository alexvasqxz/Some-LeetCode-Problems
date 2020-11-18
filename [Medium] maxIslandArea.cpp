//  Topic: DFS
//      Problem: Max Area of Island
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a matrix containing 0's and 1's where
// the ones represent land and the zeros represent sea
// find the island with the greates area, and island is 
// a set of ones that are adjacent to each other (either
// horizontally or vertically)

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
    
    int maxArea = 0;
    int temp = 0;
    
    void getArea(vector<vector<int>>& grid, int r, int c){
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == 0){
            return;
        }
        
        temp++;
        grid[r][c] = 0;
        getArea(grid,r+1,c);
        getArea(grid,r-1,c);
        getArea(grid,r,c+1);
        getArea(grid,r,c-1);
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    getArea(grid, i, j);
                }
                maxArea = max(temp,maxArea);
                temp = 0;
            }
        }
        return maxArea;
    }
};

int main(){
    Solution sol;
    
    vector<vector<int>> grid = {{1,1,0,1,1},
                                {1,0,0,0,0},
                                {0,0,0,0,1},
                                {1,1,0,1,1}};
    
    cout << sol.maxAreaOfIsland(grid) << endl;
    
    return 0;
}
