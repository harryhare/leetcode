/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<iostream>
using namespace std;

 struct ListNode {
    int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {

public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *temp=head;
		while(n>0)
		{
			temp=temp->next;
			n--;
		}
		ListNode **temp2=&head;
		while(temp)
		{
			temp=temp->next;
			temp2=&((*temp2)->next);
		}
		ListNode* x=*temp2;
		*temp2=(*temp2)->next;
		delete x;
		return head;
    }
};