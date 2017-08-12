#include <string>
#include<cassert>
#include<stack>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
		int n=s.size();
		stack<int> ss;
		int count=0;
		int unmatched=0;
		int max=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='(')
			{
				unmatched++;
				ss.push(-1);
			}
			else if(s[i]==')')
			{
				unmatched--;
				if(unmatched>=0)
				{
					int sum=1;
					while(ss.top()!=-1)
					{
						sum+=ss.top();
						ss.pop();
					}
					ss.pop();
					while(ss.size()!=0&&ss.top()!=-1)
					{
						sum+=ss.top();
						ss.pop();
					}
					ss.push(sum);
					if(sum>max)
					{
						max=sum;
					}
				}
				else	
				{
					unmatched=0;
					while(ss.empty()==false)
					{
						ss.pop();
					}
				}
			}
			else
			{
				assert(0);
			}
		}
		return (max<<1);
    }
};