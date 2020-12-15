//
//  Topic: Binary Trees
//      Problem: Same Tree
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given two binary trees create a boolean function
// that returns True if both Trees are the same,
// otherwise return false

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <set>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution{
public:
    
    bool isSameTree(TreeNode* r1, TreeNode* r2){
        if (!r1 && !r2){
            return true;
        }
        if ((r1 && !r2) || (!r1 && r2)){
            return false;
        }
        if (r1->val != r2->val){
            return false;
        }
        return isSameTree(r1->left,r2->left) && isSameTree(r1->right,r2->right);
    }
};

int main(){
    
    return 0;
}

