//
//  Topic: Hash Table
//      Problem: Sort Colors
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given an array with n objects sort them in place that the
// objects with the same value are adjacent to one another
// Example
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

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

    //Approach
    // We create a map that saves the values of each
    // distinct number and the number of times it's in the
    // array. Then we traverse the map by changing the original
    // values of the array with the ones in the map
    
    void sortColors(vector<int>& nums){
        map<int,int> colors;
        
        for (int i = 0; i<nums.size(); i++){
            if (colors.find(nums[i]) != colors.end()){
                colors[nums[i]]++;
            }
            else{
                colors[nums[i]] = 1;
            }
        }
        
        int j = 0;
        for (auto i: colors){
            while (i.second > 0){
                nums[j] = i.first;
                i.second--;
                j++;
            }
        }
        
        for (int i = 0; i < nums.size(); i++){
            cout << nums[i];
        }
        cout << endl;
    }
};

int main(){
    Solution sol;
    
    vector<int> nums = {2,3,2,3,1,1,1,0,2,0,3,1};
    sol.sortColors(nums);
    
    return 0;
}


