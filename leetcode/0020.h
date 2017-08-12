#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> ss;
		ss.push('\0');
		int n=s.size();
		for(int i=0;i<n;i++)
		{
			char c=s[i];
			if(c=='('||c=='['||c=='{')
			{
				ss.push(c);
			}
			else
			{
				char c2=ss.top();
				if(c2=='('&&c==')' || c2=='['&&c==']' ||c2=='{'&&c=='}')
				{
					ss.pop();
					continue;
				}
				return false;
			}
		}
		if(ss.top()!=0)
		{
			return false;
		}
		return true;
    }
};