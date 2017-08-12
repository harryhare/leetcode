/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


#include<vector>
#include<algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
bool cmp(Interval&i1,Interval &i2)
{
	return(i1.start<i2.start);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
		sort(intervals.begin(),intervals.end(),cmp);
		vector<Interval> ans;
		if(intervals.size()==0)
		{
			return ans;
		}
		ans.push_back(intervals[0]);
		for(int i=1;i<intervals.size();i++)
		{
			if(intervals[i].start<=ans.back().end)
			{
				ans.back().end=max(ans.back().end,intervals[i].end);
			}
			else
			{
				ans.push_back(intervals[i]);
			}
		}
		return ans;
    }
};