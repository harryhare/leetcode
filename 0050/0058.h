#include<string>
#include<cstdio>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int last=0;
		int curlen=0;
		for(int i=0;i<s.size();i++)
		{
			if(isalpha(s[i]))
			{
				curlen++;
			}
			else
			{
				if(curlen>0)
				{
					last=curlen;
				}
				curlen=0;
			}
		}
		if(curlen>0)
		{
			last=curlen;
		}
		return last;
    }
};