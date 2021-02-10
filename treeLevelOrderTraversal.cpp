
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

