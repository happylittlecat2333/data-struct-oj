#include <iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int compare(char c1,char c2);
double operating(char c,double d1,double d2);
int main()
{
    char str[2000];
    double str1[2000];
    char str2[2000];
    scanf("%s",str);
    int sum1=-1;
    int sum2=-1;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            double tmp=0;int j;
            for(j=i;(str[j]>='0'&&str[j]<='9');j++) 	//把字符串中的数字，变为int型
                tmp=tmp*10+str[j]-'0';
            sum1++;
            str1[sum1]=tmp;i=j-1;
        }
        else
        {
            int j=i;
            if(str[j]=='c'||str[j]=='s'){i+=2;}		//对于cos,sin,只存入c,s
            if(sum2==-1)
            {
                sum2++;
                str2[sum2]=str[j];

            }
            else
            {
                int judge=compare(str2[sum2],str[j]);	//判断优先级
                if(judge==1)
                {
                    sum2++;str2[sum2]=str[j];
                }
                if(judge==-1)
                {
                    if(str2[sum2]=='s'||str2[sum2]=='c')
                    {
                        double i1=str1[sum1];
                        if(str2[sum2]=='c') {str1[sum1]=cos(i1);}
                        if(str2[sum2]=='s') {str1[sum1]=sin(i1);}
                        str2[sum2]='\0';sum2--;
                        i--;
                    }

                    else				//如果后来的优先级低，就先算之前的，再把后来读入还回去
                    {
                        double i1 = str1[sum1];
                        sum1--;
                        double i2 = str1[sum1];
                        str1[sum1] = operating(str2[sum2], i2, i1);
                        str2[sum2] = '\0';
                        sum2--;
                        i--;
                    }
                }
                if(judge==0)
                {str2[sum2]='\0';sum2--;}

            }
        }
        if(sum1==0&&sum2==0&&str[i+1]=='\0') {printf("%.3f",str1[sum1]);break;}


    }
    return 0;
}

int compare(char c1,char c2)		//判断优先级
{
    double a1,a2;
    if(c1=='+'||c1=='-') a1=3;
    if(c1=='*'||c1=='/') a1=5;
    if(c1=='^') a1=7;
    if(c1=='c'||c1=='s') a1=1.5;
    if(c1=='(') a1=1;
    if(c1==')') a1=9;
    if(c1=='#') a1=-1;

    if(c2=='+'||c2=='-') a2=2;
    if(c2=='*'||c2=='/') a2=4;
    if(c2=='^') a2=6;
    if(c2=='c'||c2=='s') a2=10;
    if(c2=='(') a2=8;
    if(c2==')') a2=1;
    if(c2=='#') a2=-1;
    if((c1=='c'||c1=='s')&&!(c2=='(')) return -1;
    if(a2>a1) return 1;
    if(a2<a1) return -1;
    if(a1==a2) return 0;
    return 0;

}
double operating(char c,double d1,double d2)
{
    switch (c)
    {
        case '+':
            return d1 + d2;
        case '-':
            return d1 - d2;
        case '*' :
            return d1 * d2;
        case '/':
            return d1 / d2;
        case '^':
            return pow(d1, d2);
    }
    return 0;
}