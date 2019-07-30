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
            int carry = 0;

            ListNode *c1 = l1;
            ListNode *c2 = l2;
            while(c1->next != NULL){
                cur->next = new ListNode(0);
                if(c1->val+c2->val+carry >= 10){
                    cur->val = (c1->val+c2->val+carry) % 10;
                    carry = 1;
                }else{
                    cur->val = (c1->val+c2->val+carry);
                    carry = 0;
                }
                cur = cur->next;
                c1 = c1->next;
                c2 = c2->next;
            }
            
            if(c1->val+c2->val+carry >= 10){
                cur->val = (c1->val+c2->val+carry) % 10;
                cur->next = new ListNode((c1->val+c2->val+carry)/10);
            }else{
                cur->val = (c1->val+c2->val);
            }

            return ret;
        }
};

int main(){
    ListNode *l1 = new ListNode(5);
    l1->next = new ListNode(5);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(5);

    Solution s;
    ListNode *ret = s.addTwoNumbers(l1, l2);
    return 0;
}
