#include<iostream>
using namespace std;
typedef struct tri{
	int i,j,val;
} tri;
void create(int* num,int* rpos,tri* t,int n,int m)  //传入数组(int a[1000])，用 int* num
{
	for(int k=1;k<=m;k++)
	{
		num[t[k].i]++;
	}
	rpos[1]=1;
	for(int k=2;k<=n+1;k++)
	{
		rpos[k]=rpos[k-1]+num[k-1];	
	}
}


void multiply(int* cpot1,int* cpot2,tri* a,tri* b,int m1,int m2,int n)
{
	int k=1;
	while(k<=n)
	{
		if(cpot1[k+1]-cpot1[k])
		{
			int tmp[1000]={0};
			for(int ta=cpot1[k];ta<cpot1[k+1];ta++)
			{
				// int tb=cpot2[a[ta].j];
				// cout<<ta;
				for(int tb=cpot2[a[ta].j];tb<cpot2[a[ta].j+1];tb++)
				{
					tmp[b[tb].j]+=a[ta].val*b[tb].val;
				}
			}
			for(int t=1;t<=n;t++) if(tmp[t]) cout<<k<<' '<<t<<' '<<tmp[t]<<endl;
		}
		k++;
	}
}
int main()
{
	int n,m1,m2,x;
	cin>>n;
	tri a[1000],b[1000],r[1000];
	int num1[1000]={0},num2[1000]={0},cpot1[1000],cpot2[1000],rpos[1000];
	// cin>>num[0]>>num[1];
	cin>>m1;
	for(int k=1;k<=m1;k++) cin>>a[k].i>>a[k].j>>a[k].val;
	cin>>x>>m2;
	for(int k=1;k<=m2;k++) cin>>b[k].i>>b[k].j>>b[k].val;
	create(num1,cpot1,a,n,m1);
	create(num2,cpot2,b,n,m2);
	cout<<endl;
	// for(int k=1;k<=n+1;k++) cout<<cpot1[k]<<' ';
	multiply(cpot1,cpot2,a,b,m1,m2,n);

}



// 1000000000 1
// 123 1000000000 1
// 1000000000 2
// 1 1 1
// 1000000000 456 2


// 2 3
// 1 1 1
// 1 2 -2
// 2 1 1
// 2 3
// 1 1 2
// 1 2 3
// 2 1 1