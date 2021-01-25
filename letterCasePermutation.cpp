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

class Solution{
public:
    
    vector<string> letterCasePermutation(string s){
        vector<string> solution;
        string temp = "";
        
        getPermutations(s,solution,temp,0);
        return solution;
    }
    
    void getPermutations(string s, vector<string>& solution, string temp, int index){
        
        if (temp.size() == s.size()){
            solution.push_back(temp);
            return;
        }
        
        if(s[index] >= '0' && s[index] < '9'){
            temp.push_back(s[index]);
            getPermutations(s,solution,temp,index+1);
            temp.pop_back();
        }
        else{
            temp.push_back(toupper(s[index]));
            getPermutations(s,solution,temp,index+1);
            temp.pop_back();
            temp.push_back(tolower(s[index]));
            getPermutations(s,solution,temp,index+1);
            temp.pop_back();
        }
        return;
    }
    
};

int main(){
    
    Solution sol;
    string s = "a1b2c3";
    vector<string> result = sol.letterCasePermutation(s);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << endl;
    }
    
    return 0;
}

