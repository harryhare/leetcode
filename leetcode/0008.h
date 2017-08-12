#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
		long long x=0;
		int l=str.length();
		int i=0;
		for(;i<l;i++)
		{
			//if(str[i]>='0'&&str[i]<='9' || str[i]=='+' || str[i]=='-')
			if(str[i]!=' '&&str[i]!='\n'&&str[i]!='\t')
			{
				break;
			}
		}
		int sign=1;
		long long upbound=INT_MAX;
		if(str[i]=='-')
		{
			sign=-1;
			i++;
			upbound++;
		}
		else if(str[i]=='+')
		{
			i++;
		}
		for(;str[i]>='0'&&str[i]<='9';i++)
		{
			x=x*10+str[i]-'0';
			if(x>upbound)
			{
				x=upbound;
				break;
			}
		}
		return x*sign;
    }
};