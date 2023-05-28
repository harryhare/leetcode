#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int kBigIndices(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> left_flag(n, 0);
        vector<int> right_flag(n, 0);

        std::priority_queue<int, vector<int>, less<int>> q;
        for (int i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for (int i = k; i < n - k; i++) {
            int c = nums[i];
            if (c > q.top()) {
                left_flag[i] = 1;
            } else {
                q.pop();
                q.push(c);
            }
        }



        std::priority_queue<int, vector<int>, less<int>> q1;

        for (int i = n-1; i >=n-k; i--) {
            q1.push(nums[i]);
        }
        for (int i = n-k-1; i >=k; i--) {
            int c = nums[i];
            if (c > q1.top()) {
                right_flag[i] = 1;
            } else {
                q1.pop();
                q1.push(c);
            }
        }

        int kbig = 0;
        for (int i = k; i < n - k; i++) {
            kbig += left_flag[i] && right_flag[i];
        }
        return kbig;
    }
};

int main() {
//    std::priority_queue<int, vector<int>, less<int>> q;
//    q.push(1);
//    q.push(2);
//    q.push(3);
//    q.emplace(4);
//    cout << q.top() << endl;
//    q.pop();
//    cout << q.top() << endl;
//    q.pop();
//    cout << q.top() << endl;
//    q.pop();
//    cout << q.top() << endl;
    vector<int> in={
            3,8,4,2,5,3,8,6};
    Solution s;
    s.kBigIndices(in,1);
    return 0;
}