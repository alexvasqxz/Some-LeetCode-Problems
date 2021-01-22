//
//  Topic: BFS / DFS
//      Problem: Flood Fill
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// An image is represented by a 2D array of integers, each integer
// representing the pixel value of the image
// Given a coordinate representing the starting pixel of the flood
// fill, and a pixel value newColor, "flood fill" the image considering
// the starting pixel plus any pixels connected 4-directionally to the
// starting pixel of the same color as the starting pixel
// At the end return the modified image

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
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

class Solution{
public:
    
    void fillGrid(vector<vector<int>>& image, int sr, int sc, int color, int oldColor){
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image.size() || image[sr][sc] != oldColor){
            return;
        }
        
        image[sr][sc] = color;
        fillGrid(image,sr+1,sc,color,oldColor);
        fillGrid(image,sr-1,sc,color,oldColor);
        fillGrid(image,sr,sc+1,color,oldColor);
        fillGrid(image,sr,sc-1,color,oldColor);
        return;
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
        if(image[sr][sc] == newColor){
            return image;
        }
        fillGrid(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
    
};

int main(){
    
    vector<vector<int>> image = {{1,0,1}, {1,1,0}, {1,0,1}};
    Solution sol;
    
    vector<vector<int>> grid = sol.floodFill(image,0,0,3);
    for (int i = 0; i < grid.size(); i++){
        for (int j = 0; j < grid[0].size(); j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
