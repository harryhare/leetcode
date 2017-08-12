/*593*/
#include<vector>
using namespace std;

class Solution {
	bool check(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4)
	{
		//check center
		int cx1=p1[0]+p2[0];
		int cy1=p1[1]+p2[1];
		int cx2=p3[0]+p4[0];
		int cy2=p3[1]+p4[1];
		if(cx1!=cx2 || cy1 !=cy2)
		{
			return false;
		}
		//check length
		int dx1=p1[0]-p2[0];
		int dy1=p1[1]-p2[1];
		int dx2=p3[0]-p4[0];
		int dy2=p3[1]-p4[1];
		if(dx1*dx1+dy1*dy1==0)
		{
			return false;
		}
		if(dx1*dx1+dy1*dy1 != dx2*dx2+dy2*dy2)
		{
			return false;
		}
		
		//check right angle
		if(dx1*dx2+dy1*dy2!=0)
		{
			return false;
		}
		return true;
	}

public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		int b=check(p1,p2,p3,p4);
		if(b)
		{
			return true;
		}
		b=check(p1,p3,p2,p4);
		if(b)
		{
			return true;
		}
		b=check(p1,p4,p2,p3);
		if(b)
		{
			return true;
		}
		return false;
    }
};