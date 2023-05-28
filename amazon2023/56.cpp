//
// Created by mayue on 2023/5/24.
//

#include <algorithm>
#include <vector>

using namespace std;

bool cmp(vector<int> &i1, vector<int> &i2) {
    if (i1[0] == i2[0]) {
        return i1[1] < i2[1];
    }
    return (i1[0] < i2[0]);
}


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        if (intervals.size() == 0) {
            return result;
        }
        int last_end = -1;//result index
        int j = 0;//source index
        for (j = 0; j < intervals.size(); j++) {
            if (intervals[j][0] > last_end) {
                result.push_back(intervals[j]);
                last_end = intervals[j][1];
                continue;
            }
            if (intervals[j][1] > last_end) {
                last_end = intervals[j][1];
                result.back()[1] = last_end;
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> a = {{74, 78}};
    Solution s;
    s.merge(a);

}
