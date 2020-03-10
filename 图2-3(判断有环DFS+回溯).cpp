#include<iostream>
using namespace std;
#define Max 30
int a[Max][Max];
int s[100000];
int dfs(int i,int n,int *s,int &sum)	//判断是否有环(回溯法+DFS)
{
	int judge=0;
	for(int j=1;j<=n;j++)
	{
		if(a[i][j])
		{
			if(s[0]==j)return 1;
			s[sum]=j;sum++;
			judge=dfs(j,n,s,sum);
			if(judge==1)return 1;
			sum--;
		}
	}
	
	return 0;


}
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	int judge=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		s[sum]=i;sum++;
		judge=dfs(i,n,s,sum);
		if(judge) cout<<"YES";break;
	}
	if(judge==0) cout<<"NO";
	return 0;
}