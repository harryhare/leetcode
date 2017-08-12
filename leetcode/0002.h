#include<iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3=NULL;
        int c=0;
		ListNode** pre = &l3;
        while(l1!=NULL&&l2!=NULL)
        {
            c = c + l1->val + l2->val;
            *pre = new ListNode(c%10);
			c = c/10;
			pre=&((*pre)->next);
			l1 = l1->next;
			l2 = l2->next;
        }
		if(l1==NULL)
		{
			l1=l2;
		}
		while(l1)
		{
			c = c+ l1->val;
			*pre=new ListNode(c%10);
			c = c/10;
			pre=&((*pre)->next);
			l1=l1->next;
		}
		while(c!=0)
		{
			*pre=new ListNode(c%10);
			c=c/10;
			pre=&((*pre)->next);
		}
		return l3;
    }
};