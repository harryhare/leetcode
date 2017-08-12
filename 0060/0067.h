#include<string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
       string ans="";
	   int i=a.size()-1;
	   int j=b.size()-1;
	   int c=0;
	   for(;i>=0&&j>=0;i--,j--)
	   {
		   int x=(a[i]-'0'+b[j]-'0'+c);
		   ans=string("")+char(x%2+'0')+ans;
		   c=x/2;
	   }
	   for(;j>=0;j--)
	   {
		   int x=(b[j]-'0'+c);
		   ans=string("")+char(x%2+'0')+ans;
		   c=x/2;
	   }
	   
	   for(;i>=0;i--)
	   {
		   int x=(a[i]-'0'+c);
		   ans=string("")+char(x%2+'0')+ans;
		   c=x/2;
	   }
	   if(c!=0)
	   {
		   ans=string("1")+ans;
	   }
	   return ans;
    }
};