#include"591.h"
#include<iostream>
using namespace std;
int main()
{

	Solution s;
	cout<<s.isValid("<A></A>")<<endl;
	cout<<s.isValid("<a></a>")<<endl;
	cout<<s.isValid("<A><A>")<<endl;
	cout<<s.isValid("<A><B></B></A>")<<endl;
	cout<<s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>")<<endl;
	cout<<s.isValid("<DIV>>>  ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>")<<endl;
	cout<<s.isValid("<<A>  <B> </A>   </B>")<<endl;
	cout<<s.isValid("<DIV>  div tag is not closed  <DIV>")<<endl;
	cout<<s.isValid("<DIV>  unmatched <  </DIV>")<<endl;
	cout<<s.isValid("<DIV> closed tags with invalid tag name  <b>123</b> </DIV>")<<endl;
	cout<<s.isValid("<DIV> unmatched tags with invalid tag name  </1234567890> and <CDATA[[]]>  </DIV>")<<endl;
	cout<<s.isValid("<DIV>  unmatched start tag <B>  and unmatched end tag </C>  </DIV>")<<endl;
	cout<<s.isValid("<AAAAAAAAAA></AAAAAAAAAA>")<<endl;
	cout<<s.isValid("<AAAAAAAAA></AAAAAAAAA>")<<endl;
	
	system("pause");
	return 0;
}