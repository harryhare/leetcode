#include<string>
using namespace std;
class Solution {
public:
    bool isNumber(string s) {
		int i=0;
		while(s[i]==' '||s[i]=='\t'||s[i]=='\n')
		{
			i++;
		}
		if(s[i]=='-'||s[i]=='+')
		{
			i++;
		}
		bool predot=false;
		if(isdigit(s[i])==false&&s[i]!='.')
		{
			return false;
		}
		while(isdigit(s[i]))
		{
			predot=true;
			i++;
			if(i==s.size())
			{
				return true;
			}
		}
		bool postdot=false;
		if(s[i]=='.')
		{
			i++;
			if(i==s.size())
			{
				return predot;
			}
			while(isdigit(s[i]))
			{
				postdot=true;
				i++;
				if(i==s.size())
				{
					return true;
				}
			}
			if(predot==false&&postdot==false)
			{
				return false;
			}
		}
		if(s[i]=='e')
		{
			i++;
			
			if(s[i]=='-'||s[i]=='+')
			{
				i++;
			}
			if(isdigit(s[i])==false)
			{
				return false;
			}
			while(isdigit(s[i]))
			{
				i++;
				if(i==s.size())
				{
					return true;
				}
			}
		}


		if(isspace(s[i]))
		{
			while(isspace(s[i]))
			{
				i++;
				if(i==s.size())
				{
					return true;
				}
			}
			return false;
		}

		return false;

    }
};