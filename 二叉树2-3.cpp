#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
// 哈夫曼树，构造最小路径长度
struct Tree{
	int num;
	int lchild;
	int rchild;
	double val;
	int parent;
	int layer;
}tree[1000];
struct Inputing{
	int num;
	double val;
}a[1000];


bool compare(struct Inputing a,struct Inputing b)
{
	return a.val>b.val;
}

void pathAll(int num,int layer)
{
	if(tree[num].lchild!=-1) pathAll(tree[num].lchild,layer+1);
	else tree[num].layer=layer;
	if(tree[num].rchild!=-1) pathAll(tree[num].rchild,layer+1);
	else tree[num].layer=layer;
	
}

double pathAll(int num.int layer)
{
	int tmp;
	if(tree[num].lchild!=-1) tmp=pathAll(tree[num].lchild,layer+1);
	else tmp=tree[num].layer=layer;
	if(tree[num].rchild!=-1) tmp+=pathAll(tree[num].rchild,layer+1);
	else tmp+=tree[num].layer=layer;
	return tmp;
}

int main()
{
	int n;cin>>n;int sum=n;
	for(int i=0;i<n;i++) 
	{
		tree[i].num=i;a[i].num=i;
		double temp;cin>>temp;tree[i].val=temp;a[i].val=temp;tree[i].lchild=-1;tree[i].rchild=-1;
	}
	// sort(a,a+n,compare);
	// for(int i=0;i<n;i++)
	// {
	// 	cout<<a[i].num<<' '<<a[i].val<<endl;
	// }
	for(int i=n;i>=2;i--)
	{
		sort(a,a+i,compare);
		tree[sum].num=sum;
		tree[sum].val=a[i-1].val+a[i-2].val;
		tree[sum].lchild=a[i-1].num;
		tree[sum].rchild=a[i-2].num;
		tree[a[i-1].num].parent=sum;
		tree[a[i-2].num].parent=sum;
		a[i-2].num=sum;
		a[i-2].val=a[i-1].val+a[i-2].val;
		sum++;
	}
	// for(int i=0;i<(2*n-1);i++)
	// {
	// 	cout<<tree[i].num<<' '<<tree[i].val<<' '<<tree[i].lchild<<' '<<tree[i].rchild<<' '<<endl;

	// }
	// cout<<tree[2*n-2].val;
	pathAll(2*n-2,0);
	// cout<<tmp;
	// for(int i=0;i<(2*n-1);i++)
	// {
	// 	cout<<tree[i].num<<' '<<tree[i].val<<' '<<tree[i].lchild<<' '<<tree[i].rchild<<' '<<tree[i].layer<<endl;

	// }
	double tmp=0;
	for(int i=0;i<n;i++)
	{
		tmp+=tree[i].layer*tree[i].val;
	}
	printf("%.2lf",tmp);
	return 0;
}