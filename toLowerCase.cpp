//
//  Topic: String Manipulation
//      Problem: To Lower Case
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that takes a string as a parameter and
// returns it in lowercase

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
    // We traverse the stirng and whenever we find a
    // char in uppercase we conver it to lowercase using
    // the ASCII values
    string toLowerCase(string str){
        for (int i = 0; i < str.size(); i++){
            if (str[i] >= 65 && str[i] <=90){ // The char is uppercase
                str[i] += 32;
            }
        }
        
        return str;
    }
};

int main(){
    Solution sol;
    
    string str = "ThisISanEXAMPLE";
    cout << sol.toLowerCase(str) << endl;

    return 0;
}
