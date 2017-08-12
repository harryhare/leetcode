#include<string>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) 
	{
		int l=s.length();
		int maxlen=0;
		int maxhead;
		int maxtail;
		for(int i=0;i<l;i++)
		{
			int head = i-1;//include
			int tail = i+1;//include
			int curlen=1;
			while(head>=0 && tail<l && s[head]==s[tail])
			{
				curlen+=2;
				head--;
				tail++;
			}
			if(curlen>maxlen)
			{
				maxlen=curlen;
				maxhead=head+1;
				maxtail=tail-1;
			}
		}
		for(int i=0;i<l;i++)
		{
			int head=i;
			int tail=i+1;
			int curlen=0;
			while(head>=0 && tail<l && s[head]==s[tail])
			{
				curlen+=2;
				head--;
				tail++;
			}
			if(curlen>maxlen)
			{
				maxlen=curlen;
				maxhead=head+1;
				maxtail=tail-1;
			}
		}
		return s.substr(maxhead,maxlen);
    }
};