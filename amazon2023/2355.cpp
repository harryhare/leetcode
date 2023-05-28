#include <vector>
#include <iostream>

using namespace std;

long long triangle(long long n) {
    return n * (n + 1) / 2;
}

long long trapezoid(long long a, long long h) {//a + a-1 +...+ a-h+1
    return a * h - h * (h - 1) / 2;
}

class Solution {
public:
    long long maximumBooks(vector<int> &books) {
        long long n = books.size();
        vector<long long> dp(n, 0);
        vector<long long> s;
        dp[0] = books[0];
        s.push_back(-1);// sentinel
        s.push_back(0);
        for (int i = 1; i < n; i++) {
            int c = books[i];
            if (c > books[s.back()]) {
                s.push_back(i);
                dp[i] = dp[i - 1] + c;
                continue;
            }
            while (true) {
                int j = s.back();
                if (j == -1) {
                    if (c - i - 1 >= 0) {
                        dp[i] = trapezoid(c, i + 1);//(c-i)+...+(c-1)+c
                    } else {
                        dp[i] = triangle(c);
                    }
                    s.push_back(i);
                    break;
                }
                if (c - books[j] >= i - j) {
                    dp[i] = trapezoid(c, i - j) + dp[j];
                    s.push_back(i);
                    break;
                }
                s.pop_back();
            }

        }
        long long max_book = 0;
        for (int i = 0; i < n; i++) {
            max_book = max(max_book, dp[i]);
        }
        return max_book;
    }
};

int main() {
    vector<int> books = {0, 5, 5, 5};
    Solution s;
    cout << s.maximumBooks(books) << endl;
}