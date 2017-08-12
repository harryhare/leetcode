#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstring>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        //int a[100];
		vector<int> a(n,0);
		//memset(a,0,sizeof(a));
		//queue<int> q;
		//queue<int> q1;
		stack<int> run;
		run.push(999);
		int last=0;
		for(string log:logs)
		{
			int i=log.find(':');
			int id=stoi(log.substr(0,i));
			int j=log.find(':',i+1);
			int flag=((j-i)==6);
			int t=stoi(log.substr(j+1,log.size()-j+1));
			t+=(flag==0);
			if(flag)
			{
				if(run.top()!=999)
				{
					a[run.top()]+=t-last;
				}
				//q.push(t);
				run.push(id);
			}
			else
			{
				//q.pop();
				run.pop();
				a[id]+=t-last;
			}
			last=t;
		}
		return a;
    }
};