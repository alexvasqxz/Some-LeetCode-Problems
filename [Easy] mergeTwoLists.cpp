//
//  Topic: Linked Lists
//      Problem: Merge two sorted lists
//
//  Created by Gustavo Vasquez
//  Copyright © 2020 Alex Vasquez. All rights reserved.

// Given two sorted linked lists merge both of them
// returning a single linked lists with all of the values
// sorted

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
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2){
        if (!l1 && l2){
            return NULL;
        }
        if (!l1){
            return l2;
        }
        if (!l2){
            return l1;
        }
        
        ListNode *dummy = NULL;
        ListNode *dummyEnd = NULL;
        
        while (l1 && l2){
            if (l1->val < l2->val){
                if (!dummy){
                    dummy = l1;
                    dummyEnd = dummy;
                }
                else{
                    dummyEnd->next = l1;
                    dummyEnd = l1;
                }
            }
            else{
                if (!dummy){
                    dummy = l2;
                    dummyEnd = dummy;
                }
                else{
                    dummyEnd->next = l2;
                    dummyEnd = l2;
                }
            }
        }
        
        if (l1){
            dummyEnd->next = l1;
        }
        if (l2){
            dummyEnd->next = l2;
        }
        return dummy;
    }
    
};

int main(){
    
    return 0;
}

