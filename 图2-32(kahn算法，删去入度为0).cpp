#include<iostream>
#include<stack>
using namespace std;
#define MAX 30
int a[MAX][MAX];
int in[MAX]={0},out[MAX]={0};
int main()						//kahn算法(拓扑排序)，不断删去入度为0的点
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int tmp;cin>>tmp;
			a[i][j]=tmp;
			if(tmp)
			{
				out[i]++;in[j]++;
			}
		}
	}
	int sum=0;
	stack<int> s;
	for(int i=1;i<=n;i++)	//找出所有入度为0的点，入栈
	{
		if(in[i]==0) {s.push(i);sum++;}
	}
	while(!s.empty())
	{
		int t=s.top();s.pop();	//取出栈顶t，并删除
		for(int i=1;i<=n;i++)	//删去所有以t为起始点的边
		{						//如果删除的边的另一个顶点入度为0，则入栈
			if(a[t][i])
			{
				in[i]--;
				if(in[i]==0) {s.push(i);sum++;}
			}
		}
	}
	if(sum==n) cout<<"NO";
	else cout<<"YES";
	return 0;
}