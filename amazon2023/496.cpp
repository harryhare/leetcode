#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// 单调栈的技巧在于，除了第一个元素以为，栈不会是空的，栈顶肯定是上一个元素！！！
class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n = nums2.size();
        stack<int> s;
        s.push(-1);
        s.push(n - 1);
        vector<int> next_big(n, -1);
        for (int i = n - 2; i >= 0; i--) {
            int c = nums2[i];
//            if (c < nums2[i + 1]) {
//                next_big[i] = nums2[i + 1];
//                s.push(i);
//                continue;
//            }
            while (s.top() != -1 && c >= nums2[s.top()]) {
                s.pop();
            }
            if(s.top()!=-1){
                next_big[i] = nums2[s.top()];
            }
            s.push(i);
        }
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums2[i]] = i;
        }

        int n1 = nums1.size();
        vector<int> res(n1);
        for (int i = 0; i < n1; i++) {
            int c = nums1[i];
            int j=m[c];
            res[i]=next_big[j];
        }
        return res;
    }
};

int main(){
    vector<int> num1={4,1,2};
    vector<int> num2={1,3,4,2};
    Solution s;
    s.nextGreaterElement(num1,num2);
}