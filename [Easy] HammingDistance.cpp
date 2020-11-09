//
//  Topic: BitWise
//      Problem: Hamming Distance
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that returns the humming distance between two
// integers. The humming distance is the number of positions
// in which the bits of the integers are different.

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
    // We create an array for each integer and store the bits
    // of their decimal to binary value. Then we compare both arrays.
    int hammingDistance(int x, int y) {
        if ( x == y){
            return 0;
        }
        
        int aX [32];
        int aY [32];
    
        int count = 0;
    
        for (int i = 0; i < 32; i++){
            aX[i] = aY[i] = 0;
        }
    
        for (int i = 0; i < 32; i++){
            if (x > 0){
                aX[i] = x%2;
                x /= 2;
            }
            else{
                break;
            }
        }
    
        for (int i = 0; i < 32; i++){
            if (y > 0){
                aY[i] = y%2;
                y /= 2;
            }
            else{
                break;
            }
        }
    
        for (int i = 0; i < 32; i++){
            if (aX[i] != aY[i]){
                count++;
            }
        }
        return count;
    }
};

int main(){
    Solution sol;
    
    int x = 12;
    int y = 34;
    
    // 12 = 001100
    // 34 = 100010
    // Should expect: 4
    
    cout << sol.hammingDistance(x, y) << endl;

    return 0;
}
