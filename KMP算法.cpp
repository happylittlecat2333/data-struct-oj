#include <iostream>
#include<stdio.h>
#include<string>
#include<string.h>
using namespace std;
char a[ 1000001],b[ 1000001];
int nexting[1000001];
void getNext();
int main()                      //KMP算法
{
    scanf("%s",a);
    scanf("%s",b);
    getNext();
    int i=0,j=0,m=0;
    int alen=strlen(a),blen=strlen(b);
    while(i<alen&&j<blen)
    {
        if(j==-1 || a[i]==b[j])
        {
            i++;
            j++;
            if(j==blen)
            {
                if(m!=0){printf("\n");}
                printf("%d",i-j+1);
                j--;m=1;
            }
        }
        else
        {
            j=nexting[j];
        }
    }

    return 0;

}

void getNext()
{
    int blen=strlen(b);
    nexting[0]=-1;
    int j=0;
    int k=-1;
    while(j<blen-1)
    {
        if(k==-1 || b[j]==b[k])
        {
            nexting[j+1]=nexting[j]+1;
            j++;k++;
        }
        else
        {
            k=nexting[k];
        }

    }


}