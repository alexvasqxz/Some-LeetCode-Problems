//
//  Topic: BFS
//      Problem: N-ary Tree Level Order Traversal
//
//  Created by Gustavo Vasquez
//  Copyright © 2021 Alex Vasquez. All rights reserved.

/*
 Given an n-ary tree, return the level order traversal of its nodes' values.

 Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value
 */

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <queue>
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

// Definition of a node
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        queue<Node*> q;
        if (!root){
            return result;
        }
        q.push(root);
        
        while (!q.empty()){
            int size = q.size();
            vector<int>temp;
            for (int i = 0; i < size; i++){
                Node* node = q.front();
                q.pop();
                temp.push_back(node->val);
                for (int j = 0; j < node->children.size(); j++){
                    q.push(node->children[j]);
                }
            }
            result.push_back(temp);
        }
        
        return result;
    }
};

int main(){
    Solution sol;

    return 0;
}

