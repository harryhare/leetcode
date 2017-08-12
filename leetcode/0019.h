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
	int target;
	void fun(ListNode*&head,int&n)
	{
		if(head->next==NULL)
		{
			n=0;
		}
		else
		{
			fun(head->next,n);
		}
		n++;
		if(n==target)
		{
			ListNode*temp=head;
			head=head->next;
			delete temp;
		}
		return;
	}
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		int t=0;
		target=n;
		fun(head,t);
		return head;
    }
};