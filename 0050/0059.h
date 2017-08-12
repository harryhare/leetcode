#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
		vector<vector<int> > ans(n,vector<int>(n,0));
		if(n==0)
		{
			return ans;
		}
		int m=n;
		int i=0;
		int j=0;
		int loi=0;
		int loj=0;
		int hii=n-1;
		int hij=m-1;
		int x=1;
		while(loi<=hii&&loj<=hij)
		{
			while(j<=hij)
			{
				(ans[i][j])=x++;
				j++;
			}
			loi++;
			j--;
			i++;
			while(i<=hii)
			{
				ans[i][j]=x++;
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
				ans[i][j]=x++;
				j--;
			}
			hii--;
			i--;
			j++;
			while(i>=loi)
			{
				ans[i][j]=x++;
				i--;
			}
			loj++;
			i++;
			j++;
		}
		return ans;
    }
};