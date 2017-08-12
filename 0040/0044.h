#include<string>
#include<algorithm>
using namespace std;
class Solution {
	void fun1(int *dp1,int*dp2,int n)
	{		
		for(int j=0;j<=n;j++)
		{
			if(dp1[j]==1)
			{
				while(j<=n)
				{
					dp2[j++]=1;
				}
				break;
			}
			else
			{
				dp2[j]=0;
			}
		}
	}
	void fun2(int *dp1,int*dp2,int n)
	{	
		dp2[0]=0;
		for(int j=0;j<n;j++)
		{
			dp2[j+1]=dp1[j];

		}
	}
	void fun3(int *dp1,int*dp2,int n,string s,char c)
	{	
		dp2[0]=0;
		for(int j=0;j<n;j++)
		{
			if(dp1[j]==1 && s[j]==c )
			{
				dp2[j+1]=1;
			}
			else
			{
				dp2[j+1]=0;
			}
		}
	}
public:
    bool isMatch(string s, string p) {
		int *dp1=new int[s.size()+1];
		int *dp2=new int[s.size()+1];
		int n=p.size();
		memset(dp1,0,(s.size()+1)*sizeof(int));
		dp1[0]=1;
		for(int i=0;i<n;i++)
		{
			switch (p[i])
			{
			case '?':
				fun2(dp1,dp2,s.size());
				break;
			case '*':
				fun1(dp1,dp2,s.size());
				break;
			default:
				fun3(dp1,dp2,s.size(),s,p[i]);
				break;
			}
			swap(dp1,dp2);
		}
		bool ans=dp1[s.size()];
		delete[] dp1;
		delete[] dp2;
		return ans;
    }
};