//
//  Topic: Arrays
//      Problem: Remove Element
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that deletes the element of an array with certain
// value and returns the new length

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
    // We traverse the array of integers and whenever
    // we find an element with the value we move it
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (int i = 0; i <nums.size(); i++){
            if (nums[i] != val){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums = {2,3,4,5,6,7,8,9,2,3,4,2};
    // Length : 12
    // Expected: 9
    
    cout << sol.removeElement(nums,2) << endl;

    return 0;
}



