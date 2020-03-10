#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 100
#define INF 100000
int d[MAX];		//d[i]表示从源顶点到i顶点的最短路径
int v[MAX]={0};
int a[MAX][MAX];
int main()					//Dijkstra算法(求最短路径)
{
	int n;cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)cin>>a[i][j];
	for(int i=1;i<=n;i++)d[i]=INF; 	//初始化

	d[1]=0;		//顶点1为源顶点(出发)，源点为0
	for(int i=1;i<=n;i++)
	{
		int k,w=INF;
		for(int j=1;j<=n;j++)	//找到从k点出发的最小路径
		{
			if(v[j]==0&&d[i]<w) {k=j;w=d[i];}	//第一次先访问1顶点	
		}							//在所有未标记节点中，选出d值最小的
		sum+=w;				
		v[k]=1;			//标记节点k
		// cout<<k<<endl;
		for(int j=1;j<=n;j++) //对于从k出发的所有边，更新d[j]
		{
			if(a[k][j])
			d[j]=min(d[j],d[k]+a[k][j]);
		}
	}
	if(d[n]!=INF)cout<<d[n];
	else cout<<-1;
	return 0;
}