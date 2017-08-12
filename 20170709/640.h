#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
    string solveEquation(string equation) {
		int a0=0;
		int a1=0;
		int i=0;
		while(i<equation.size())
		{
			if(equation[i]=='=')
			{
				i++;
				break;
			}
			int sign=1;
			if(equation[i]=='+'||equation[i]=='-')
			{
				sign=(equation[i]=='+'?1:-1);
				i++;
			}
			int factor=0;
			if(isdigit(equation[i])==false)
			{
				factor=1;
			}
			while(isdigit(equation[i]))
			{
				factor=factor*10+(equation[i]-'0');
				i++;
			}
			if(i<equation.size()&&equation[i]=='x')
			{
				a1+=sign*factor;
				i++;
			}
			else
			{
				a0+=sign*factor;
			}
		}

		while(i<equation.size())
		{
			if(equation[i]=='=')
			{
				break;
			}
			int sign=1;
			if(equation[i]=='+'||equation[i]=='-')
			{
				sign=(equation[i]=='+'?1:-1);
				i++;
			}
			int factor=0;
			if(isdigit(equation[i])==false)
			{
				factor=1;
			}
			while(isdigit(equation[i]))
			{
				factor=factor*10+(equation[i]-'0');
				i++;
			}
			if(i<equation.size()&&equation[i]=='x')
			{
				a1-=sign*factor;
				i++;
			}
			else
			{
				a0-=sign*factor;
			}
		}
		if(a1==0)
		{
			if(a0!=0)
			{
				return "No solution";
			}
			else
			{
				return "Infinite solutions";
			}
		}
		ostringstream ans;
		ans<<"x="<<(-a0/a1);
		return ans.str();
    }
};