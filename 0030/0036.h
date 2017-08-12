#include<vector>
#include<cassert>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		assert(board.size()==9);
		assert(board[0].size()==9);
		static int count[10];
		//check h
		for(int i=0;i<9;i++)
		{
			memset(count,0,sizeof(count));
			for(int j=0;j<9;j++)
			{
				char c=board[i][j];
				if(c!='.')
				{
					c -= '0';
					if(count[c]>0)
					{
						return false;
					}
					count[c]++;
				}
			}
		}

		//check v
		for(int i=0;i<9;i++)
		{
			memset(count,0,sizeof(count));
			for(int j=0;j<9;j++)
			{
				char c=board[j][i];
				if(c!='.')
				{
					c -= '0';
					if(count[c]>0)
					{
						return false;
					}
					count[c]++;
				}
			}
		}
		//check cell
		for(int k=0;k<9;k++)
		{
			memset(count,0,sizeof(count));
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					char c=board[i+k/3*3][j+k%3*3];
					if(c!='.')
					{
						c -= '0';
						if(count[c]>0)
						{
							return false;
						}
						count[c]++;
					}
				}
			}
		}
		return true;

    }
};