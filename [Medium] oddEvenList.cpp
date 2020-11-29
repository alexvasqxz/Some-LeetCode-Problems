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
    
    ListNode* oddEvenList(ListNode* head){
        if(!head){
            return NULL;
        }
        if (!head->next){
            return head;
        }
        
        ListNode* startOdd = head;
        ListNode* endOdd = startOdd;
        ListNode* startEven = head->next;
        ListNode* endEven = startEven;
        ListNode* temp = new ListNode;
        
        while(endOdd->next || endEven->next){
            if (endOdd->next){
                temp = endOdd->next->next;
                endOdd->next = endOdd->next->next;
                if(temp){
                    endOdd = temp;
                }
            }
            if (endEven->next){
                temp = endEven->next->next;
                endEven->next = endEven->next->next;
                if(temp){
                    endEven = temp;
                }
            }
        }
        endOdd->next = startEven;
        
        return startOdd;
    }
    
    /*(...)
     1->2->3->4->5->N
     sO = 1
     eO = 1
     sE = 2
     eE = 2
     if (1->2)
        temp = 3->4
        eO = 1->3
        eO = 3->4
     if (2->3)
        temp = 4->5
        eE = 2->4
        eE = 4->5
     ...
     if (3->4)
        temp = 5->n
        eO = 3->5->N
        eO = 5->N
     if (4->5)
         temp = N
         eE = 4->N
     
     eO = 5->2->4->N
     (...)*/
};

int main(){
    
    return 0;
}

