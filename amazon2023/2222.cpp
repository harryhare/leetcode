#include <string>
using namespace std;

class Solution {
public:
    long long numberOfWays(string s) {
        long long a[2][3]={0};
        long long sum=0;
        a[0][0]=1;
        a[1][0]=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            int c =s[i]-'0';
            sum=sum+a[!c][2];
            a[c][2]+=a[!c][1];
            a[c][1]+=a[!c][0];
        }
        return sum;
    }
};