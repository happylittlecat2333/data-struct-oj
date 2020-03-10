#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
// 根据前序和中序构造二叉树，输出后序二叉树，按层次遍历，根结点到结点的路径
int a[1000],b[1000];
struct Tree{
	int node;
	int lchild;
	int rchild;
	int parent;
	int layer;
}tree[1000];
int findHead(int ahead,int bhead,int btail)
{
	for(int i=bhead;i<=btail;i++) 
	if(b[i]==a[ahead]) return i;
	
}

void createTree(int ahead,int atail,int bhead,int btail)
{

	int curhead=findHead(ahead,bhead,btail);
	int l1=curhead-bhead,l2=btail-curhead;
	if(l1!=0) tree[a[ahead+1]].parent=a[ahead];
	if(l2!=0) tree[a[ahead+1+l1]].parent=a[ahead];
	if(l1!=0) tree[a[ahead]].lchild=a[ahead+1];else tree[a[ahead]].lchild=-1;
	if(l2!=0) tree[a[ahead]].rchild=a[ahead+1+l1];else tree[a[ahead]].rchild=-1;
	if(l1!=0) createTree(ahead+1,ahead+l1,bhead,curhead-1);
	if(l2!=0) createTree(ahead+1+l1,atail,curhead+1,btail);

}

void postOrder(int head)
{
	if(tree[head].lchild!=-1) postOrder(tree[head].lchild);
	// else cout<<tree[head].node<<' ';
	if(tree[head].rchild!=-1) postOrder(tree[head].rchild);
	cout<<tree[head].node<<' ';
}

void levelOrder(int head,int n)
{
	queue<int> order;
	order.push(tree[head].node);
	while(order.size()!=0)
	{
		int tmp=order.front();
		cout<<tmp<<' ';
		order.pop();
		if(tree[tmp].lchild!=-1) order.push(tree[tmp].lchild);
		if(tree[tmp].rchild!=-1) order.push(tree[tmp].rchild);


	}
	// int temp[1000],start=1,tail=1;
	// temp[1]=tree[head].node;
	// while(start<=n)
	// {
	// 	int end=tail;
	// 	for(int i=start;i<=tail;i++) cout<<temp[i]<<' ';
	// 	for(int i=start;i<=tail;i++)
	// 	{
	// 		if(tree[i].lchild!=-1) {end++;temp[end]=tree[i].lchild;}
	// 		if(tree[i].rchild!=-1) {end++;temp[end]=tree[i].rchild;}
	// 	}
	// 	start=tail+1;
	// 	tail=end;
	// }

}

void path(int head,int q)
{
	int temp[1000],i=1;
	while(tree[q].parent!=0)
	{
		temp[i]=q;
		q=tree[q].parent;
		i++;
	}
	temp[i]=q;
	for(int j=i;j>=1;j--) {cout<<temp[j];if(j!=1)cout<<' ';}
}
int h=0;

int main()
{
	int n;cin>>n;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	int q;cin>>q;
	for(int i=1;i<=n;i++) tree[i].node=i;
	createTree(1,n,1,n);
	for(int i=1;i<=n;i++)
	// cout<<tree[i].node<<' '<<tree[i].lchild<<' '<<tree[i].rchild<<' '<<tree[i].parent<<endl;
	

	for(int i=1;i<=n;i++)
	{
		if(tree[i].parent==0) {h=i;break;}
	}
	// cout<<endl<<h;
	postOrder(h);
	cout<<endl;
	levelOrder(h,n);
	cout<<endl;
	path(h,q);
	return 0;
	

}