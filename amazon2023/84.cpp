//
// Created by mayue on 2023/5/27.
//
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
/* 答案的常数时间优化还是算了吧*/
class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> right(n, n);
        vector<int> left(n, -1);
        s.push(n);
        for (int i = n - 1; i >= 0; i--) {
            int c = heights[i];
            while (s.top() != n && heights[s.top()] >= c) {
                s.pop();
            }
            right[i] = s.top();
            s.push(i);
        }

        stack<int> s2;
        s2.push(-1);
        for(int i=0;i<n;i++){
            int c = heights[i];
            while (s2.top() != -1 && heights[s2.top()] >= c) {
                s2.pop();
            }
            left[i] = s2.top();
            s2.push(i);
        }

        long long res = 0;
        for (int i = 0; i < n; i++) {
            long long  area = (long long )heights[i] * (right[i] - left[i]-1);
            if (area > res) {
                res = area;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> a={2,1,5,6,2,3};
    cout<<s.largestRectangleArea(a)<<endl;
    return 0;
}