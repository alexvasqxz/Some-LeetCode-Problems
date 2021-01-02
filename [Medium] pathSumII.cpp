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
    
    void getPaths(TreeNode* root, vector<vector<int>>& res, int acum, vector<int>& temp){
        
        if(!root){
            return;
        }
        temp.push_back(root->val);
        if (acum - root->val == 0 && !root->left && !root->right){
            res.push_back(temp);
        }
        else{
            getPaths(root->left,res,acum-root->val,temp);
            getPaths(root->right,res,acum-root->val,temp);
        }
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum){
        vector<vector<int>> res;
        vector<int> temp;
        
        getPaths(root,res,sum,temp);
        return res;
    }
};

int main(){
    
    return 0;
}

