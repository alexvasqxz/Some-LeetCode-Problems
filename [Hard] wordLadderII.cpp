//
//  Topic: BFS
//      Problem: Word Ladder
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given two words (beginWord and endWord) and a dictionary wordList, find
// all shortest transformations sequences from beginWord to endWord such that:
//  - Only one letter can be changed at a time
//  - Each transformed word must exist in the word list. Note that
//    beginWord is not a transformed word

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

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList){
        vector<vector<string>> ans;
        unordered_set<string> list(wordList.begin(), wordList.end());
        unordered_set<string> visited;
        
        queue<vector<string>> q;
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()){
            return ans;
        }
        
        q.push({beginWord});
        int level = 1;
        int ansLevel = -1;
        
        while(!q.empty()){
            vector<string> temp = q.front();
            int size = temp.size();
            string lastWord = temp.back();
            q.pop();
            
            if (ansLevel > -1 && size > ansLevel){
                break;
            }
            if (size > level){
                for (auto i : visited){
                    list.erase(i);
                }
                level = size;
            }
            
            if (lastWord == endWord){
                if (ansLevel == -1){
                    ansLevel = size;
                }
                ans.push_back(temp);
            }
            
            for (int i = 0; i < endWord.size(); i++){
                for (char j = 'a'; j <= 'z'; j++){
                    if (j != lastWord[i]){
                        string temp1 = lastWord;
                        lastWord[i] = j;
                        
                        if (list.count(lastWord)){
                            temp.push_back(lastWord);
                            q.push(temp);
                            temp.pop_back();
                            visited.insert(lastWord);
                        }
                        lastWord = temp1;
                    }
                }
            }
        }
        
        return ans;
    }
};

int main(){
    
    Solution sol;
    string begin = "hit";
    string end = "cog";
    vector<string> list = {"hot","dot","dog","lot","log","cog","pot"};
    //vector<string>list = {"hot","dot","dog","lot","log","cog"};
    
    vector<vector<string>> result = sol.findLadders(begin,end,list);
    for (int i = 0; i <result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

