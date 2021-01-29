
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
    
    set<pair<int,int>> visited;
    bool found = false;
    string temp = "";
    
    void findWord(vector<vector<char>>& board, string word, int r, int c, int i){
        pair<int,int> p = {r,c};
        if (r<0 || c<0 || r>=board.size() || c>=board[0].size() || board[r][c] != word[i]  || visited.find(p) != visited.end()){
            return;
        }
        
        visited.insert(p);
        if (board[r][c] == word[i]){
            temp += word[i];
            
            if (temp == word){
                found = true;
                return;
            }
            
            findWord(board,word,r+1,c,i+1);
            findWord(board,word,r-1,c,i+1);
            findWord(board,word,r,c+1,i+1);
            findWord(board,word,r,c-1,i+1);
            temp.pop_back();
            visited.erase({r,c});
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (board[i][j] == word[0]){
                    findWord(board,word,i,j,0);
                    if (found){
                        return true;
                    }
                    temp = "";
                    visited.clear();
                }
            }
        }
        return found;
    }
};

int main(){
    Solution sol;
    string word = "ABCESEEEFS";
    vector<vector<char>> board = {{'A','B','C','E'},
                                  {'S','F','E','S'},
                                  {'A','D','E','E'}};
    if(sol.exist(board,word)){
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;
    
    return 0;
}
