//
//  Topic: Hash Table
//      Problem: Uncommon Words
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// A word is uncommon if it appears exactly once in one
// of the sentences, and does not appear in the other sentence.

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:

    // Approach
    // We will concatenate both words and the traverse the
    // new string, we will add every word (set of chars before a space)
    // to a map with a counter
    // Then we just traverse the map and append to our result the
    // words with a count of 1
    
    vector<string> uncommonFromSentences(string A, string B) {
        string both = A + " " + B;
        map<string, int> words;
        string word;
        for (int i = 0; i < both.size(); i++){
            if (both[i+1] == ' ' || !both[i+1]){
                word += both[i];
                if (words.find(word) != words.end()){
                    words[word]++;
                    word = "";
                }
                else{
                    words[word] = 1;
                    word = "";
                }
            }
            else if (both[i] != ' '){
                word += both[i];
            }
        }
            
        vector<string> result;
        for (auto i : words){
            if (i.second == 1){
                result.push_back(i.first);
            }
        }
        return result;
        
    }
};

int main(){
    Solution sol;
    
    string A = "This is the first example";
    string B = "This is the second example";
    
    // Should return first and second
    vector<string> R = sol.uncommonFromSentences(A, B);
    for (int i = 0; i < R.size(); i++){
        cout << R[i] << endl;
    }
    
    return 0;
}

