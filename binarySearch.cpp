//
//  Topic: Binary Search
//      Problem: Binary Search
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Function that returns the position of a number
// in a sorted vector.

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
    // We can use recursion we there is a simpler approach, which is
    // use two pointers, one at the beggining and the other one at the end,
    // then we obtain the middle value and from there we compare to the target
    // value, if it's smaller than the middle value we start moving to the left
    // and if it's greater to the right
    
    int search(vector<int>& nums, int target) {
        int mid, beg = 0, end = nums.size()-1;
        while (end >= beg){
            mid = beg + (end - beg) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] < target){
                beg = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return -1;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums = {-1,0,3,5,9,12};
    
    // If we look for 0 it should return 1
    cout << sol.search(nums, 0) << endl;
    
    // If we look for 13 it should return -1
    cout << sol.search(nums,13) << endl;
    
    return 0;
}

