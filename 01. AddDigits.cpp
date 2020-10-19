//
//  Topic: Arithmetic
//      Problem: Add Digits
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Code to add all digits of an integer
// until the result has only one digit

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

    // Aproach 1
    // We iterate through the number until its residue over 10 it's
    // equal to 0 meaning we have only one digit. To do this we can see that
    // if the add the (num/10) + (num%10) we will eventually get to our
    // answer
    int addDigits(int num){
        while (num/10 != 0){
            num = (num/10) + (num%10);
        }
        return num;
    }
    
    // Approach 2
    // After trying with a broad number of examples
    // a logic was gound where we observe that the residue of a number
    // over 9 is going to give us the result
    int addDigits2(int num){
        if (num == 0){
            return 0;
        }
        if (num % 9 == 0){
            return 9;
        }
        else{
            return num%9;
        }
    }
};

int main(){
    Solution sol;
    
    int num = 327;
    cout << sol.addDigits(num) << endl;
    cout << sol.addDigits2(num) << endl;
    
    return 0;
}



