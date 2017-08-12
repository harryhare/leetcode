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


 struct Node
 {
	 int index;
	 ListNode*node;
	 Node(int i,ListNode*n):index(i),node(n){}
	 Node(){}
	 bool operator<(const Node& n)const
	 {
		 if(n.node==NULL)
		 {
			 return true;
		 }
		 return node->val<n.node->val;
	 }
	 bool operator>(const Node& n)const
	 {
		 if(node==NULL)
		 {
			 return true;
		 }
		 return node->val>n.node->val;
	 }
 };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<Node,vector<Node>,greater<Node> > q;
		int n=lists.size();
		for(int i=0;i<n;i++)
		{
			if(lists[i]!=NULL)
			{
				q.push(Node(i,lists[i]));
				lists[i]=lists[i]->next;
			}
		}
		ListNode* head=NULL;
		ListNode** temp=&head;
		while(q.empty()==false)
		{
			Node n=q.top();
			q.pop();
			(*temp)=n.node;
			temp=&((*temp)->next);
			if(lists[n.index]!=NULL)
			{
				q.push(Node(n.index,lists[n.index]));
				lists[n.index]=lists[n.index]->next;
			}
		}
		*temp=NULL;
		return head;
    }
};