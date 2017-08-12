#include<string>
using namespace std;
class StringIterator {
	int left;
	char c; 
	int cur;
	string str;
public:
    StringIterator(string compressedString) {
		str=compressedString;
		cur=0;
		left=0;
    }
    
    char next() {
		if(left>0)
		{
			left--;
			return c;
		}
		if(cur>=str.length())
		{
			return ' ';
		}
		c=str[cur];
		cur++;
		while(str[cur]<='9'&&str[cur]>='0')
		{
			left=left*10+str[cur]-'0';
			cur++;
		}
		left--;
		return c;
    }
    
    bool hasNext() {
		return left||cur<str.length();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */