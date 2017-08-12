#include<string>
#include<cassert>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        int i=0;
		int j=0;
		int n=haystack.size();
		for(int i=0;i<=n;i++)
		{
			int t=i;
			while(needle[j]!=0 &&haystack[t]!=0 && haystack[t]==needle[j])
			{
				t++;
				j++;
			}
			if(needle[j]==0)
			{
				return i;
			}
			if(haystack[t]==0)
			{
				return -1;
			}
			j=0;
		}
		assert(0);
		return -1;
    }
};