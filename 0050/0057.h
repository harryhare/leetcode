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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		vector<Interval> ans;
		int i=0;
		while(i<intervals.size()&&intervals[i].start<newInterval.start)
		{
			ans.push_back(intervals[i]);
			i++;
		}
		if(ans.size()==0||ans.back().end<newInterval.start)
		{
			ans.push_back(newInterval);
		}
		else
		{
			ans.back().end=max(ans.back().end,newInterval.end);
		}
		while(i<intervals.size()&&intervals[i].start<=ans.back().end)
		{
			ans.back().end=max(ans.back().end,intervals[i].end);
			i++;
		}
		while(i<intervals.size())
		{
			ans.push_back(intervals[i]);
			i++;
		}
		return ans;
    }
};