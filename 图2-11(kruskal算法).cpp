#include<iostream>
#include<algorithm>
#define MAX 30
#define MAXNUM 10000
using namespace std;

int a[MAX][MAX];
int r[MAXNUM],p[MAXNUM],u[MAXNUM],v[MAXNUM],w[MAXNUM];
int cmp(int i,int j) {return w[i]<w[j];}
int find(int x)					//寻找x的父节点，其实是找到代表这棵树的值
{
	if(p[x]==x) return x;
	else return find(p[x]);	//找父节点	
}
int main()
{
	int n;cin>>n;
	int num=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			int tmp;cin>>tmp;
			if(tmp)
			{
				u[num]=i;v[num]=j;w[num]=tmp;num++;	//如果有边，输入起点，终点，权重
			}
		}
	
	for(int i=0;i<n;i++) p[i]=i;		//表示每个结点都是一棵树
	for(int i=0;i<num;i++) r[i]=i;		//用来标记权重大小顺序
	sort(r,r+num,cmp);					//对权重排序
	int sum=0;
	for(int i=0;i<num;i++)				//从权重最小的开始合并
	{
		int e=r[i];						//权重最小的边
		int x=find(u[e]);				//找到所在的树的根节点(为同一棵树的标记)
		int y=find(v[e]);
		if(x!=y) {p[x]=y;sum+=w[e];}	//如果不在一棵树上，合并，即x的父节点为y
	}
	cout<<sum;
	return 0;
}