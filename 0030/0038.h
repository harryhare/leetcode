#include<string>
#include<cassert>
using namespace std;
class Solution {
	string intostring(int n)
	{   
		static int a[32];
		int l=0;
		a[0]=0;
		while(n)
		{
			a[l++]=n%10;
			n=n/10;
		}
		string x;
		for(int i=l-1;i>=0;i--)
		{
			x+=char('0'+a[i]);
		}
		return x;
	}
	string fun(string x)
	{
		assert(x.size()>=1);
		int n=x.size();
		int count=1;
		string y;
		for(int i=1;i<n;i++)
		{
			if(x[i]==x[i-1])
			{
				count++;
			}
			else
			{
				y+=intostring(count);
				y+=x[i-1];
				count=1;
			}
		}
		y+=intostring(count);
		y+=x[n-1];
		return y;
	}
public:
    string countAndSay(int n) {
		string x="1";
		for(int i=1;i<n;i++)
		{
			x=fun(x);
		}
		return x;
    }
};