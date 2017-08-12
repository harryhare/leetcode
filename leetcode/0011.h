#include<vector>
#include<cassert>
using namespace std;

inline int fmin(int x,int y)
{
	if(x<y)
	{
		y=x;
	}
	return y;
}
inline int fmax(int x,int y)
{
	if(x>y)
	{
		y=x;
	}
	return y;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
		if(height.size()<=1)
		{
			return 0;
		}

		vector<int> valid_index1;
		vector<int> valid_index2;
		int n=height.size();
		int max=height[0];
		valid_index1.push_back(0);
		for(int i=1;i<n;i++)
		{
			if(height[i]>max)
			{
				max=height[i];
				valid_index1.push_back(i);
			}
		}
		max=height[n-1];
		valid_index2.push_back(n-1);
		for(int i=n-1;i>=0;i--)
		{
			if(height[i]>max)
			{
				max=height[i];
				valid_index2.push_back(i);
			}
		}
		int n1=valid_index1.size();
		int n2=valid_index2.size();
		int max_area=0;
		assert(height[valid_index1[n1-1]]==height[valid_index2[n2-1]]);
		int ii=0,jj=0;
		while(ii<n1 && jj<n2)
		{
			int i1=valid_index1[ii];
			int i2=valid_index2[jj];
			assert(i1<=i2);
			if(height[i1]<=height[i2])
			{
				int area=height[i1]*(i2-i1);
				max_area=fmax(max_area,area);
				ii++;
			}
			else
			{
				int area=height[i2]*(i2-i1);
				max_area=fmax(max_area,area);
				jj++;
			}
		}
        return max_area;
    }
};