#include<string>
#include<vector>
using namespace std;
class Solution {
	
	vector<string> result;
	void addletter(string t,const char* digits)
	{
		if(digits[0]==0)
		{
			result.push_back(t);
			return ;
		}
		static char *a[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};	
		int  x=digits[0]-'0';
		for(int i=0;a[x][i];i++)
		{
			addletter(t+a[x][i],digits+1);
		}
	}
public:
    vector<string> letterCombinations(string digits) {
		result.clear();
		if(digits.size()==0)
		{
			return result;
		}
		addletter("",digits.c_str());
		return result;
    }
};