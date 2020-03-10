#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;
int main()
{
    int a[1000];           //输入不定长的数组
    int i=0;
    while(cin>>a[i])        //cin如果输入失败，返回0
    {
        i++;
        if(getchar()=='\n') break; //数据用空格隔开 如：1 2 3 4 5 6 7
    }
    cout<<a[0]<<a[1];

    cout<<endl;

    char b[100];           //输入不定长的字符串
    int i=0;
    char c=getchar();       //循环的启动
    while(c!='\n')          //每次先接受到c,如果c是'\n',就推出 abcdefefeesx
    {
        b[i]=c;
        i++;
        c=getchar();
    }
    cout<<b[0]<<b[1];

    int c;
    while(scanf("%d",&c)!=EOF)  //遇到oj中最后无'\n',用EOF
    {
        a[i]=c;
        i++;
    }
}
   


