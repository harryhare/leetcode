#include<string>
#include<vector>
using namespace std;
class Solution {
	static int commonlength(const string &s1,const string &s2)
	{
		int i;
		for(i=0;s1[i]==s2[i] && s1[i];i++);
		return i;
	}
public:
    string longestCommonPrefix(vector<string>& strs) {
		if(strs.size()==0)
		{
			return "";
		}
		int n=strs.size();
		int min=strs[0].length();
		string minstr=strs[0];
		for(int i=1;i<n;i++)
		{
			int t=commonlength(minstr,strs[i]);
			if(t==0)
			{
				min=0;
				minstr="";
				break;
			}
			if(t<min)
			{
				min=t;
				minstr=minstr.substr(0,min);
			}
		}
		return minstr;
    }
};