#include<iostream>
#include<algorithm>
using namespace std;
#define INF 100000
#define MAX 1000
int d[MAX][MAX];
int main()						//Floyd算法 (用于求得所有顶点之间的最短路径)
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int tmp;cin>>tmp;
			if(i==j) d[i][j]=0;	//自身无权重
			else if(tmp==0) d[i][j]=INF;//没有边，设权重为INF
			else d[i][j]=tmp;
		}
	}

	for(int k=1;k<=n;k++)		//允许中间顶点序号最大为k时的最短路径
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);//中间顶点序号最大为k时的最短路径
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// 	{
	// 		for(int j=1;j<=n;j++)
	// 		{
	// 			cout<<d[i][j]<<' ';
	// 		}
	// 		cout<<endl;
	// 	}
	if(d[1][n]!=INF)cout<<d[1][n];
	else cout<<-1;
	return 0;
}