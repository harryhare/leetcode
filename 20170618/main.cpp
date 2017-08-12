#include<iostream>
#include<cassert>
#include<list>
#include"631.h"
using namespace std;

/*
 0 1
*/
void test1()
{
	//	["Excel","sum","set","get"]
	//	[[3,"C"],[1,"A",["A2"]],[2,"A",1],[1,"A"]]
	Excel s(3,'C');
	vector<string> v;
	v.push_back("A2");
	cout<<s.sum(1,'A',v)<<endl;
	s.set(2,'A',1);
	cout<<s.get(1,'A')<<endl;
}
/*
1 0 0
*/
void test2()
{
//	["Excel","set","sum","set","get","set","get"]
//	[[5,"E"],[1,"A",1],[2,"B",["A1"]],[2,"B",0],[2,"B"],[1,"A",5],[2,"B"]]
	Excel s(5,'E');
	s.set(1,'A',1);
	vector<string> v;
	v.push_back("A1");
	cout<<s.sum(2,'B',v)<<endl;
	s.set(2,'B',0);
	cout<<s.get(2,'B')<<endl;
	s.set(1,'A',5);
	cout<<s.get(2,'B')<<endl;
}

void test3()
{
	/*
	["Excel","set","set","set","sum","get","set","get","sum","set","get","get","sum","set","get","get","get","get"]
[[5,"E"],[1,"A",5],[1,"B",3],[1,"C",2],[1,"C",["A1","A1:B1"]],[1,"C"],[1,"B",5],[1,"C"],[1,"B",["A1:A5"]],[5,"A",10],[1,"B"],[1,"C"],[3,"C",["A1:C1","A1:A5"]],[3,"A",3],[1,"B"],[1,"C"],[3,"C"],[5,"A"]]
	*/
	Excel s(5,'E');
	s.set(1,'A',5);
	s.set(1,'B',3);
	s.set(1,'C',2);
	vector<string> v;
	v.push_back("A1");
	v.push_back("A1:B1");
	cout<<s.sum(1,'C',v)<<endl;
	cout<<s.get(1,'C')<<endl;
	s.set(1,'B',5);
	cout<<s.get(1,'C')<<endl;
	v.clear();
	v.push_back("A1:A5");
	cout<<s.sum(1,'B',v)<<endl;
	s.set(5,'A',10);
	cout<<s.get(1,'B')<<endl;
	cout<<s.get(1,'C')<<endl;
	v.clear();
	v.push_back("A1:C1");
	v.push_back("A1:A5");
	cout<<s.sum(3,'C',v)<<endl;
	s.set(3,'A',3);
	cout<<s.get(1,'B')<<endl;
	cout<<s.get(1,'C')<<endl;
	cout<<s.get(3,'C')<<endl;
	cout<<s.get(5,'A')<<endl;
}
int main()
{
	test1();
	test2();
	test3();
	system("pause");
	return 0;
}