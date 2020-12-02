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
    
    TreeNode* mergeTrees(TreeNode* r1, TreeNode* r2){
        if (!r1){
            return r2;
        }
        if (!r2){
            return r1;
        }
        r1->val += r2->val;
        r1->left = mergeTrees(r1->left, r2->left);
        r2->right = mergeTrees(r1->right, r2->right);
        return r1;
    }
};

int main(){
    
    return 0;
}
