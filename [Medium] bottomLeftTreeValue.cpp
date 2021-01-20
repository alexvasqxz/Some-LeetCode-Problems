//
//  Topic: Binary Trees
//      Problem: Find Bottom Left Tree Value
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given the root of a binary tree, return the
// leftmost value in the last row of the tree.

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
    
    int max = 0;
    int ans = 0;
    
    int traverse(TreeNode* root, int height){
        height++;
        if(!root){
            return height;
        }
        if (height > max){
            ans = root->val;
            max = height;
        }
        traverse(root->left,height);
        traverse(root->right, height);
        return ans;
    }
    
    int findBottomLeftValue(TreeNode* root){
        return traverse(root,0);
    }
};

int main(){
    
    return 0;
}
