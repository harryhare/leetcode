#include<string>
#include<cstdio>
using namespace std;
class Solution {
public:
	Solution()
	{
		init();
	}
	int f[10];
	void init()
	{
		f[0]=1;
		for(int i=1;i<10;i++)
		{
			f[i]=f[i-1]*i;
		}
	}
public:
    string getPermutation(int n, int k) {
		if(n==1)
		{
			return "1";
		}
		k--;
		  int x=k/f[n-1];
		  string ans=getPermutation(n-1,k%f[n-1]+1);
		  for(int i=0;i<ans.size();i++)
		  {
			  if(ans[i]>=x+'1')
			  {
				  ans[i]++;
			  }
		  }
		  return string("")+(char)(x+'1')+ans;
    }
};