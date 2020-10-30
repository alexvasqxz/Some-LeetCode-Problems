//
//  Topic: Arithmetic
//      Problem: Fibonacci Number
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// The fibonacci numbers is equal to:
// F(N) = F(N-1) + F(N-2) for N > 1

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
    // Since we already have the formula to caluclate the
    // fibonacci number we can just iterate in a for loop
    // an assing to an array fo size N+1 the fibonacci number
    // for N position and return the array at N position
    // Note: We can solve this recursively as well but it takes
    // more time
    int fib(int N) {
        if (N == 0){
            return 0;
        }
        if (N == 1 || N == 2){
            return 1;
        }
        
        int fArr[N+1];
        fArr[0] = 0;
        fArr[1] = fArr[2] = 1;
        
        for (int i = 3; i <= N; i++){
            fArr[i] = fArr[i-1] + fArr[i-2];
        }
        
        return fArr[N];
    }
};

int main(){
    Solution sol;

    // 1 = 1
    // 2 = 1
    // 3 = 2
    // 4 = 3
    // 5 = 5
    // 6 = 8
    // 7 = 13
    // 8 = 21
    // 9 = 34
    // 10 = 55
    cout << sol.fib(10) << endl;
    
    return 0;
}


