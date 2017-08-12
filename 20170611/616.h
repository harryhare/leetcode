#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string addBoldTag(string s, vector<string>& dict) {
        string b=s;
		int cur=0;
		for(string word : dict)
		{
			cur=0;
			cur=s.find(word,cur);
			while(cur!=string::npos)
			{
				for(int i=0;i<word.length();i++)
				{
					b[cur+i]=-1;
				}
				cur++;
				cur=s.find(word,cur);
			}
		}
		string ans;
		bool inbold=false;
		for(int i=0;i<s.length();i++)
		{
			if((b[i])==(char)-1 && inbold==false)
			{
				ans.append("<b>");
				inbold=true;
			}
			if(b[i]!=-1 && inbold==true)
			{
				ans.append("</b>");
				inbold=false;
			}
			ans+=s[i];
			
		}
		if(inbold)
		{
			ans.append("</b>");
		}
		return ans;
    }
};