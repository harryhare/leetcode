#include<vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        		if(grid.size()==0||grid[0].size()==0)
		{
			return 0;
		}
		int n=grid.size()+1;
		int m=grid[0].size()+1;
		unsigned *a=new unsigned[n*m];
		memset(a,-1,n*m*sizeof(int));
		a[m+1]=grid[0][0];
		for(int d=3;d<=n+m-2;d++)
		{
			for(int i=max(1,d-m+1),j=d-i;j>0&&i<n;j--,i++)
			{
				a[(i)*m+j]=min(a[(i-1)*m+j],a[(i)*m+j-1])+grid[i-1][j-1];
			}
		}
		return a[n*m-1];
    }
};