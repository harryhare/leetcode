#include<string>
#include<cassert>
#include<cstring>
using namespace std;

inline void swap(int *&a,int *&b)
{
	int *t=a;
	a=b;
	b=t;
}

class Solution {
public:
    bool isMatch(string s, string p) {
		p=p+'\0';
		int sl=s.length();
		int pl=p.length();
		//if(pl==0)
		//{
		//	return sl==0;
		//}
		//if(pl==1)
		//{
		//	return sl==1&&(p[0]=='.'||p[0]==s[0]);
		//}
		int maxcol=sl+2;
		int *dp1=new int[maxcol];
		int *dp2=new int[maxcol];
		memset(dp1,0,maxcol*sizeof(int));
		memset(dp2,0,maxcol*sizeof(int));
		dp1[0]=1;
		for(int i=1;i<=sl;i++)
		{
			dp1[i]=0;
		}
		int left=pl;
		int i=0;//pattern index
		int j=0;//string index
		while(left>=2)
		{
			if(p[i+1]!='*')
			{
				for(int j=0;j<sl;j++)
				{
					if(dp1[j]==1 && (p[i]=='.'||s[j]==p[i]))
					{
						dp2[j+1]=1;
					}
				}
				i++;
				left--;
			}
			else
			{
				if(p[i]=='.')
				{
					int j=0;
					for(;dp1[j]==0 && j<=sl;j++);
					for(int k=j;k<=sl;k++)
					{
						dp2[k]=1;
					}
				}
				else
				{
					for(int j=0;j<=sl;j++)
					{
						if(dp1[j]==1)
						{
							dp2[j]=1;
							for(int k=j;k<sl;k++)
							{
								if(s[k]==p[i])
								{
									dp2[k+1]=1;
								}
								else
								{
									j=max(j,k);
									break;
								}
							}
						}
					}
				}
				i+=2;
				left-=2;
			}
			swap(dp1,dp2);
			memset(dp2,0,maxcol*sizeof(int));
		}
		bool ismatch=dp1[sl];
		delete []dp1;
		delete []dp2;
		return ismatch;
    }
};