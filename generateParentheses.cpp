
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

class Solution {
public:
    vector<string> ans;
    void generateString(int n, int o, int c, string s) {

        if (o == n && c == n) {
            ans.push_back(s);
            return;
        }
        if (o < n) {
            generateString(n, o + 1, c, s + '(');
        }
        if (o > c && c < n) {
            generateString(n, o, c + 1, s + ')');
        }

    }

    vector<string> generateParenthesis(int n) {
        generateString(n, 0, 0, "");
        return ans;
    }

};

int main(){
    Solution sol;
    vector<string> par = sol.generateParenthesis(3);
    for (int i = 0; i < par.size(); i ++){
        cout << par[i] << endl;
    }
    return 0;
}

