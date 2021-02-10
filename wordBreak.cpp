/*
 Given a non-empty string s and a dictionary wordDict containing a list of
 non-empty words, determine if s can be segmented into a space-separated sequence
 of one or more dictionary words.
 Note:
 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int size = s.size();
        vector<bool> dp(size+1);
        dp[0] = true;
        
        for (int i = 0; i < size; i++){
            if (!dp[i]){ continue; }
            for (int j = 0; j < wordDict.size(); j++){
                int k = i + wordDict[j].size();
                if (k <= size && s.substr(i, k - i) == wordDict[j]){
                    dp[k] = true;
                }
            }
        }
        
        return dp[size];
    }
};
