#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> ans;
		if(matrix.size()==0||matrix[0].size()==0)
		{
			return ans;
		}
		int n=matrix.size();
		int m=matrix[0].size();
		int i=0;
		int j=0;
		int loi=0;
		int loj=0;
		int hii=n-1;
		int hij=m-1;
		while(loi<=hii&&loj<=hij)
		{
			while(j<=hij)
			{
				ans.push_back(matrix[i][j]);
				j++;
			}
			loi++;
			j--;
			i++;
			while(i<=hii)
			{
				ans.push_back(matrix[i][j]);
				i++;
			}
			hij--;
			i--;
			j--;
			if(loi>hii||loj>hij)
			{
				break;
			}
			while(j>=loj)
			{
				ans.push_back(matrix[i][j]);
				j--;
			}
			hii--;
			i--;
			j++;
			while(i>=loi)
			{
				ans.push_back(matrix[i][j]);
				i--;
			}
			loj++;
			i++;
			j++;
		}
		return ans;
    }
};