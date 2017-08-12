#include<string>
#include<vector>
using namespace std;
class Solution {
	vector<string> strs;
	void fun(string pre,int leftremain,int rightremain)
	{
		if(leftremain>0)
		{
			fun(pre+'(',leftremain-1,rightremain+1);
		}
		if(rightremain>0)
		{
			fun(pre+')',leftremain,rightremain-1);
		}
		if(leftremain==0 && rightremain==0)
		{
			strs.push_back(pre);
		}
	}


public:
    vector<string> generateParenthesis(int n) {
		strs.clear();
		fun("",n,0);
		return strs;
    }
};