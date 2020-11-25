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
    
    ListNode* swapPairs(ListNode* head){
        if(!head){
            return NULL;
        }
        
        ListNode* previous = head;
        ListNode* node = head;
        
        while(node && node->next){
            ListNode* temp = node->next;
            node->next = temp->next;
            temp->next = node;
            if (previous != head){
                previous->next = temp;
            }
            if (node == head){
                head = temp;
            }
            previous = node;
            node = node->next;
        }
        return head;
    }
    
    /*(...)
     1->2->3->4
     previous = 1
     node = 1
     
     temp = 2->3->4
     node->next = 1->3->4
     temp->next = node 2->1->3->4
     (1->2 != 1->2)
     (1 = 1)
     head = temp // head = 2->1->3->4
     previous = 1->3->4
     node = 3->4
     
     ...
     temp = 4
     node->next = 3->null
     temp->next = 4->3->null
     (1 != 2)
     previous->next = 1->4->3
     (3 == 2)
     previous = 3->null
     node = null
     (...)*/
};

int main(){
    
    return 0;
}
