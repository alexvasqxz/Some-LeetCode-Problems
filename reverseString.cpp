//
//  Topic: String Manipulation
//      Problem: Reverse String
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that reverses a string without any extra space
// for an extra array

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
    // We use two pointerss, one at the beggining and
    // the other one at the end of the string, then we just
    // swap them until the first pointer is greater or equal to
    // the second one
    void reverseString(vector<char>& s) {
        
        int index = 0;
        int end = s.size() - 1;
        
        while (index < end){
            char temp = s[index];
            s[index] = s[end];
            s[end] = temp;
            index++;
            end--;
        }
        
        for (int i = 0; i < s.size(); i++){
            cout << s[i];
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    
    vector<char>s = {'E','X','A','M','P','L','E'};
    sol.reverseString(s);

    return 0;
}
