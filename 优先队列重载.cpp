#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
struct Tree{
	double x;
	bool operator < (const Tree & a) const{
		return y<a.y;
	}
	int y;
}tmp;
typedef struct Tree tree;

int main()
{
	priority_queue<Tree> q;
	int n;
	cin>>n;
	double sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>tmp.x>>tmp.y;
		q.push(tmp);
	} 
	while(!q.empty())
	{
		cout<<q.top().x<<' ';
		q.pop();
	}
}