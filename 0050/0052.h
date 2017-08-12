#include<vector>
#include<string>
using namespace std;
class Solution {
	int ans;
	void fun(vector<int> & pre,int n)
	{
		int curline=pre.size();
		if(curline==n)
		{
			ans++;
			return;
		}
		vector<bool> valid(n,true);
		for(int i=0;i<curline;i++)
		{
			valid[pre[i]]=false;
			int j=i+pre[i]-curline;
			if(j>=0 && j<n)
			{
				valid[j]=false;
			}
			j=pre[i]-i+curline;
			if(j>=0 && j<n)
			{
				valid[j]=false;
			}
		}
		pre.push_back(0);
		for(int i=0;i<n;i++)
		{
			if(valid[i])
			{
				pre[curline]=i;
				fun(pre,n);
			}
		}
		pre.pop_back();
	}

public:
    int totalNQueens(int n) {
		vector<int> pre;
		ans=0;
		fun(pre,n);
		return ans;
    }
};