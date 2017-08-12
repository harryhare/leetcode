#include<string>
#include<vector>
using namespace std;
class Solution {



public:
    vector<string> generateParenthesis(int n) {
		vector<string> x;
		if(n==0)
		{
			x.push_back("");
			return x;
		}
		for(int i=n-1;i>=0;i--)
		{
			int j=n-1-i;
			vector<string> s1=generateParenthesis(i);
			vector<string> s2=generateParenthesis(j);
			for(int ij=0;ij<s1.size();ij++)
			{
				for(int ik=0;ik<s2.size();ik++)
				{
					x.push_back('('+s1[ij]+')'+s2[ik]);
				}
			}
		}
		return x;
    }
};