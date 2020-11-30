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
    
    ListNode* reverseBetween(ListNode* head, int i, int j){
        if(!head){
            return NULL;
        }
        ListNode* current = head;
        ListNode* previous = NULL;
        
        while (i > 1){
            previous = current;
            current = current->next;
            i--;
            j--;
        }
        ListNode* temp = previous;
        ListNode* end = current;
        ListNode* node = NULL;
        while (j > 0){
            node = current->next;
            current->next = previous;
            previous = current;
            current = node;
            j--;
        }
        if (temp){
            temp->next = previous;
        }
        else{
            head = previous;
        }
        end->next = current;
        return head;
    }
    
    /*(...)
     1->2->3->4->5->N // 1->4->3->2->5->N
     current = 1->2
     previous
     while (2 > 1)
     previous = 1->2->3
     current = 2->3->4
     
     temo = 1->2
     end = 2->3
     node
     while (3 > 0)
        node = 3->4->5
        curr = 2->1->2->3
        prev = 2->1->2->3
        curr = 3->4->5
        j = 2
        node = 4->5->N
        curr = 3->2->1->2
        prev = 3->2->1
        curr = 4->5->N
        j = 1
        node = 5->N
        curr = 4->3->2
        prev = 4->3->2
        curr = 5->N
     
     temp = 1->4->3->2->5->N
     (...)*/
};

int main(){
    
    return 0;
}
