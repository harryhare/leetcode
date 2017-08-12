#include"0061.h"
#include<iostream>
using namespace std;
int main1()
{
	ListNode* head=new ListNode(1);
	head->next=new ListNode(2);
	head->next->next=new ListNode(3);
	Solution s;
	ListNode*ans=s.rotateRight(head,1);
	system("pause");
	return 0;
}