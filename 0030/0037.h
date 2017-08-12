#include<vector>
#include<cassert>
using namespace std;
class Solution {
	int a[3][10][10];
	bool solve(vector<vector<char>>& board,int x=0)
	{
		int i=x/9;
		int j=x%9;
		x=-1;
		for(;i<9 ;i++)
		{
			for(;j<9;j++)
			{
				if(board[i][j]==0)
				{
					x=i*9+j;
					break;
				}
			}
			if(x!=-1)
			{
				break;
			}
			j=0;
		}
		if(x==-1)
		{
			return true;
		}
		for(int k=1;k<=9;k++)
		{
			if(a[0][i][k]==0 && a[1][j][k]==0 && a[2][i/3*3+j/3][k]==0)
			{
				board[i][j]=k;
				a[0][i][k]=1;a[1][j][k]=1;a[2][i/3*3+j/3][k]=1;
				if(solve(board,x+1))
				{
					return true;
				}
				board[i][j]=0;
				a[0][i][k]=0;a[1][j][k]=0;a[2][i/3*3+j/3][k]=0;
			}
		}
		return false;
	}
public:
    void solveSudoku(vector<vector<char>>& board) {
		memset(a,0,sizeof(a));
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				char c=board[i][j];
				if(c=='.')
				{
					c=0;
				}
				else
				{
					c=c-'0';
					a[0][i][c]=1;
					a[1][j][c]=1;
					a[2][i/3*3+j/3][c]=1;
				}
				board[i][j]=c;
			}
		}
		assert(solve(board,0));
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(board[i][j]==0)
				{
					board[i][j]='.';
				}
				else
				{
					board[i][j]+='0';
				}
			}
		}
		return;
    }
};