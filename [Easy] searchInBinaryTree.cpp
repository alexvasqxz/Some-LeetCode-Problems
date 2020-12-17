//
//  Topic: Binary Trees
//      Problem: Search in a Binary Tree
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a binary tree and an integer value, traverse
// the binary tree looking for the node containing that
// value and return it, if the value does not exist
// inside the tree return null

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
    
    TreeNode* searchBST(TreeNode* root, int val){
        if(!root){
            return NULL;
        }
        if (root->val == val){
            return root;
        }
        if (root->val < val){
            return searchBST(root->right,val);
        }
        else{
            return searchBST(root->left,val);
        }
    }
};

int main(){
    
    return 0;
}


