/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<vector>
#include<queue>
#include<functional>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode**temp=&head;
		while(*temp)
		{
			ListNode*start=*temp;//include
			ListNode*end=start;//exclude
			bool longenough=true;
			for(int i=0;i<k;i++)
			{
				if(end==NULL)
				{
					longenough=false;
					break;
				}
				end=end->next;
			}
			if(longenough==false)
			{
				break;
			}
			ListNode *t=start->next;
			ListNode *pre=start;
			while(t!=end)
			{
				ListNode *nt=t->next;
				t->next=pre;
				pre=t;
				t=nt;
			}
			*temp=pre;
			start->next=end;
			temp=&(start->next);
		}
		return head;
    }
};