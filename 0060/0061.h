/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<cstdio>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
		if(k==0||head==NULL)
		{
			return head;
		}
		ListNode* t=head;
		int l=0;
		while(t!=NULL)
		{
			t=t->next;
			l++;
		}
		k=k%l;;
        if(k==0)
        {
            return head;
        }
		ListNode**t2=&head;
        for(int i=0;i<k;i++)
		{
			if(*t2==NULL)
			{
				t2=&head;
			}
			t2=&((*t2)->next);
		}

		ListNode**t1=&head;
		while((*t2)!=NULL)
		{
			t2=&((*t2)->next);
			t1=&((*t1)->next);
		}
		ListNode*newhead=*t1;
		*t1=NULL;
		*t2=head;
		return newhead;
    }
};