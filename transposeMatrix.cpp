//
//  Topic: Arrays
//      Problem: Transpose Matrix
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// The transpose of a matrix is the matrix flipped over
// it's main diagonal, switching the row and column
// indices of the matrix.

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <list>
#include <string>
#include <sstream>
#include <iterator>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:

    // Approach
    // We will save the values of each column
    // in a vector and append it to a vector of
    // vector to later it return it as the result
    
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int temp = 0;
        vector<vector<int>> B;
        for (int i = 0; i < A[0].size(); i++){
            vector<int> BB;
            for (int j = 0; j < A.size(); j++){
                BB.push_back(A[j][i]);
            }
            B.push_back(BB);
            BB.clear();
        }
        return B;
    }
};

int main(){
    Solution sol;

    // 1 2 3
    // 4 5 6
    // 7 8 9
    
    // 1 4 7
    // 2 5 8
    // 3 6 9
    
    vector<vector<int>> A = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> B = sol.transpose(A);
    
    for (int i = 0; i < B.size(); i++){
        for (int j = 0; j < B[0].size(); j++){
            cout << B[i][j];
        }
        cout << endl;
    }

    return 0;
}


