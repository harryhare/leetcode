#include"03.h"
#include"04.h"
#include<iostream>
using namespace std;
int main()
{
	Solution s;
	string str="abcd";
	cout<<str.substr(2)<<endl;

	FileSystem obj = FileSystem();
	obj.mkdir("/a/b/c");
	obj.mkdir("/a/c");
	obj.mkdir("/a/b/a");
	obj.mkdir("/a/c/a");
	obj.mkdir("/a/c/c");
	obj.mkdir("/a/c/aa");
	auto param_1 = obj.ls("/a/c");
	auto param_2 = obj.ls("/a/b");
	auto param_3 = obj.ls("/a");
	auto param_4 = obj.ls("/");
	//string param_6 = obj.readContentFromFile("/a/b/c");
	//cout<<param_6<<endl;
	system("pause");
	return 0;
}