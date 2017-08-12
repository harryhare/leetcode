#include<string>
#include<cassert>
#include<vector>
using namespace std;
class Solution {
	vector<int> next;
	void initnext(string needle)
	{
		int n=needle.size();
		int i=1;
		int j=0;
		next.clear();
		next.push_back(-1);
		while(i<n)
		{
			if(needle[i]==0)
			{
				break;
			}
			if(needle[i]==needle[j])
			{
				if(j==0)
				{
					next.push_back(-1);
				}
				else
				{
					next.push_back(0);
				}
				i++;
				j++;
			}
			else
			{
				if(next[j]!=-1)
				{
					next.push_back(j);
					while(j!=-1&&needle[j]!=needle[i])
					{
						j=next[j];
					}
					if(j==-1)
					{
						i++;
						j=0;
					}
					else
					{
						i++;
						j++;
					}
				}
				else
				{
					next.push_back(j);
					i++;
					j=0;
				}
			}
		}
	}

public:
    int strStr(string haystack, string needle) {
        int i=0;
		int j=0;
		int n=haystack.size();
		initnext(needle);
		while(i<=n)
		{
			if(needle[j]==0)
			{
				return i-needle.size();
			}
			if(haystack[i]==0)
			{
				return -1;
			}
			if(haystack[i]==needle[j])
			{
				i++;
				j++;
			}
			else if(next[j]!=-1)
			{
				j=next[j];
			}
			else
			{
				i++;
				j=0;
			}
		}
		assert(0);
		return -1;
    }
};