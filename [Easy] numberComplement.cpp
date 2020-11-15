//
//  Topic: BitWise
//      Problem: Number Complement
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that given a positive integer, output is the complemented
// number. By definition the complement is the binary representation of
// the number with the flipped bits.

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

    int findComplement(int num) {
        // By definition the complement of its binary number
        // equals the result after applying XOR to that number
        // along with the 0111 bit (all ones);
        
        // 1. We need the bit full of ones with the same length as our number
        // 2. To do this we right shift one log2 num positions and then substract 1
        // 3. After that we just XOR our num and the number obtained in step 2
        
        long int bits = log2(num) + 1;
        
        long int ones = (1 << bits);
        
        return (ones - 1) ^ num;
        
        // Example
        // 5 = 101
        // Complement = 010 = 2
        
        // Line 40: bits = log2(num) + 1;
        // That is 3
        
        // Line 42: ones = (1 << bits)
        // That is = 1000
        
        // Line 44: (ones - 1) ^ nums
        // That is: (8 - 1) = 7 = 111
        // 111 ^ 101 (^ means XOR)
        // Which means bits with same value are 0 and
        // with different value are 1
        // 010 = 2
    }
};

int main(){
    Solution sol;

    cout << sol.findComplement(32) << endl;
    return 0;
}



