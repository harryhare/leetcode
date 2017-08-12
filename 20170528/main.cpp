#include<iostream>
#include"04.h"
using namespace std;
int main()
{
	Solution s;
	cout<<s.findIntegers(6)<<endl;;
	for(int i=0;i<8;i++)
	{
		cout<<s.findIntegers(i)<<endl;;
	}
	system("pause");
	return 0;
}