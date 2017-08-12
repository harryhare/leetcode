#include <cassert>
#include <string>
#include <stack>
using namespace std;

bool check1(string &code){
	if(code.length()<7){
		return false;
	}
	if(code[0]!='<')
	{
		return false;
	}
	int i=1;
	for(i=1;i<code.length();i++)
	{
		if(code[i]=='>')
			break;
		if(i>9)
		{
			return false;
		}
		if(code[i]<'A'||code[i]>'Z')
			return false;
	}
	string tagname=code.substr(1,i-1);
	if(code.at(code.length()-1)!='>')
	{
		return false;
	}
	int j=code.length()-2;
	for(;j>i;j--)
	{
		if(code[j]=='/'&&code[j-1]=='<')
		{
			break;
		}
		if(code.length()-1-j>9)
		{
			return false;
		}
		if(code[j]<'A'||code[j]>'Z')
		{
			return false;
		}
	}
	if(j==i)
	{
		return false;
	}
	string tagname2=code.substr(j+1,code.length()-1-(j+1));
	assert(code[i]=='>');
	assert(code[j-1]=='<');
	code=code.substr(i+1,j-1-i-1);
	return tagname==tagname2;
}

int gettag(string code,int &begin,string&label,bool &beginorend){
	int i=begin;
	for(;i<code.size();i++)
	{
		if(code[i]=='<')
		{
			break;
		}
	}
	
	if(i+11<code.size()&&code.substr(i,9)=="<![CDATA[")
	{
		i++;
		while(i+2<code.size())
		{
			if(code[i]!=']')
			{
				i++;
			}
			else
			{
				if(code[i+1]!=']')
				{
					i+=2;
				}
				else
				{
					if(code[i+2]!='>')
						i+=2;
					else
						break;
				}
			}
		}
		if(i+2<code.size()&&code.substr(i,3)=="]]>")
		{
			begin=i+3;
			return gettag(code,begin,label,beginorend);
		}
		else
		{
			begin=i+3;
			return -1;
		}
	}
	if(i+6<code.size()&&code[i]=='<'&&code[i+1]!='/')
	{
		int begin1=i+1;
		int end1=-1;
		for(int j=i+1;j<code.length();j++)
		{
			if(code[j]=='>')
			{
				end1=j;
				label=code.substr(begin1,end1-begin1);
				begin=end1+1;
				beginorend=0;
				return true;
			}
			if(j-i>9)
			{
				return -1;
			}
			if(code[j]<'A'||code[j]>'Z')
				return -1;
		}
		return false;
	}
	if(i+3<code.size()&&code[i]=='<'&&code[i+1]=='/')
	{
		int begin1=i+2;
		int end1=-1;
		for(int j=i+2;j<code.length();j++)
		{
			if(code[j]=='>')
			{
				end1=j;
				label=code.substr(begin1,end1-begin1);
				begin=end1+1;
				beginorend=1;
				return true;
			}
			if(j-i>10)
			{
				return -1;
			}
			if(code[j]<'A'||code[j]>'Z')
				return -1;
		}

	}
	begin=i;
	return 0;
}


class Solution {
public:
    bool isValid(string code) {
        if(check1(code)==false)
		{
			return false;
		}
		stack<string> labels;
		int i=0;
		bool beginorend;
		string label;
		int x=gettag(code,i,label,beginorend);
		while(x>0)
		{
			if(beginorend==0)//begin
			{
				labels.push(label);
			}
			else
			{
				if(labels.size()==0||labels.top()!=label)
				{
					return false;
				}
				labels.pop();
			}
			x=gettag(code,i,label,beginorend);
		}
		if(x==-1)
		{
			return false;
		}
		return i==code.size()&&labels.size()==0;
    }
};