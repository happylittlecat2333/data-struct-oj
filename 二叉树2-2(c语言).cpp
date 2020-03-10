#include<stdio.h>
#include<stdlib.h>
#define Max 300
int pre[Max],in[Max],post[Max],level[Max];
int son[Max][2],root,fa[Max];		//精髓在son,fa(father)
int decode(int b1,int e1,int b2,int e2){
	if(e1<b1) {return -1;}
	int r=pre[b1];
	int p=b2;
	while(in[p]!=r)p++;
	int lson=decode(b1+1,p-b2+b1,b2,p-1);
	// if(lson==-1)printf("%d%d%d%d%d\n",b1,e1,b2,e2,p);
	int rson=decode(p-b2+b1+1,e1,p+1,e2);
	son[r][0]=lson;		//精髓
	son[r][1]=rson;
	// printf("%d %d %d\n",r,lson,rson);
	if(lson!=-1) fa[lson]=r;	//精髓
	if(rson!=-1) fa[rson]=r;
	return r;
}
void postOrder(int root){
	if(son[root][0]!=-1)
		postOrder(son[root][0]);
	if(son[root][1]!=-1)
		postOrder(son[root][1]);
	printf("%d ",root);
}
void levelOrder(int root,int n){
	int len=0;
	level[len++]=root;
	for(int i=0;i<n;i++){	//用for循环，而不是while，每次只输出1个
		int r=level[i];
		printf("%d ",r);
		if(son[r][0]!=-1) level[len++]=son[r][0]; //模拟队列
		if(son[r][1]!=-1) level[len++]=son[r][1];
	}
}
void retrace(int u,int root){
	int l[Max];
	int len=0;int r=u;
	while(r!=root){
		l[len++]=r;
		r=fa[r];
		// printf("%d",r);
	}
	l[len++]=root;
	for(int i=len-1;i>=0;i--)
		printf("%d ",l[i]);
}
int main(){
	int n;int u;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&pre[i]);
	for(int i=0;i<n;i++)
		scanf("%d",&in[i]);
	scanf("%d",&u);
	int root=decode(0,n-1,0,n-1);
	postOrder(root);
	printf("\n");
	levelOrder(root,n);
	printf("\n");
	retrace(u,root);
}

// 7
// 0 1 3 4 2 5 6
// 3 1 4 0 5 2 6


// pre:0 -> 1 -> 3 -> 4 -> 2 -> 5 -> 6
// mid:3 -> 1 -> 4 -> 0 -> 5 -> 2 -> 6
// before:3 -> 4 -> 1 -> 5 -> 6 -> 2 -> 0