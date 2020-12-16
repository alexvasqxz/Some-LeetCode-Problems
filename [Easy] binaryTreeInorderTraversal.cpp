//
//  Topic: Binary Trees
//      Problem: Inorder Traversal
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a binary tree, store its elements value
// using Inorder Traversal

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
    
    vector<int> inorder;
    vector<int> inorderTraversal(TreeNode* root){
        if (!root){
            return inorder;
        }
        
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
        
        return inorder;
    }
};

int main(){
    
    return 0;
}

