#include<iostream>
#include"0030.h"
using namespace std;
class Base
{

	virtual void fun()
	{
		cout<<"Base::fun()"<<endl;
	}
	virtual void fun1()
	{
		cout<<"Base::fun1()"<<endl;
	}
};
class Base2
{
	virtual void fun2()
	{
		cout<<"Base2::fun2()"<<endl;
	}
};
class Derived:public Base
{
	virtual void fun1()
	{
		cout<<"Derived"<<endl;
	}
	virtual void fun()
	{
		cout<<"Derived::fun()"<<endl;
	}
	char c;
	//short b;
	//int a;
};
int main()
{
	//cout<<sizeof(Base)<<endl;
	//cout<<sizeof(Derived)<<endl;
	//strcpy(NULL,"a");
	Solution s;
	//ListNode* p1=new ListNode(0);
	//p1->next=new ListNode(2);
	//p1->next->next=new ListNode(4);
	//p1->next->next->next=NULL;
	//ListNode* p2=new ListNode(1);
	//p2->next=new ListNode(3);
	//p2->next->next=new ListNode(5);
	//p2->next->next->next=p1;
	//vector<ListNode*> a;
	//a.push_back(p1);
	//a.push_back(p2);
	//ListNode *p3=s.reverseKGroup(p2,3);
	//while(p3)
	//{
	//	cout<<p3->val<<endl;
	//	p3=p3->next;
	//}
	
	//vector<int> b;
	//s.removeElement(b,3);
	//vector<int> a;
	//a.push_back(3);
	//a.push_back(2);
	//a.push_back(2);
	//a.push_back(3);
	//cout<<s.removeElement(a,3)<<endl;
	//int n=a.size();
	//for(int i=0;i<n;i++)
	//{
	//	cout<<a[i]<<endl;
	//}
	//vector<string> p;
	//p.push_back("word");
	//p.push_back("good");
	//p.push_back("best");
	//p.push_back("good");

	//vector<int> a=s.findSubstring("wordgoodgoodgoodbestword",p);
	//for(int i=0;i<a.size();i++)
	//{
	//	cout<<a[i]<<endl;
	//}
	vector<int> nums;
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	Solution s;
	s.findSubstrin
	return 0;
}