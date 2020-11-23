//
//  Topic: Linked Lists
//      Problem: Middle Node
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given a linked list return its middle Node

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
    
    ListNode* middleNode(ListNode* head){
        if(!head->next){
            return head;
        }
        
        ListNode* fast = head;
        while (fast && fast->next){
            head = head->next;
            fast = fast->next->next;
        }
        return head;
        
        /* (...)
         1->2->3->4->5
         head = 1
         fast = 1
         head = 2
         fast = 3
         head = 3
         fast = 5
         !fast->next
         break
         head = 3
         (...)*/
    }
    
};

int main(){
    
    return 0;
}

