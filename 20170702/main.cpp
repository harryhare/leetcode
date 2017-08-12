#include"635.h"
#include<iostream>
using namespace std;
int main()
{
	 LogSystem obj;
	obj.put(1,"2017:01:01:23:59:59");
	obj.put(2,"2017:01:01:22:59:59");
	obj.put(3,"2016:01:01:00:00:00");
	vector<int> param_2 = obj.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Year");
	vector<int> param_3 = obj.retrieve("2016:01:01:01:01:01","2017:01:01:23:00:00","Hour");
	cout<<param_2.size()<<endl;
	cout<<param_3.size()<<endl;
	system("pause");
	return 0;
}