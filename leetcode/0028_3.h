#include<string>
#include<cassert>
#include<vector>
using namespace std;
class Solution {
	vector<int> next;
	void initnext(string needle)
	{
		int n=needle.size();
		int j=0;
		next.clear();
		next.push_back(-1);
		for(int i=1;i<n;i++,j++)
		{
			if(needle[i]!=needle[j])
			{
				next.push_back(j);
				while(j!=-1 && needle[i]!=needle[j])
				{
					j=next[j];
				}
				//if(j==-1)
				//{
				//	j=0;
				//}
				//else 
				//{
				//	assert(needle[i]==needle[j]);
				//	j++;
				//}
			}
			else if(j==0)
			{
				next.push_back(-1);
				//j++;
			}
			else
			{
				next.push_back(0);
				//j++;
			}

		}
	}

public:
    int strStr(string haystack, string needle) {
        int i=0;
		int j=0;
		int n=haystack.size();
		initnext(needle);
		for(int i=0;i<=n;i++)
		{
			if(needle[j]==0)
			{
				return i-needle.size();
			}
			if(haystack[i]==0)
			{
				return -1;
			}
			while(j!=-1 && haystack[i]!=needle[j])
			{
				j=next[j];
			}
			//if(j==-1)
			//{
			//	j=0;
			//}
			//else 
			{
				//assert(haystack[i]==needle[j]);
				j++;
			}
		}
		assert(0);
		return -1;
    }
};