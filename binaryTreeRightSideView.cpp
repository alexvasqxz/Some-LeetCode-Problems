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
    
    int maxHeight = 0;
    vector<int> traverseTree(TreeNode* root, int height, vector<int>& res){
        height += 1;
        if (!root){
            return res;
        }
        if (height > maxHeight){
            res.push_back(root->val);
            maxHeight = height;
        }
        res = traverseTree(root->left, height, res);
        res = traverseTree(root->right, height, res);
        
        return res;
    }
    
    vector<int> rightSideView(TreeNode* root){
        vector<int> res;
        int height = 0;
        
        traverseTree(root,height,res);
        return res;
    }
};

int main(){
    
    return 0;
}
