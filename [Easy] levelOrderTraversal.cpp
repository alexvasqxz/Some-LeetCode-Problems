//
//  Topic: Binary Trees
//      Problem: Level Order Traversal
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a binary tree, return the bottom up level order
// traversal of its node's values (from left to right)

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
    
    vector<int> nodes;
    
    int getHeight(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        
        return right > left ? right+1 : left+1;
    }
    
    void getNodes(TreeNode* root, int level){
        if(!root || level == 0){
            return;
        }
        if (level == 1){
            nodes.push_back(root->val);
            return;
        }
        getNodes(root->left, level-1);
        getNodes(root->right, level-1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int height = getHeight(root);
        vector<vector<int>> res;
        for (int i = height; i > 0; i--){
            getNodes(root,i);
            res.push_back(nodes);
            nodes.clear();
        }
        return res;
    }
};

// BFS Solution
class Solution{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root){
        if (!root){
            return {};
        }
        vector<vector<int>> ret;
        stack<vector<int>> mySt;
        deque<TreeNode*> myQue;
        myQue.emplace_back(root);
        while (!myQue.empty()){
            int n = myQue.size();
            vector<int> temp;
            for (int i = 0; i < n; i++){
                auto node = myQue.front();
                myQue.pop_front();
                if (node->left){
                    myQue.emplace_back(node->left);
                }
                if (node->right){
                    myQue.emplace_back(node->right);
                }
                temp.emplace_back(node->val);
            }
            mySt.push(temp);
        }
        while (!mySt.empty()){
            ret.emplace_back(mySt.top());
            mySt.pop();
        }
        return ret;
    }
};

int main(){
    
    return 0;
}

