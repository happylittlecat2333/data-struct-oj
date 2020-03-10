#include<iostream>
#include<queue>
#include<stack>
#include<deque>
#include<vector>
#include<list>
using namespace std;
int t[10000];
int a[100],b[100];
typedef struct Tree{
	int val;
	struct Tree* l;
	struct Tree* r;
}Tree, *treenode;
// typedef struct Tree Tree;
void createTree(Tree* &pn,int i,int j,int len)//使用&pn,引用，表示：pn->l和调用后的pn都是一个东西
{											  //所以改变pn可以改变上一个pn->l
	if(len<=0) return;
	pn=new Tree;
	// pn=(Tree*)malloc(sizeof(Tree));
	pn->val=a[i];
	pn->l=NULL;		//NULL为0x0
	pn->r=NULL;
	int m=0;
	while(b[m]!=a[i]) m++;
	createTree(pn->l,i+1,j,m-j);
	createTree(pn->r,i+(m-j)+1,m+1,len-1-(m-j));
}

void postOrder(treenode &pn)
{
	if(pn) {postOrder(pn->l);postOrder(pn->r);cout<<pn->val<<' ';}

}

void layerOrder(treenode &pn)
{
	queue<Tree*> p;
	p.push(pn);
	while(!p.empty())
	{
		treenode tmp=p.front();p.pop();
		if(tmp->l) p.push(tmp->l);
		if(tmp->r) p.push(tmp->r);
		cout<<tmp->val<<' ';
	}

}
void printPath(list<int> &p)
{
	for(list<int>::iterator it=p.begin();it!=p.end();it++)
		cout<<*it<<' ';
}

void finding(treenode pn,int q,list<int>&p) //不管三七二十一，先存进去a，如果在后来的		
{									//的子树中找不到，说明q不在a所在的树就，弹出a
	if(pn==NULL) return;			//如果找到，输出后，返回
	p.push_back(pn->val);
	if(pn->val==q){printPath(p);return;}
	finding(pn->l,q,p);
	finding(pn->r,q,p);
	p.pop_back();
}
int main()
{ 
	int n;cin>>n;
	// cout<<"输入前序和中序"<<endl;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	int q;cin>>q;
	Tree* root=NULL;
	// cout<<"由前序和中序，生成二叉树"<<endl;
	createTree(root,0,0,n);
	// cout<<root->val;
	// cout<<root->l->val;
	postOrder(root);//后序
	cout<<endl;
	layerOrder(root);//按层次遍历
	cout<<endl;
	list<int> p;
	finding(root,q,p);
	// findPath(root,path,q);

	return 0;
}



// Tree* createTree(int a1,int b1,int a2,int b2)
// {
// 	int cur=find(a1,b1,a2,b2);
// 	int l1=cur-b1,l2=b2-cur;
// 	Tree* p1,*p2;Tree tmp;
// 	if(l1==0&&l2==0)
// 	{
		
// 		p1=new Tree;
// 		p1->val=a[a1];p1->l=NULL;p1->r=NULL;
// 		return p1;
// 	}
// 	if(l1!=0) p1=createTree(a1+1,b1,a1+l1,cur-1);
// 	else p1=NULL;
// 	// {
// 	// 	tmp.val=a[a1];tmp.l=NULL;tmp.r=NULL:
// 	// 	p1=new Tree(tmp);
// 	// 	// return p1;
// 	// }
// 	if(l2!=0) p2=createTree(a1+l1+1,cur+1,a2,b2);
// 	else p2=NULL;
// 	// {
// 	// 	p2=new Tree(a[i]);	
// 	// 	// return p2;
// 	// } 
// 	Tree* p;
// 	p->val=a[a1];p->l=p1;p->r=p2;
// 	cout<<p->val;
// 	return p;

// }
// int n;
