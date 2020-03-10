#include<iostream>
using namespace std;
int a[30][30]={0};
int visited[30]={0};
void DFS(int v,int n)			//visit顶点v
{
	visited[v]=1;
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0&&a[v][i]==1) DFS(i,n);
	}
}
int main()				//输出连通图个数
{
	int n;cin>>n;int sum=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	for(int i=1;i<=n;i++)	
	{
		if(visited[i]==0)		//如果DFS遍历后，还有没有visit，个数加1
		{
			sum++;
			DFS(i,n);
		}
	}
	cout<<sum;
	return 0;
}