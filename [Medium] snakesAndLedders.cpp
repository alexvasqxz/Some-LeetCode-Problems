//
//  Topic: BFS
//      Problem: Snakes and Ladders
//
//  Created by Gustavo Vasquez
//  Copyright © 2021 Alex Vasquez. All rights reserved.

// On an NXN board, the numbers from 1 to N*N are written starting from
// the bottom left of the board, and alternating direction each row.
// You start on square 1 of the board, and each move consists of:
// - You choose a square from x+1 to x+6
// - If s has a snake or ladder, you move to the destination of that snake
//   or ladder
// Return the least number of moves required to reach square N*N

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
    
    int snakesAndLadders(vector<vector<int>>& board) {
        if (board.size() == 0){
            return -1;
        }
        if (board.size() == 1){
            return 0;
        }
        
        // Create square array
        vector<int> squares;
        bool isEven = board.size()%2 == 0 ? true : false;
        if (isEven){
            for (int i = board.size()-1; i >= 0; i--){
                if (i%2 == 0){
                    for (int j = board.size()-1; j >= 0; j--){
                        squares.push_back(board[i][j]);
                    }
                }
                else{
                    for (int j = 0; j < board.size(); j++){
                        squares.push_back(board[i][j]);
                    }
                }
            }
        }
        if(!isEven){
            for (int i = board.size()-1; i >= 0; i--){
                if (i%2 == 0){
                    for (int j = 0; j < board.size(); j++){
                        squares.push_back(board[i][j]);
                    }
                }
                else{
                    for (int j = board.size()-1; j >= 0; j--){
                        squares.push_back(board[i][j]);
                    }
                }
            }
        }
        
        if (squares.size() <= 6){
            return 1;
        }
        
        queue<pair<int,int>> q;
        unordered_set<int> visited;
        q.push({0,0});
        int level = 0;
        
        while(!q.empty()){
            pair<int,int> temp = q.front();
            
            if (temp.first >= squares.size() -1){
                return temp.second;
            }
            q.pop();
            
            for (int i = 1; i <= 6; i++){
                pair<int,int> c = {temp.first+i, temp.second+1};
                
                if (squares[c.first] != -1 && visited.find(squares[c.first]-1) == visited.end()){
                    visited.insert(squares[c.first]-1);
                    q.push({squares[c.first]-1, c.second});
                }
                
                if (squares[c.first] == -1 && visited.find(c.first) == visited.end()){
                    visited.insert(c.first);
                    q.push({c.first, c.second});
                }
            }
            level++; // 1 -> 14 -> 16 -> 12 -> 13 -> 34 -> 35
        }
        return -1;
    }
};

int main(){
    Solution sol;
    
    vector<vector<int>> board = {
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,35,-1,-1,13,-1},
        {-1,-1,-1,-1,-1,-1},
        {-1,15,-1,-1,-1,-1}};
    
    cout << sol.snakesAndLadders(board) << endl;
    
    return 0;
}

