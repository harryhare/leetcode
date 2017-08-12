#include<vector>
#include<queue>
#include<cassert>
//#include<algorithm>
using namespace std;


static bool cmp(const vector<int>& v1,const vector<int>&v2)
{
	return( v1.back()<v2.back());

}
class Solution {
	int *a;
	int alen;
	void push(int x)
	{
		a[alen++]=x;
		shiftup(alen-1);
	}
	void popanspush(int x)
	{
		a[0]=x;
		shiftdown(0);
	}
	void shiftup(int i)
	{
		int j=(i-1)/2;
		while(i!=0&&a[i]>a[j])
		{
			swap(a[i],a[j]);
			i=j;
			j=(i-1)/2;
		}
	}
	void shiftupr(int i)
	{
		if(i==0) return;
		int j=(i-1)/2;
		if(a[i]>a[j])
		{
			swap(a[i],a[j]);
			shiftupr(j);
		}
	}
	void shiftdownr(int i)
	{
		int left=i*2+1;
		int right=i*2+2;
		if(left>=alen)
		{
			return;
		}
		if(right>=alen)
		{
			if(a[left]>a[i])
			{
				swap(a[left],a[i]);
			}
			return;
		}
		if(a[right]>=a[left]&&a[right]>a[i])
		{
			swap(a[right],a[i]);
			shiftdownr(right);
		}
		else if(a[right]<a[left]&&a[left]>a[i])
		{
			swap(a[left],a[i]);
			shiftdownr(left);
		}
	}
	void shiftdown(int i)
	{
		int left=i*2+1;
		int right=i*2+2;
		while(right<alen)
		{
			if(a[right]>=a[left]&&a[right]>a[i])
			{
				swap(a[right],a[i]);
				i=right;
			}
			else if(a[right]<a[left]&&a[left]>a[i])
			{
				swap(a[left],a[i]);
				i=left;
			}
			else
			{
				break;
			}
			left=i*2+1;
			right=i*2+2;
		}
		if(left>=alen)
		{
			return;
		}
		if(right>=alen)
		{
			if(a[left]>a[i])
			{
				swap(a[left],a[i]);
			}
			return;
		}
	}
public:
    int scheduleCourse(vector<vector<int>>& courses) {
		if(courses.size()==0)
		{
			return 0;
		}
		alen=0;
		a=new int[courses.size()];
		sort(courses.begin(),courses.end(),cmp);
		//priority_queue<int> q;
		//q.push(courses[0][0]);
		push(courses[0][0]);
		int sum=courses[0][0];
		//int sum2=sum;
		for(int i=1;i<courses.size();i++)
		{
			//sum2+=courses[i][0];
			//q.push(courses[i][0]);
			//if(sum2>courses[i][1])
			//{
			//	sum2-=q.top();
			//	q.pop();
			//}
			int endtime=sum+courses[i][0];
			if(endtime<=courses[i][1])
			{
				sum=endtime;
				push(courses[i][0]);
			}
			else if(courses[i][0]<a[0])
			{
				sum=endtime-a[0];
				popanspush(courses[i][0]);
			}
		}
		//return q.size();
		return alen;
    }
};