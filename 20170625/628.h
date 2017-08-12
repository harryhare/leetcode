#include<vector>
#include<queue>
#include<functional>

using namespace std;

struct Three
{
	int a[3];
	int len;
	Three(){len=0;}
	int getmax()
	{
		int i=0;
		if(len>1&&a[i]<a[1])
		{
			i=1;
		}
		if(len>2&&a[i]<a[2])
		{
			i=2;
		}
		return a[i];
	}
	void push(int x)
	{
		if(len<3)
		{
			a[len]=x;
			if(len!=0&&a[len]<a[0])
			{
				swap(a[len],a[0]);
			}
			len++;
		}
		else if(x>a[0])
		{
			a[0]=x;
			if(a[1]<=a[2]&&a[1]<a[0])
			{
				swap(a[1],a[0]);
			}
			if(a[2]<a[1]&&a[2]<a[0])
			{
				swap(a[2],a[0]);
			}
		}
	}
};
struct Two
{
	int a[2];
	int len;
	Two(){len=0;}
	void push(int x)
	{
		if(len<2)
		{
			a[len]=x;
			if(len!=0&&a[len]>a[0])
			{
				swap(a[len],a[0]);
			}
			len++;
		}
		else if(x<a[0])
		{
			a[0]=x;
			if(a[0]<a[1])
			{
				swap(a[1],a[0]);
			}
		}
	}
};
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
		//priority_queue<int> t;
		//priority_queue<int,vector<int>,greater<int>> nt;
		//priority_queue<int> nnt;
		sort(nums.begin(),nums.end());
		Three t;
		Three nnt;
		Two nt;
 		for(int i=0;i<nums.size();i++)
		{
			if(nums[i]<0)
			{
				nt.push(nums[i]);
				nnt.push(nums[i]);
			}
			else
			{
				t.push(nums[i]);
			}
		}
		int an=0;
		if(t.len==3)
		{
			an=max(t.a[0]*t.a[1]*t.a[2],an);
		}
		if(nt.len==2&&t.len>=1)
		{
			an=max(t.getmax()*nt.a[0]*nt.a[1],an);

		}
		if(t.len==0)
		{
			an=nnt.a[0]*nnt.a[1]*nnt.a[2];
		}
		return an;
    }
};