#include<vector>
#include<string>
#include<map>
using namespace std;
class Solution {
public:
    int countSubstrings(string s) {
		int n=s.size();
		if(n==0)
		{
			return 0;
		}
		//single
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int begin=i,end=i;begin>=0&&end<n;begin--,end++)
			{
				if(s[begin]==s[end])
				{
					ans++;
				}
				else
				{
					break;
				}
			}
		}
		//double
		for(int i=0;i<n;i++)
		{
			for(int begin=i,end=i+1;begin>=0&&end<n;begin--,end++)
			{
				if(s[begin]==s[end])
				{
					ans++;
				}
				else
				{
					break;
				}
			}
		}
		return ans;

    }
};