#include<vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
		int n=matrix.size();
		int upbound=(n+1)/2;//5:0,1,2;6:0,1,2
		int upbound2=n-upbound;//5:0,1;6:0,1,2
		for(int i=0;i<upbound;i++)
		{
			for(int j=0;j<upbound2;j++)
			{
				int &t1=matrix[i][j];
				int &t2=matrix[j][n-1-i];
				int &t3=matrix[n-1-i][n-1-j];
				int &t4=matrix[n-1-j][i];
				int t=t4;
				t4=t3;
				t3=t2;
				t2=t1;
				t1=t;
			}
		}
    }
};