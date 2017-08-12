#include<vector>
#include<string>
#include<map>
using namespace std;
struct Node
{
	int a[26];
};
class Solution {
	Node nodes[5000];
	int len;
	bool mark[5000];


public:
	Solution()
	{
		memset(mark,0,sizeof(mark));
		memset(nodes,0,sizeof(nodes));
		len=1;
	}
	void insert(string &str)
	{
		int n=str.size();
		int head=0;
		for(int i=0;i<n;i++)
		{
			int x=str[i]-'a';
			if(nodes[head].a[x]==0)
			{
				nodes[head].a[x]=len;
				len++;
			}
			else if(mark[head]==1)
			{
				return;
			}
			head=nodes[head].a[x];
		}
		mark[head]=1;
	}
    string replaceWords(vector<string>& dict, string sentence) {
		int n=dict.size();
		for(int i=0;i<n;i++)
		{
			insert(dict[i]);
		}
		int begin=0;
		int end=0;
		n=sentence.length();
		
		string ans="";
		bool first=true;
		while(begin<n)
		{
			while(sentence[begin]==' ')
			{
				begin++;
			}
			end=begin;
			while(isalpha( sentence[end]))end++;
			int head=0;	
			if(!first)
			{
				ans+=' ';
			}
			first=false;
			for(int i=begin;i<end;i++)
			{
				

				int x=sentence[i]-'a';
				
				if(nodes[head].a[x]==0)
				{
					ans+=sentence.substr(begin,end-begin);
					break;
				}
				head=nodes[head].a[x];
				
				if(mark[head]==1)
				{
					ans+=sentence.substr(begin,i+1-begin);
					break;
				}
			}
			begin=end;
		}
		return ans;
    }
};