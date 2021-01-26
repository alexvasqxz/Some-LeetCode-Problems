
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
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads(deadends.begin(), deadends.end());
        string start = "0000";
        if (deads.find(target) != deads.end() || deads.find(start) != deads.end()){
            return -1;
        }
        if (start == target){
            return 0;
        }
        
        queue<string> q;
        q.push(start);
        
        unordered_set<string> temp;
        temp.insert(start);
        int ans = 0;
        
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i ++){
                string s = q.front();
                q.pop();
                for (int j = 0; j < 4; j++){
                    string t1 = s;
                    string t2 = s;
                    
                    t1[j]--;
                    t1[j] < '0' ? t1[j] = '9' : t1[j] = t1[j];
                    t2[j]++;
                    t2[j] > '9' ? t2[j] = '0' : t2[j] = t2[j];
                    
                    if (t1 == target || t2 == target){
                        return ans + 1;
                    }
                    if (temp.find(t1) == temp.end() && deads.find(t1) == deads.end()){
                        temp.insert(t1);
                        q.push(t1);
                    }
                    if (temp.find(t2) == temp.end() && deads.find(t2) == deads.end()){
                        temp.insert(t2);
                        q.push(t2);
                    }
                }
            }
            ans++;
        }
        return -1;
    }

};

int main(){
    Solution sol;
    vector<string> deadEnds = {"8887","8889","8878","8898","8788","8988","7888","9888"};
    string target = "8888";
    cout << sol.openLock(deadEnds, target) << endl;
    
    return 0;
}
