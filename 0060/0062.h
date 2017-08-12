#include<algorithm>
using namespace std;
class Solution {
	int a[201][201];
public:
    int uniquePaths(int m, int n) {
        a[0][0]=1;
		int x=m+n-2;
		int y=min(m-1,n-1);
		for(int i=1;i<=x;i++)
		{
			a[i][0]=1;
			for(int j=1;j<i;j++)
			{
				a[i][j]=a[i-1][j-1]+a[i-1][j];
			}
			a[i][i]=1;
		}
		return a[x][y];
    }
};