#include<iostream>
#define MAX 30
#define MAXNUM 10000
using namespace std;
int a[MAX][MAX];
int visited[MAX]={0};
int main()						//prim算法(求最小生成树)
{
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) cin>>a[i][j];
	visited[1]=1;
	for(int p=1;p<n;p++)
	{
		int v1,v2,w=MAXNUM;
		for(int i=1;i<=n;i++)
		{
			if(visited[i]==1)		//从已经生成的树中选取
			{
				for(int j=1;j<=n;j++)
				{
					if(visited[j]==0&&a[i][j]!=0&&a[i][j]<w) //找到和已经生成的树中最短的边
					{										//再把和边相连的顶点并入生成树中
						v1=i;v2=j;w=a[i][j];
					}
				}
			}
		}
		sum+=w;
		visited[v2]=1;
	}
	cout<<sum;



}