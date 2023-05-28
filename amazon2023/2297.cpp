#include <vector>
#include <stack>
using namespace std;
const  long long MAX_COST= 100000000001;
class Solution {
public:
    long long minCost(vector<int> &nums, vector<int> &costs) {
        int n = nums.size();
        vector<int> right_less(n, -1);
        vector<int> right_big(n, -1);
        vector<long long> dp(n, MAX_COST);

        stack<int> s;
        s.push(-1);

        for(int i=n-1;i>=0;i--){
            int c=nums[i];
            while(s.top()!=-1 &&nums[s.top()]<c){
                s.pop();
            }
            right_less[i]=s.top();
            s.push(i);
        }

        stack<int> s2;
        s2.push(-1);
        for(int i=n-1;i>=0;i--){
            int c=nums[i];
            while(s2.top()!=-1 &&nums[s2.top()]>=c){
                s2.pop();
            }
            right_big[i]=s2.top();
            s2.push(i);
        }
        dp[0]=0;
        for(int i=0;i<n-1;i++){
            int rl=right_less[i];
            if(rl!=-1){
                dp[rl]=min(dp[rl],dp[i]+costs[rl]);
            }
            int rb=right_big[i];
            if(rb!=-1){
                dp[rb]=min(dp[rb],dp[i]+costs[rb]);
            }
        }
        return dp[n-1];
    }
};