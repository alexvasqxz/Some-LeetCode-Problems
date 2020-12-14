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
    
    TreeNode* invertTree(TreeNode* root){
        if(!root){
            return NULL;
        }
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};

int main(){
    
    return 0;
}

