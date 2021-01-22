//
//  Topic: BFS
//      Problem: Word Ladder
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// A transformation sequence from word beginWord to word endWord using a
// dictionary wordList is a sequence such that:
// - The first word in the sequence is beginWord
// - The last word is endWord
// - Only one letter is different between each adjacent pair of words
//   in the sequence
// - Every word in the sequence is in the wordList dictionary
// Given two word return the number of words in the shortest
// transformation sequence from beginWord to endWord

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

class Solution{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> wordSet(wordList.begin(),wordList.end()), visited;
        if (wordSet.find(endWord) == wordSet.end()){
            return 0;
        }
        queue<pair<string,int>> words;
        words.push({beginWord,1});
        while(!words.empty()){
            pair<string,int> temp = words.front();
            words.pop();
            if (temp.first == endWord){
                return temp.second;
            }
            string originalWord = temp.first;
            for (int index = 0; index < originalWord.size(); index++){
                for (char c = 'a'; c <= 'z'; c++){
                    temp.first[index] = c;
                    if (wordSet.find(temp.first) != wordSet.end() && visited.find(temp.first) == visited.end()){
                        words.push({temp.first,temp.second+1});
                        visited.insert(temp.first);
                    }
                }
                temp.first = originalWord;
            }
        }
        
        return 0;
    }
};

int main(){
    
    Solution sol;
    string begin = "hit";
    string end = "cog";
    vector<string> list = {"hot","dot","dog","lot","log","cog","pot"};
    //vector<string>list = {"hot","dot","dog","lot","log","cog"};
    
    cout << sol.ladderLength(begin,end,list) << endl;
    return 0;
}
