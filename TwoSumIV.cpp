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
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);
        nodes.push_back(root->val);
        inorder(root->right);
    }
    
    bool twoSumBST(TreeNode* root, int sum){
        inorder(root);
        int beg = 0, end = nodes.size()-1;
        while (beg < end){
            if (beg + end == sum){
                return true;
            }
            else if (beg + end < sum){
                beg++;
            }
            else{
                end--;
            }
        }
        return false;
    }
};

int main(){
    
    return 0;
}

