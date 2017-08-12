#include<vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
		bool addonedig=true;
		for(int i=0;i<digits.size();i++)
		{
			if(digits[i]!=9)
			{
				addonedig=false;
				break;
			}
		}

		if(addonedig)
		{
			vector<int> ans(digits.size()+1,0);
			digits[0]=1;
			return ans;
		}
		vector<int> ans(digits);
		int c=1;
		for(int i=ans.size()-1;i>=0&&c;i--)
		{
			ans[i]+=c;
			c=(ans[i])/10;
			ans[i]%=10;
		}
		return ans;
    }
};