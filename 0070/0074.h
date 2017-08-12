#include<string>
#include<vector>

using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.size()==0||matrix[0].size()==0)
		{
			return false;
		}
		int n=matrix.size();
		int m=matrix[0].size();
		int begin=0;
		int end=n-1;
		if(target<matrix[0][0] ||target>matrix[n-1][m-1])
		{
			return false;
		}
		while(begin<end)
		{
			int mid=end-(end-begin)/2;
			if(target>=matrix[mid][0])
			{
				begin=mid;
			}
			else
			{
				end=mid-1;
			}
		}
		if(target>matrix[begin][m-1])
		{
			return false;
		}
		int lo=0;
		int hi=m-1;
		while(lo<=hi)
		{
			int mid=(lo+hi)/2;
			if(matrix[begin][mid]==target)
			{
				return true;
			}
			if(matrix[begin][mid]<target)
			{
				lo=mid+1;
			}
			else
			{
				hi=mid-1;
			}
		}
		return false;
    }
};