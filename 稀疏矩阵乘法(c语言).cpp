#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 130*130

typedef struct Triple{
	int i,j,e;
} Triple;

Triple a[MAX],b[MAX],c[MAX],c2[MAX];

int comp(const void *a, const void *b){		//升序
	if( (*(Triple*)a).i == (*(Triple*)b).i ). //把void *a强制转化
		return (*(Triple*)a).j - (*(Triple*)b).j; //如果a>b,返回1, a,b互换
	else 
		return (*(Triple*)a).i - (*(Triple*)b).i;
}

int main(){
	int c1,na;
	scanf("%d%d",&c1,&na);
	for(int i=0;i<na;i++)
		scanf("%d%d%d",&a[i].i,&a[i].j,&a[i].e);
	int nb;
	scanf("%d%d",&c1,&nb);
	for(int i=0;i<nb;i++)
		scanf("%d%d%d",&b[i].i,&b[i].j,&b[i].e);
	
	int nc=0;
	for(int i=0;i<na;i++)
		for(int j=0;j<nb;j++){
			if(a[i].j==b[j].i){
				c[nc].i=a[i].i;
				c[nc].j=b[j].j;
				c[nc++].e=a[i].e*b[j].e;
			}
		}

	qsort(c,nc,sizeof(Triple),comp);

	int nc2=0;
	for(int i=0;i<nc;i++){
		if(nc2>0 && c2[nc2-1].i==c[i].i && c2[nc2-1].j==c[i].j){
			c2[nc2-1].e+=c[i].e;
		}
		else
			c2[nc2++]=c[i];
	}
	nc=0;
	for(int i=0;i<nc2;i++){
		if(c2[i].e){
			c[nc++]=c2[i];
		}
	}
	for(int i=0;i<nc;i++){
		printf("%d %d %d",c[i].i,c[i].j,c[i].e);
		if(i!=nc-1)
			printf("\n");
	}

	return 0;
}





