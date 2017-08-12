#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
		if(matrix.size()==0||matrix[0].size()==0)
		{
			return;
		}
		int n=matrix.size();
		int m=matrix[0].size();

		vector<bool> rowzero(n,false);
		vector<bool> colzero(m,false);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(matrix[i][j]==0)
				{
					rowzero[i]=true;
					colzero[j]=true;
				}
			}
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(rowzero[i]||colzero[j])
				{
					matrix[i][j]=0;
				}
			}
		}
		
    }
};