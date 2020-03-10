#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	priority_queue<double,vector<double>,greater<double> > q;
	int n;
	cin>>n;
	double sum=0;
	for(int i=0;i<n;i++)
	{
		double tmp;cin>>tmp;
		q.push(tmp);
	} 
	while(q.size()!=1)
	{
		double tmp1,tmp2;
		tmp1=q.top();q.pop();
		tmp2=q.top();q.pop();
		// cout<<tmp1<<' '<<tmp2<<endl;
		sum+=(tmp1+tmp2);
		q.push(tmp1+tmp2);
	}
	printf("%.2lf",sum);
}