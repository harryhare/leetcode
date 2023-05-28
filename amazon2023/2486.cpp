#include <string>
using namespace std;
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0;
        int j=0;
        int l1=s.size();
        int l2=t.size();
        while(i<l1 && j<l2){
            if(s[i]==t[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return l2-j;
    }
};