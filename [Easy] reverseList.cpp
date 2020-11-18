//
//  Topic: Linked Lists
//      Problem: Reverse Linked List
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a linked list create a function that
// reverses it, meaning, the head node is now the
// last node

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
    
    ListNode* reverseList(ListNode *head){
        if (!head){
            return NULL;
        }
        if (!head->next){
            return head;
        }
        
        ListNode* result = new ListNode(head->val, NULL);
        head = head->next;
        
        while(head){
            ListNode *node = new ListNode(head->val,result);
            result = node;
            head = head->next;
        }
        return result;
        
        /* 1->2->3->4
           (...)
           result = 1
           head = 2
           node = 2->1
           result = 2->1
           head = 3
           node = 3->2->1
           result = 3->2->1
           (...)
         */
    }
    
};

int main(){
    
    return 0;
}

