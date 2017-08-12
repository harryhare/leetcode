#include<iostream>
#include<sstream>
#include"604.h"
#include"616.h"
using namespace std;
int main()
{
	//string s="1x2c";
	////ostream o=iostream(s);
	// StringIterator obj = StringIterator(s);
	//for(int i=0;i<4;i++)
	//{
	//	cout<< obj.next()<<endl;;
	//	cout<< obj.hasNext()<<endl;
	//}
	Solution s;
	vector<string> p;
	p.push_back("a");
	p.push_back("b");
	p.push_back("c");
	cout<<s.addBoldTag("aaabbcc",p)<<endl;
	system("pause");
	return 0;
}