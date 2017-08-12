#include<string>
#include<cassert>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
		if(numRows==1)
		{
			return s;
		}
		int l=s.length();
		int maxcol = l/(numRows-1)+1;
		char *a=new char[numRows*maxcol];
		memset(a,0,numRows*maxcol);
		int action=0;
		int i=0;
		int col=0;
		int row=0;
		while(i<l)
		{
			assert(row==0);
			for(;row<numRows-1 && i<l;row++)
			{
				a[maxcol*row+col]=s[i];
				i++;
			}
			col++;
			for(;row>=1 && i<l;row--)
			{
				a[maxcol*row+col]=s[i];
				i++;
			}
			col++;
		}
		string s2;
		for(int i=0;i<numRows*maxcol;i++)
		{
			if(a[i])
			{
				s2+=a[i];
			}
		}
		delete[]a;
		return s2;
    }
};