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

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution{
public:
    
    ListNode* removeElements(ListNode* head, int val){
        if(!head){
            return NULL;
        }
        
        ListNode* current = new ListNode(-1,head);
        head = current;
        
        while (current->next){
            if(current->next->val == val){
                current->next = current->next->next;
            }
            else{
                current = current->next;
            }
        }
        return head->next;
        
        /* (...)
         1->2->6->3->4->6
         current = -1->1
         head = -1->1
         // current->next->val = 1
         current = 1
         ... current = 2
         current->next->val = 6
         2->3
         
         return -1->next = 1->2->3->4
         (...)*/
    }
};

int main(){
    
    return 0;
}

