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
    
    int level = 0;
    void getZigZag(TreeNode* root, int lr, int count){
        if (!root){
            return;
        }
        level = max(level,count);
        
        if (lr == 1){
            getZigZag(root->left,1,1);
            getZigZag(root->right,2,count+1);
        }
        else{
            getZigZag(root->left,1,count+1);
            getZigZag(root->right,2,1);
        }
    }
    
    int longestZigZag(TreeNode* root){
        getZigZag(root,-1,0);
        return level;
    }
};

int main(){
    
    return 0;
}

