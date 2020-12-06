//
//  Topic: Binary Trees
//      Problem: Maximum Depth of Binary Tree
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a binary tree return its maximum
// depth, meaning, the greater numbers of levels from
// the right vs left side

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
    
    int maxDepth(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return left > right ? left+1 : right+1;
    }
};

int main(){
    
    return 0;
}
