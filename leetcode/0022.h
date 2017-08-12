#include<string>
#include<vector>
using namespace std;
class Solution {

	
public:
    vector<string> generateParenthesis(int n) {
		vector<vector<string> > strs;
		vector<string> temp;
		temp.push_back("");
		strs.push_back(temp);
		for(int i=1;i<=n;i++)
		{
			vector<string> t;
			for(int j=i-1;j>=0;j--)
			{
				int k=i-1-j;
				for(int ij=0;ij<strs[j].size();ij++)
				{
					for(int ik=0;ik<strs[k].size();ik++)
					{
						t.push_back('('+strs[j][ij]+')'+strs[k][ik]);
					}
				}
			}
			strs.push_back(t);
		}
		return strs[n];
    }
};