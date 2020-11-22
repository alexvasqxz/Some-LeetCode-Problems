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
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int> > q;
        set<int> values;
        
        q.push(1);
        int count = 1;
        while (!q.empty()){
            int temp = q.top();
            if (count == n){
                return temp;
            }
            q.pop();
            for (int i = 0; i < primes.size(); i++){
                if (values.find(temp * primes[i]) == values.end()){
                    values.insert(temp*primes[i]);
                    q.push(temp*primes[i]);
                }
            }
            count++;
        }
        return -1;
    }
};

int main(){
    Solution sol;
    vector<int> primes = {2,7,13,19};
    cout << sol.nthSuperUglyNumber(12, primes) << endl;
    
    
    return 0;
}
