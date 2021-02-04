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
    
    map<pair<int,int>, int> visited;
    
    void rotOranges(vector<vector<int>>& grid, int r, int c, int minutes){
        pair<int,int> p = {r,c};
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0){
            return;
        }
        
        if (visited.find(p) != visited.end()){
            if (minutes < visited[p]){
                visited[p] = minutes;
            }
            else if (grid[r][c] == 3){
                return;
            }
        }
        else{
            visited[p] = minutes;
        }
        grid[r][c] = 3;
        rotOranges(grid,r+1,c,minutes+1);
        rotOranges(grid,r-1,c,minutes+1);
        rotOranges(grid,r,c+1,minutes+1);
        rotOranges(grid,r,c-1,minutes+1);
    }
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        int minutesAns = 0;
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 2){
                    vector<vector<int>> temp = grid;
                    rotOranges(temp,i,j,0);
                }
            }
        }
        
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1 && visited.find({i,j}) == visited.end()){
                    return -1;
                }
            }
        }
        
        for (auto it : visited){
            if (it.second > minutesAns){
                minutesAns = it.second;
            }
        }
        return minutesAns;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> oranges = {{0,1,1,2},{0,1,1,0},{1,1,2,0}};
    cout << sol.orangesRotting(oranges) << endl;
    
    return 0;
}
