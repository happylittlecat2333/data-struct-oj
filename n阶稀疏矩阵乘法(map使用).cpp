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
		if(i==b.i) return j<b.j;  //如果this->i==b.i,比较this->j和b.j(this是指针)
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
				m[t]+=a[p].val*b[q].val;	//map自动初始化,用m[k]=val插入
				if(m[t]==0) m.erase(t);		//m.erase(t) t是key,根据键删除
			}
		}
	}
	cout<<m.size()<<endl;
	for(map<point,int>::iterator it=m.begin();it!=m.end();it++)
	{
		cout<<(*it).first.i<<' '<<(*it).first.j<<' '<<(*it).second<<endl;
	}			//it->first为key,it->second为value


}

// // 第三种 用"array"方式插入
// mapStudent[123] = "student_first";

// // find 返回迭代器指向当前查找元素的位置否则返回map::end()位置
// iter = mapStudent.find("123");
// //用关键字刪除
// int n = mapStudent.erase("123"); //如果刪除了會返回1，否則返回0


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



// #include<cstdio>
// #include<cstdlib>
// #include<iostream>
// #include<algorithm>
// #include<map>
// #define MAXSIZE 1000

// using namespace std;

// typedef struct dS{
//  int i;
//  int j;
//  int e;
// }dS;

// typedef struct point{
//  int x;
//  int y;
//  bool operator < (const point b) const
//  {
//   if(this->x == b.x) {
//    return this->y < b.y;
//   }
//   return this->x < b.x;
//  }
// }point;

// int main()
// {
//  int n1,m1,n2,m2;
//  dS M[MAXSIZE],N[MAXSIZE],Q[MAXSIZE];
//  scanf("%d %d",&n1,&m1);
//  int k,l;
//  for(k=0;k<m1;k++) {
//   scanf("%d %d %d",&M[k].i,&M[k].j,&M[k].e);
//  }
//  scanf("%d %d",&n2,&m2);
//  for(k=0;k<m2;k++) {
//   scanf("%d %d %d",&N[k].i,&N[k].j,&N[k].e);
//  }
//  map<point,int> mtemp;
//  for(k=0;k<m1;k++) {
//   for(l=0;l<m2;l++) {
//    if(M[k].j == N[l].i) {
//     mtemp[{ M[k].i, N[l].j }] += M[k].e*N[l].e;
//     if(mtemp[{ M[k].i, N[l].j }] == 0) {
//      mtemp.erase({ M[k].i, N[l].j });
//     }
//    }
//   }
//  }
//  map<point,int>::iterator iter = mtemp.begin();
//  printf("%d %d\n",n1,mtemp.size());
//  for(iter=mtemp.begin();iter!=mtemp.end();iter++) {
//   printf("%d %d %d\n",iter->first.x,iter->first.y,iter->second);
//  }
//  return 0;
// }