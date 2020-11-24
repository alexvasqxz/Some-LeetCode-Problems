//
//  Topic: Linked Lists
//      Problem: Remove Duplicates
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a sorted linked list remove all elements
// that are repeated in the list (more than one
// time)

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
    
    ListNode* deleteDuplicates(ListNode* head){
        ListNode* current = head;
        ListNode* next = head;
        ListNode* prev = new ListNode(-1,head);
        ListNode* node = prev;
        
        while(next){
            int count = 0;
            while (next && current->val == next->val){
                next = next->next;
                count++;
            }
            if (count > 1){
                prev->next = next;
                current = next;
            }
            else{
                prev = current;
                current = next;
            }
        }
        
        return node->next;
    }
    
    /*(...)
     1-2->3->3->4->4->5
     current = 1
     next = 1
     prev = -1->1
     node = -1->1
     
     curr->val == next->val (1 1)
     next = 2
     count = 1
     
     count = 1
     prev = 1->2->3
     current = 2->3->3
     
     while
     2 = 2
     next = 3
     count = 1
     2 != 3
     
     count = 1
     prev = 2->3->3
     current = 3->3->4
     
     while
     3 = 3
     count = 1
     3 = 3
     count = 2
     4 != 3
     
     count > 1
     prev = 2->4->4->5
     current = 4->4->5
     
     while
     4 = 4
     count = 1
     4 = 4
     count = 2
     5 != 4
     
     count > 1
     prev = 2->5
     current = 5
     
     return node->next = prev
     (...)*/
};

int main(){
    
    return 0;
}

