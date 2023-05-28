#include <string>
#include <algorithm>
using namespace std;
bool cmp(int & x, int &y){
    return x>y;
}
class Solution {
public:
    int minimumKeypresses(string s) {
        int counter[26]={0};
        int l=s.size();
        for(int i=0;i<l;i++){
            counter[s[i]-'a']++;
        }
        sort(counter,counter+26,cmp );
        int result=0;
        int sum[3]={0};
        for(int i=0;i<26;i++){
            sum[i/9]+=counter[i];
        }
        return sum[0]+sum[1]*2+sum[2]*3;
    }
};

int main(){
    Solution s;
    s.minimumKeypresses("abc");
}