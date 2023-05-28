#include <string>
#include <cstring>

using namespace std;

/* 答案是用位运算，但是感觉没啥必要
 * */
class Solution {
public:
    int partitionString(string s) {
        int counter[26]={0};
        int res=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            int c=s[i]-'a';
            if(counter[c]>0){
                res++;
                memset(counter,0,sizeof(counter));
            }
            counter[c]=1;
        }
        return res+1;
    }
};