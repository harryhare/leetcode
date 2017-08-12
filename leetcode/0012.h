#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
		static char* romans[4][10]={"","I","II","III","IV","V","VI","VII","VIII","IX"
							  ,"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"
							  ,"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"
							  ,"","M","MM","MMM",};
		string x;
		x+=romans[3][num/1000];
		x+=romans[2][num/100%10];
		x+=romans[1][num/10%10];
		x+=romans[0][num%10];
		return x;
    }
};