/**
 * Definition for singly linked list.
 * struct ListNode {
 *  int val;
 *  ListNode *next;
 *  ListNode(int x) : val(x), next(NULL){}
 * };
 */

#include<cstddef>
#include<stdio.h>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
            ListNode *cur = new ListNode(0);
            ListNode *ret = cur;
            
            int carry = 0,
                val_to_next = 0,
                tmp_sum = 0;

            ListNode *c1 = l1;
            ListNode *c2 = l2;
            
            while(c1 != NULL || c1 != NULL || carry > 0){
                tmp_sum = 0;
                if(c1 != NULL){
                    tmp_sum += c1->val;
                    c1 = c1->next;
                }
                if(c2 != NULL){
                    tmp_sum += c2->val;
                    c2 = c2->next;
                }
                tmp_sum += carry;
                carry = tmp_sum/10;
                val_to_next = tmp_sum%10;
                cur->val = val_to_next;
                cur->next = new ListNode(0);
                cur = cur->next;
            }
            cur = NULL;
            return ret;
        }
};

void printllist(ListNode* l){
    printf("Linked list: ");
    while(l != NULL){
        printf(" (%d)", l->val);
        l = l->next;
    }
    printf("\n");
}

int main(){
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(1);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(1);
    l2->next = new ListNode(1);
    l2->next->next = new ListNode(5);

    Solution s;
    printllist(l1);
    printllist(l2);
    ListNode *ret = s.addTwoNumbers(l1, l2);
    printllist(ret);
    return 0;
}
