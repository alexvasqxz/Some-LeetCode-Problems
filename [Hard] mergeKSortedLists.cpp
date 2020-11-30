≈#include <stdio.h>
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

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution{
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists){
        if (lists.size() == 0){
            return NULL;
        }
        vector<int> data;
        for (int i = 0; i < lists.size(); i++){
            ListNode* node = lists[i];
            while(node){
                data.push_back(node->val);
                node=node->next;
            }
        }
        if (data.size() == 0){
            return NULL;
        }
        
        sort(data.begin(), data.end());
        int value = data[0];
        ListNode* startResult = new ListNode(value);
        ListNode* endResult = startResult;
        
        for (int i = 1; i < data.size(); i++){
            value = data[i];
            ListNode* temp = new ListNode(value);
            endResult->next = temp;
            endResult = temp;
        }
        return startResult;
    }
};

int main(){
    
    return 0;
}
