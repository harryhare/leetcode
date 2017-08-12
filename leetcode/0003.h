#ifndef H_3
#define H_3

#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

//struct S
//{
//	int l;
//	int i;
//};
//bool cmp1(const S&s1,const S&s2)
//{
//	return s1.l>s2.l;
//}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		static int last_index[256];
		int l=s.length();
		int *pre=new int[l];
		memset(last_index,-1,sizeof(last_index));
		for(int i=0;i<l;i++)
		{
			pre[i]=last_index[s[i]];
			last_index[s[i]]=i;
		}
		int start=-1;
		int max=0;
		int cur_len=0;
		for(int i=0;i<l;i++)
		{
			if(pre[i]<=start)
			{
				cur_len++;
				continue;
			}
			if(cur_len>max)
			{
				max=cur_len;
			}
			start=pre[i];
			cur_len=i-pre[i];
		}
		if(cur_len>max)
		{
			max=cur_len;
		}

		delete[] pre;
		return max;
    }
};
#endif