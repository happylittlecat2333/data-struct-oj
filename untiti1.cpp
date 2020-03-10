#include<iostream>
#include<map>
#include<queue>
#define MAXSIZE 1000
using namespace std;
typedef struct Tri{
	int i,j,val;
	
} tri;
typedef struct Point{
	int i,j;
	bool operator < (const struct Point &b) const{	//重载'<',使得map按照(i,j)升序排列
		if(i==b.i) return j<b.j;
		return i<b.i;
	}
}point;
int main()
{
	int n,x,m1,m2;cin>>n>>m1;
	tri a[MAXSIZE],b[MAXSIZE];
	for(int k=1;k<=m1;k++)cin>>a[k].i>>a[k].j>>a[k].val;
	cin>>x>>m2;
	for(int k=1;k<=m2;k++)cin>>b[k].i>>b[k].j>>b[k].val;
	map<point,int> m;				//map自动会根据key排列（key可能需要重载'<')
	for(int p=1;p<=m1;p++)
	{
		for(int q=1;q<=m2;q++)
		{
			if(a[p].j==b[q].i)
			{
				point t={a[p].i,b[q].j};	//{x,y}相当于结构体初始化
				m[t]+=a[p].val*b[q].val;	//map自动初始化
				if(m[t]==0) m.erase(t);		//m.erase(t) t是key,根据键删除
			}
		}
	}
	for(map<point,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<(*it).first.i<<' '<<(*it).first.j<<' '<<(*it).second<<endl;
	}


}
// in:
// 1000000000 1
// 123 1000000000 1
// 1000000000 2
// 1 1 1
// 1000000000 456 2
// out:
// 123 456 2

// in:
// 2 3
// 1 1 1
// 1 2 -2
// 2 1 1
// 2 3
// 1 1 2
// 1 2 3
// 2 1 1
// out:
// 1 2 3
// 2 1 2
// 2 2 3