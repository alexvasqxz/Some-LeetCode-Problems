//
//  Topic: Binary Trees
//      Problem: Average of Levels
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a non empty binary tree, return the average value of the nodes
// on each level in the form of an array

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
    
    vector<double> values;
    double sum = 0;
    
    vector<double> averageOfLevels(TreeNode* root) {
        values.push_back(root->val);
        int height = maxDepth(root);
        for (int i = 2; i <= height; i++){
            int n = getAverage(root,i);
            values.push_back(sum/n);
            sum = 0;
        }
        return values;
    }
    
    int getAverage(TreeNode* root, int level){
        if (!root){
            return 0;
        }
        else if (level == 1){
            sum += root->val;
            return 1;
        }
        else{
            return getAverage(root->right, level-1) + getAverage(root->left, level-1);
        }
    }
    
    int maxDepth(TreeNode* root) {
        if (!root){
            return 0;
        }
        
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        
        return left > right ? left + 1: right + 1;
    }
    
    // BFS Solution
    int depth(TreeNode* root){
        if (!root){
            return 0;
        }
        return 1 + max(depth(root->left), depth(root->right));
    }
    
    vector<double> averageofLevelsBFS(TreeNode* root){
        int size = depth(root);
        vector<double> arr(size, 0);
        vector<double> count(count, 0);
        queue<pair<TreeNode*, int> bfs;
        bfs.push({root, 0});
        
        while (!bfs.empty()){
            auto curr = bfs.front();
            bfs.pop();
            if (curr.first){
                arr[curr.second] += (curr.first->val);
                count[curr.second] += 1;
                bfs.push({curr.first->left, curr.second+1});
                bfs.push({curr.first->right, curr.second+1});
            }
        }
        for (int i = 0; i < size; i++){
            arr[i] /= count[i];
        }
        return arr;
    }
};

int main(){
    
    return 0;
}

