#include<vector>
using namespace std;
#include<vector>
using namespace std;
class Solution {
	inline void swap(int&a,int&b)
	{
		int t=a;
		a=b;
		b=t;
	}
public:
    int removeElement(vector<int>& nums, int val) {
		int n=nums.size();
		int i=0;
		int j=n-1;
		while(i<=j)
		{
			for(;nums[i]!=val && i<=j;i++);
			for(;nums[j]==val && i<=j;j--);
			if(i<j)
			{
				swap(nums[i],nums[j]);
				i++;
				j--;
			}
		}
		return i;
    }
};