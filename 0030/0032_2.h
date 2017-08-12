#include <string>
#include<cassert>
#include<stack>
#include<functional>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
		stack<int> ss;
		ss.push(-1);
		int n=s.size();
		int m=0;
		for(int i=0;i<n;i++)
		{
			int t=ss.top();
			if(s[i]==')' &&t!=-1 && s[t]=='(')
			{
				ss.pop();
				m=max(m,i-ss.top());
			}
			else
			{
				ss.push(i);
			}
		}
		return m;
    }
};