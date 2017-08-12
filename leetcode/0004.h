#include<vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int l1=nums1.size();
		int l2=nums2.size();
		int l3=(l1+l2)/2;
		int i1=0;
		int i2=0;
		int i3=0;
		int last=0;
		int cur=0;
		for(i3=0;i3<=l3;i3++)
		{
			int x=INT_MAX;
			int y=INT_MAX;
			if(i1<l1)
			{
				x=nums1[i1];
			}
			if(i2<l2)
			{
				y=nums2[i2];
			}
			if(x<y)
			{
				i1++;
				last=cur;
				cur=x;
			}
			else
			{
				i2++;
				last=cur;
				cur=y;
			}
		}
		if((l1+l2)%2)
		{
			return cur;
		}
		else
		{
			return (cur+last)/2.;
		}
    }
};