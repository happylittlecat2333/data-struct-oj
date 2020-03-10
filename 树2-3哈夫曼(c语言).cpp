#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

double a[MAX][MAX];

int comp(const void *a,const void *b){
	return	*(double*)b - *(double*)a;
}

int main(){
	int n;double sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lf",&a[n][i]);
	for(int i=n;i!=1;i--){
		qsort(a[i],i,sizeof(double),comp);
		a[i][i-2]+=a[i][i-1];		//a[i]表示合并后剩下i个元素的排列
		sum+=a[i][i-2];
		for(int j=0;j<i-1;j++)
			a[i-1][j]=a[i][j];
		// for(int j=0;j<i-1;j++)
		// 	printf("%lf ",a[i-1][j]);
		// printf("%lf\n",sum);

	}
	printf("%lf",sum);
}