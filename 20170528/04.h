#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	int a[32];
	Solution()
	{
		a[0]=1;//0
		a[1]=2;//0,1
		for(int i=2;i<32;i++)
		{
			a[i]=a[i-1]+a[i-2];
		}
	}
	int fun(int num)
	{
		if(num==0)
		{
			return 1;
		}
		if(num==1)
		{
			return 2;
		}
		if(num==2)
		{
			return 3;
		}
		if(num==3)
		{
			return 3;
		}
		int n=0;
		int t=num;
		while(t)
		{
			t=(t>>1);
			n++;
		}
		int mask=(3<<(n-2));
		if((num&mask)==mask)
		{
			return a[n];
		}
		int ans=a[n-1];
		ans=ans+fun(num&(~mask));
		return ans;
	}

public:
    int findIntegers(int num) {

		return fun(num);
    }
};