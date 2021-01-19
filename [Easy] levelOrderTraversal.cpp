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

int main(){
    
    return 0;
}

