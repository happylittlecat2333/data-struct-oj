#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()			
{
	stack<char> p;		//括号匹配{}()[]
	
	int sum=0;
	char c=getchar();
	while(c!='\n')		//在输入数据时就开始判断
	{
		if(p.empty()) p.push(c);
		else
		{
			char tmp=p.top();
			if((tmp=='('&&c==')')||(tmp=='['&&c==']')||(tmp=='{'||c=='}') )
			{
				p.pop();
			}
			else p.push(c);
		}
		c=getchar();
	}
	if(!p.empty()) cout<<"False";
	else cout<<"True";
	return 0;
}