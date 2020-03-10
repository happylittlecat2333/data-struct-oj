#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s="avefsdwefwef"; 
	s.erase(s.begin()); //vefsdwefwef 删除开头s[0]
	cout<<s<<endl;
	s.erase(s.end()); //vefsdwefwef s.end()指向s最后一个的下一个
	cout<<s<<endl;
	s.erase(s.begin()+1,s.end()-1); //vf 删除[s.begin()+1,s.end()-1)

	s="avefsdwefwef";
	s.erase(s.begin()+2,s.end()); //av 删除[s.begin()+1,s.end() )
	cout<<s<<endl;
	s.append("x");
	cout<<s<<endl; 	//avx

	return 0;
}

//s.insert(pos,str)//在s的pos位置插入str