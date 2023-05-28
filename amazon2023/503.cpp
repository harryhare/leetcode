#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp(2 * n,-1);
        stack<int> s;
        s.push(-1);
        s.push(n-1);
        for (int i = 2 * n - 2; i >= 0; i--) {
            int c=nums[i%n];
            while(s.top()!=-1 && nums[s.top()]<=c){
                s.pop();
            }
            if(s.top()!=-1) {
                dp[i] = nums[s.top()];
            }
            s.push(i%n);
        }

        dp.resize(n);
        return dp;
    }
};

int main() {
    vector<int> a = {1, 2, 1};
    a.resize(2);
    cout << a.size() << endl;
    cout << a[0] << endl;
    cout << a[1] << endl;
    Solution s;
    s.nextGreaterElements(a);
    return 0;
}