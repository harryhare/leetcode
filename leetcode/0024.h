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
    ListNode* swapPairs(ListNode* head) {
		ListNode**temp=&head;
		while((*temp)&&(*temp)->next)
		{
			ListNode*n1=*temp;
			ListNode*n2=n1->next;
			ListNode*n3=n2->next;
			*temp=n2;
			n2->next=n1;
			n1->next=n3;
			temp=&(n1->next);
		}
		return head;
    }
};