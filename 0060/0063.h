#include<vector>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if(obstacleGrid.size()==0||obstacleGrid[0].size()==0||obstacleGrid[0][0]==1)
		{
			return 0;
		}
		int n=obstacleGrid.size()+1;
		int m=obstacleGrid[0].size()+1;
        int *a=new int[n*m];
		memset(a,0,n*m*sizeof(int));
		a[m+1]=1;
		for(int d=3;d<=n+m-2;d++)
		{
			for(int i=max(1,d-m+1),j=d-i;j>0&&i<n;j--,i++)
			{
				if(obstacleGrid[i-1][j-1]==0)
				{
					a[(i)*m+j]=a[(i-1)*m+j]+a[(i)*m+j-1];
				}
			}
		}
		return a[n*m-1];
    }
};