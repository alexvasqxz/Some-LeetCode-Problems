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
