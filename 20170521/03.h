/*592*/
#include<string>
#include<cassert>
using namespace std;

class Fraction
{
public:
	int up;
	int down;
	void get(string& input,int &i)
	{
		int sign=1;
		if(input[i]=='-')
		{
			sign=-1;
			i++;
		}
		else if(input[i]=='+')
		{
			i++;
		}
		up=input[i]-'0';
		for(i++;input[i]<='9'&&input[i]>='0';i++)
		{
			up=up*10+input[i]-'0';
		}
		up*=sign;
		assert(input[i]=='/');
		down=0;
		for(i++;input[i]<='9'&&input[i]>='0';i++)
		{
			down=down*10+input[i]-'0';
		}
	}


	void Reduce()
	{
		int t1=abs(up);
		int t2=down;
		while(t1)	
		{
			int t=t2%t1;
			t2=t1;
			t1=t;
		}
		up=up/t2;
		down=down/t2;
	}
	Fraction Add(Fraction & other)
	{
		Fraction x;
		long a=up*other.down;
		long b=down*other.up;
		x.up=a+b;
		x.down=down*other.down;
		x.Reduce();
		return x;
	}
};

class Solution {
public:
    string fractionAddition(string expression) {
		Fraction a;
		Fraction b;
		Fraction c;
		int i=0;
		a.get(expression,i);
		while(i<expression.length())
		{
			b.get(expression,i);
			c=a.Add(b);
			a=c;
		}
		return to_string(a.up)+'/'+to_string(a.down);
    }
};