#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTime(vector<int>& jobs, vector<int>& workers) {
        sort(jobs.begin(),jobs.end());
        sort(workers.begin(),workers.end());
        int n=jobs.size();
        int max_day=0;
        for(int i=0;i<n;i++){
            int day=(jobs[i]+workers[i]-1)/workers[i];
            if(day>max_day){
                max_day=day;
            }
        }
        return max_day;
    }
};