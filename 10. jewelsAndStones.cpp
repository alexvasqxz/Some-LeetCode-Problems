//
//  Topic: Hash Table
//      Problem: Jewels and Stones
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// You're given strings J representing the types of stones that
// are jewels, and S representing the stones you have.
// Each character in S is a type of stone you have.
// You want to know how many of the stones you have are also jewels.

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
    // We will add the Jewels to a set
    // and then traverse the stones we have, every
    // time we encounter with a Jewel we just add one
    // to our counter
    int numJewelsInStones(string J, string S) {
        int count = 0;
        unordered_set<int> jewels;
        for (int i = 0; i < J.size(); i++){
            jewels.insert(J[i]);
        }
        for (int i = 0; i < S.size(); i ++){
            if (jewels.find(S[i]) != jewels.end()){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    
    string J = "Jewels";
    string S = "stonesandJes";
    
    // esJes
    // Should be 5
    
    cout << sol.numJewelsInStones(J, S) << endl;

    return 0;
}


